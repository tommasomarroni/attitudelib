/**
    Name: attitudelib
    Description: a pure template header-only library for orientation representations

    @author Tommaso Marroni
*/

template<typename _scalar>
class dcm {

private:
    Eigen::Matrix<_scalar, 3, 3> DCM;

public:

    dcm() {
        DCM << Eigen::Matrix<_scalar, 3, 3>::Identity();
    }

    dcm(const _scalar* values) {
        set_params(values);
    }

    dcm(const dcm& other) {
        DCM << other.DCM;
    }

    /*
    explicit dcm(attitudelib::crp& crp) { convert(etc...) }
    explicit dcm(attitudelib::crp& crp) {}
    explicit dcm(attitudelib::crp& crp) {}
    explicit dcm(attitudelib::crp& crp) {}
    explicit dcm(attitudelib::crp& crp) {}
    explicit dcm(attitudelib::crp& crp) {}
    */

    ~dcm() {}

    // checked
    void set_item(int x, int y, const _scalar& value) {
        DCM(x - 1, y - 1) = value;
    }

    // checked
    _scalar get_item(int x, int y) {
        return DCM(x - 1, y - 1);
    }

    // checked
    void set_params(const _scalar* values) {
        DCM << values[0], values[1], values[2],
               values[3], values[4], values[5],
               values[6], values[7], values[8];
    }

    // checked
    void get_params(_scalar* params) {
        DCM.transposeInPlace();
        for (int i = 0; i < 9; i++) params[i] = DCM.data()[i];
        DCM.transposeInPlace();
    }

    //checked
    dcm invert() {
        dcm result;
        result.DCM << (this->DCM).transpose();
        return result;
    }

    // checked
    void invert_in_place() {
        (this->DCM).transposeInPlace();
    }

    // checked
    void get_diff_kin(_scalar* dcm_dot, const _scalar* omega_vec) {
        Eigen::Matrix<_scalar, 3, 1> omega;
        Eigen::Matrix<_scalar, 3, 3> cross_prod, res;

        omega << omega_vec[0], omega_vec[1], omega_vec[2];
        cross_prod << utils::get_cross_operator<_scalar>(omega);

        res << -(cross_prod * DCM);
        res.transposeInPlace();

        for (int i = 0; i < 9; i++) dcm_dot[i] = res.data()[i];
    }

    // checked
    friend std::ostream& operator<<(std::ostream& stream, const dcm& right) {
        stream << right.DCM(0, 0) << ", " << right.DCM(0, 1) << ", " << right.DCM(0, 2) << std::endl;
        stream << right.DCM(1, 0) << ", " << right.DCM(1, 1) << ", " << right.DCM(1, 2) << std::endl;
        stream << right.DCM(2, 0) << ", " << right.DCM(2, 1) << ", " << right.DCM(2, 2) << std::endl;;
        return stream;
    }

    // checked
    dcm operator*(const dcm& right) {
        dcm result;
        result.DCM << (this->DCM) * (right.DCM);
        return result;
    }

    // checked
    void operator=(const dcm& right) {
        this->DCM << right.DCM;
    }

    // checked
    bool operator==(const dcm& right) {
        return ((this->DCM - right.DCM).norm() < EPSILON);
    }

    // checked
    bool operator!=(const dcm& right) {
        return !(operator==(right));
    }



};

typedef dcm<float> dcmf;
typedef dcm<double> dcmd;
