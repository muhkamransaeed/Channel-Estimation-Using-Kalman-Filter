#include "least_square.h"
#include <vector>
#include <complex>

// MIMO LS estimator for Nt x Nr system
std::vector<std::vector<std::complex<double>>> least_squares_mimo_estimate(
    const std::vector<std::vector<std::complex<double>>> &x,   // [Nt][N]
    const std::vector<std::vector<std::complex<double>>> &y,   // [Nr][N]
    int Nt, int Nr, int N)
{
    std::vector<std::vector<std::complex<double>>> h_ls(Nt * Nr, std::vector<std::complex<double>>(N));

    for (int r = 0; r < Nr; ++r) {
        for (int t = 0; t < Nt; ++t) {
            for (int k = 0; k < N; ++k) {
                h_ls[r * Nt + t][k] = y[r][k] / x[t][k];
            }
        }
    }

    return h_ls;
}