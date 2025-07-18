#include "kalman.h"

std::vector<std::vector<std::complex<double>>> kalman_mimo_estimate(
    const std::vector<std::vector<std::complex<double>>> &x,  // [Nt][N]
    const std::vector<std::vector<std::complex<double>>> &y,  // [Nr][N]
    int Nt, int Nr, int N,
    double alpha, double Q, double R) 
{
    std::vector<std::vector<std::complex<double>>> h_est(Nt * Nr, std::vector<std::complex<double>>(N));

    for (int r = 0; r < Nr; ++r) {
        for (int t = 0; t < Nt; ++t) {
            std::complex<double> h_pred = 0.0;
            double P = 1.0;

            for (int k = 0; k < N; ++k) {
                h_pred = alpha * h_pred;
                P = alpha * alpha * P + Q;

                std::complex<double> x_tk = x[t][k];
                std::complex<double> y_rk = y[r][k];

                std::complex<double> K = P * std::conj(x_tk) / (std::norm(x_tk) * P + R);
                std::complex<double> innovation = y_rk - h_pred * x_tk;
                h_est[r * Nt + t][k] = h_pred + K * innovation;

                P = (1.0 - std::real(K * x_tk)) * P;
            }
        }
    }

    return h_est;
}
