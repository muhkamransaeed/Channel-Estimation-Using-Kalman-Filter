// utils.h
#pragma once
#include <vector>
#include <complex>

double compute_mse(const std::vector<std::vector<std::complex<double>>> &h_true,
                   const std::vector<std::vector<std::complex<double>>> &h_est);