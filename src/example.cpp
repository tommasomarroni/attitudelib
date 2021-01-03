#include <iostream>
#include <Eigen/Dense>
#include <attitudelib/core.h>

int main() {

    float matrix1[9] = {1.0, 2.0, 3.0,
                        4.0, 5.0, 6.0,
                        7.0, 8.0, 9.0};

    double matrix2[9] = {1.0, 0.5, 0.0,
                        0.5, 1.0, 0.5,
                        0.0, 0.5, 1.0};

    attitudelib::dcm<float> dcm1;
    attitudelib::dcm<float> dcm2(matrix1);
    attitudelib::dcmf dcm3(matrix1);   // equivalent to previous
    attitudelib::dcmd dcm4(matrix2);   // equivalent to previous but double

    std::cout << dcm1 << std::endl;
    std::cout << dcm2 << std::endl;
    std::cout << dcm3 << std::endl;
    std::cout << dcm4 << std::endl;

    float matrix3[9];
    dcm2.get_params(matrix3);
    for (int i = 0; i < 9; i++) std::cout << matrix3[i] << " ";

    dcm2.set_item(3, 3, 10);
    std::cout << std::endl << std::endl << dcm2.get_item(3, 3) << std::endl << std::endl;

    dcm1.set_params(matrix3);
    std::cout << dcm1 << std::endl;

    attitudelib::dcm<float> dcm5;
    dcm5 = dcm1;
    std::cout << dcm5 << std::endl;
    std::cout << dcm2*dcm5 << std::endl;

    attitudelib::dcm<float> dcm6(dcm5);
    std::cout << dcm6.invert() << std::endl;

    std::cout << dcm6 << std::endl;
    dcm6.invert_in_place();
    std::cout << dcm6 << std::endl;
    dcm6.invert_in_place();
    std::cout << dcm6 << std::endl;

    float omega[3] = {0.0, 2.0, 0.0};
    float dcm_dot[9] = {0};
    dcm6.get_diff_kin(dcm_dot, omega);
    //float dcm_dot[9]; //or...
    //for (int i = 0; i < 9; i++) dcm_dot[i] = dcm6.get_diff_kin(omega)[i];
    for (int i = 0; i < 9; i++) std::cout << dcm_dot[i] << " ";

    float arr[5] = {1,2,3,4,5};
    Eigen::Vector3f vec1 = attitudelib::utils::arr_to_vec<float, 3>(arr);
    Eigen::Matrix3f mat1 = attitudelib::utils::arr_to_mat<float, 3, 3>(dcm_dot);
    float vec2[3];
    float mat2[9];
    attitudelib::utils::vec_to_arr<float, 3>(vec2, vec1);
    attitudelib::utils::mat_to_arr<float, 3, 3>(mat2, mat1);

    std::cout << std::endl << std::endl << vec1 << std::endl;
    std::cout << std::endl << mat1 << std::endl << std::endl;
    for (int i = 0; i < 3; i++) std::cout << vec2[i] << " ";
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 9; i++) std::cout << mat2[i] << " ";

    dcm6.set_item(3, 3, 9.0001);
    std::cout << std::endl << std::endl << (dcm6 == dcm6) << !(dcm6 == dcm6) << std::endl;
    std::cout << (dcm6 == dcm1) << !(dcm6 == dcm1) << std::endl;
    std::cout << (dcm6 == dcm2) << !(dcm6 == dcm2) << std::endl;







}
