// kalman.h
#pragma once
#include <vector>
#include <complex>

std::vector<std::vector<std::complex<double>>> kalman_mimo_estimate(
    const std::vector<std::vector<std::complex<double>>> &x,  // [Nt][N]
    const std::vector<std::vector<std::complex<double>>> &y,  // [Nr][N]
    int Nt, int Nr, int N,
    double alpha, double Q, double R);