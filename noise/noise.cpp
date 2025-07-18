// noise.cpp
#include "noise.h"
#include <random>

std::vector<std::complex<double>> generate_noise(int N, double R) {
    std::vector<std::complex<double>> v(N);
    std::mt19937 gen(42);
    std::normal_distribution<> dist(0.0, std::sqrt(R / 2));

    for (int i = 0; i < N; ++i) {
        v[i] = std::complex<double>(dist(gen), dist(gen));
    }
    return v;
}