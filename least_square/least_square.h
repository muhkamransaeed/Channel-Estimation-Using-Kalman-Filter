// least_squares.h
#pragma once
#include <vector>
#include <complex>

std::vector<std::vector<std::complex<double>>> least_squares_mimo_estimate(
    const std::vector<std::vector<std::complex<double>>> &x,   // [Nt][N]
    const std::vector<std::vector<std::complex<double>>> &y,   // [Nr][N]
    int Nt, int Nr, int N);