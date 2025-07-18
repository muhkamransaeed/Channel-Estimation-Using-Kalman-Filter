// utils.cpp
#include "util.h"
#include <cmath>

double compute_mse(const std::vector<std::complex<double>> &a,
                   const std::vector<std::complex<double>> &b) {
    double mse = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        mse += std::norm(a[i] - b[i]);
    }
    return mse / a.size();}