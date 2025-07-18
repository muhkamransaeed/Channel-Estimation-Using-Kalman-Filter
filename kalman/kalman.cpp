// kalman.cpp
#include "kalman.h"

std::vector<std::complex<double>> kalman_estimate(const std::vector<std::complex<double>> &x,
                                                  const std::vector<std::complex<double>> &y,
                                                  double alpha, double Q, double R) {
    int N = x.size();
    std::vector<std::complex<double>> h_est(N);
    std::complex<double> h_pred = 0.0;
    double P = 1.0;

    for (int k = 0; k < N; ++k) {
        h_pred = alpha * h_pred;
        P = alpha * alpha * P + Q;

        std::complex<double> K = P * std::conj(x[k]) / (std::norm(x[k]) * P + R);
        h_est[k] = h_pred + K * (y[k] - x[k] * h_pred);
        P = (1.0 - std::real(K * x[k])) * P;
    }

    return h_est;
}