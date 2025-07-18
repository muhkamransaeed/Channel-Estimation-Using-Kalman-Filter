#include "noise.h"
#include <random>
#include <complex>
#include <vector>

std::vector<std::vector<std::complex<double>>> generate_mimo_noise(int N, int Nr, double R) {
    std::vector<std::vector<std::complex<double>>> v(Nr, std::vector<std::complex<double>>(N));
    std::mt19937 gen(42);
    std::normal_distribution<> dist(0.0, std::sqrt(R / 2));

    for (int r = 0; r < Nr; ++r) {
        for (int i = 0; i < N; ++i) {
            v[r][i] = std::complex<double>(dist(gen), dist(gen));
        }
    }
    return v;
}
