#include <iostream>
#include <vector>
#include <complex>
#include "./pilot/pilot.h"
#include "./channel/channel.h"
#include "./noise/noise.h"
#include "./kalman/kalman.h"
#include "./least_square/least_square.h"
#include "./util/util.h"

int main() {
    int N = 100;
    int Nt=32;
    int Nr=4;
    double alpha = 0.9;
    double Q = 0.01;
    double R = 0.1;

    auto x = generate_mimo_bpsk_pilots(N, Nt);
    auto h_true = generate_mimo_gauss_markov_channel(N, Nt, Nr, alpha, Q);
    auto noise = generate_mimo_noise(N, Nt, R);

    std::vector<std::vector<std::complex<double>>> y(Nr, std::vector<std::complex<double>>(N));

    for (int r = 0; r < Nr; ++r) {
        for (int i = 0; i < N; ++i) {
            std::complex<double> sum = 0.0;
            for (int t = 0; t < Nt; ++t) {
                sum += h_true[r * Nt + t][i] * x[t][i];
            }
            y[r][i] = sum + noise[r][i];
        }
    }

    auto h_kalman = kalman_mimo_estimate(x, y, Nt, Nr, N, alpha, Q, R);
    auto h_ls = least_squares_mimo_estimate(x, y, Nt, Nr, N);

    double mse_k = compute_mse(h_true, h_kalman);
    double mse_ls = compute_mse(h_true, h_ls);

    std::cout << "MSE Kalman: " << mse_k << ", MSE LS: " << mse_ls << std::endl;

    return 0;
}