
// pilot.cpp
#include "pilot.h"
#include <random>
#include <complex>

std::vector<std::complex<double>> generate_bpsk_pilot(int N) {
    std::vector<std::complex<double>> x(N);
    std::mt19937 gen(42);
    std::uniform_int_distribution<> dist(0, 1);
    for (int i = 0; i < N; ++i) {
        int bit = dist(gen);
        x[i] = std::complex<double>(2 * bit - 1, 0.0);  // BPSK: {-1, +1}
    }
    return x;
}