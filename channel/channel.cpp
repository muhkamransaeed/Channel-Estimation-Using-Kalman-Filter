// channel.cpp
#include "channel.h"
#include <random>

std::vector<std::complex<double>> generate_gauss_markov_channel(int N, double alpha, double Q) {
    std::vector<std::complex<double>> h(N);
    std::mt19937 gen(42);
    std::normal_distribution<> dist(0.0, std::sqrt(Q / 2));

    std::complex<double> w0(dist(gen), dist(gen));
    h[0] = w0;

    for (int i = 1; i < N; ++i) {
        std::complex<double> w(dist(gen), dist(gen));
        h[i] = alpha * h[i - 1] + w;
    }
    return h;
}