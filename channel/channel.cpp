#include "channel.h"
#include <random>

std::vector<std::vector<std::complex<double>>> generate_mimo_gauss_markov_channel(int N, int Nt, int Nr, double alpha, double Q) {
    std::vector<std::vector<std::complex<double>>> H(Nt * Nr, std::vector<std::complex<double>>(N));
    std::mt19937 gen(42);
    std::normal_distribution<> dist(0.0, std::sqrt(Q / 2));

    for (int r = 0; r < Nr; ++r) {
        for (int t = 0; t < Nt; ++t) {
            int idx = r * Nt + t;  // Flattened index
            H[idx][0] = std::complex<double>(dist(gen), dist(gen));
            for (int n = 1; n < N; ++n) {
                std::complex<double> w(dist(gen), dist(gen));
                H[idx][n] = alpha * H[idx][n - 1] + w;
            }
        }
    }
    return H;
}
