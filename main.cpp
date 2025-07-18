#include <iostream>
#include <vector>
#include <complex>
#include "../pilot/pilot.h"
#include "../channel/channel.h"
#include "../noise/noise.h"
#include "../kalman/kalman.h"
#include "../least_square/least_square.h"
#include "../util/util.h"

int main() {
    int N = 100;
    double alpha = 0.9;
    double Q = 0.01;
    double R = 0.1;

    auto x = generate_bpsk_pilot(N);
    auto h_true = generate_gauss_markov_channel(N, alpha, Q);
    auto noise = generate_noise(N, R);

    std::vector<std::complex<double>> y(N);
    for (int i = 0; i < N; ++i) {
        y[i] = x[i] * h_true[i] + noise[i];
    }

    auto h_kalman = kalman_estimate(x, y, alpha, Q, R);
    auto h_ls = least_squares_estimate(x, y);

    double mse_k = compute_mse(h_true, h_kalman);
    double mse_ls = compute_mse(h_true, h_ls);

    std::cout << "MSE Kalman: " << mse_k << ", MSE LS: " << mse_ls << std::endl;

    return 0;
}