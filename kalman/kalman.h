// kalman.h
#pragma once
#include <vector>
#include <complex>

std::vector<std::complex<double>> kalman_estimate(const std::vector<std::complex<double>> &x,
                                                  const std::vector<std::complex<double>> &y,
                                                  double alpha, double Q, double R);