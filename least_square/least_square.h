// least_squares.h
#pragma once
#include <vector>
#include <complex>

std::vector<std::complex<double>> least_squares_estimate(const std::vector<std::complex<double>> &x,
                                                         const std::vector<std::complex<double>> &y);