/**
    Name: attitudelib
    Description: a pure template header-only library for orientation representations

    @author Tommaso Marroni
*/

namespace utils {

template<typename T, int N>
Eigen::Matrix<T, N, 1> arr_to_vec(const T* arr) {
    return Eigen::Matrix<T, N, 1>(arr);
}

template<typename T, int N, int M>
Eigen::Matrix<T, N, M> arr_to_mat(const T* arr) {
    return Eigen::Matrix<T, N, M>(arr).transpose();
}

template<typename T, int N>
void vec_to_arr(T* arr, const Eigen::Matrix<T, N, 1>& vec) {
    for (int i = 0; i < N; i++) arr[i] = vec(i);
}

template<typename T, int N, int M>
void mat_to_arr(T* arr, const Eigen::Matrix<T, N, M>& mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) arr[i * M + j] = mat(i, j);
    }
}

template<typename T>
Eigen::Matrix<T, 3, 3> get_cross_operator(Eigen::Matrix<T, 3, 1>& vec) {
    Eigen::Matrix<T, 3, 3> cross;
    T x1 = vec(0, 0);
    T x2 = vec(1, 0);
    T x3 = vec(2, 0);

    cross << 0, -x3, x2,
             x3, 0, -x1,
             -x2, x1, 0;

    return cross;
}

}
