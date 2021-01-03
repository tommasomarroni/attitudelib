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

    float omega[3] = {0.0, 2.0, 0.0};
    float dcm_dot[9];
    for (int i = 0; i < 9; i++) dcm_dot[i] = dcm6.get_diff_kin(omega)[i];
    for (int i = 0; i < 9; i++) std::cout << dcm_dot[i] << " ";

    float arr[5] = {1,2,3,4,5};
    std::cout << std::endl << std::endl << attitudelib::utils::arr_to_vec<float, 3>(arr) << std::endl;







}
