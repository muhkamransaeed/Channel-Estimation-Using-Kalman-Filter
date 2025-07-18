#include "pilot.h"
#include <random>
#include <complex>

// MIMO: Nt = number of transmit antennas
std::vector<std::vector<std::complex<double>>> generate_mimo_bpsk_pilots(int N, int Nt) {
    std::vector<std::vector<std::complex<double>>> X(Nt, std::vector<std::complex<double>>(N));
    std::mt19937 gen(42);
    std::uniform_int_distribution<> dist(0, 1);

    for (int t = 0; t < Nt; ++t) {
        for (int i = 0; i < N; ++i) {
            int bit = dist(gen);
            X[t][i] = std::complex<double>(2 * bit - 1, 0.0);  // BPSK: {-1, +1}
        }
    }
    return X;
}
