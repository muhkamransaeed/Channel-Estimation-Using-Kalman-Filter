// least_squares.cpp
#include "least_square.h"

std::vector<std::complex<double>> least_squares_estimate(const std::vector<std::complex<double>> &x,
                                                         const std::vector<std::complex<double>> &y) {
    int N = x.size();
    std::vector<std::complex<double>> h_ls(N);
    for (int i = 0; i < N; ++i) {
        h_ls[i] = y[i] / x[i];
    }
    return h_ls;
}