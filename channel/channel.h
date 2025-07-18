// channel.h
#pragma once
#include <vector>
#include <complex>

std::vector<std::vector<std::complex<double>>> generate_mimo_gauss_markov_channel(int N, int Nt, int Nr, double alpha, double Q);