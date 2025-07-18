#include <vector>
#include <complex>

double compute_mse(const std::vector<std::vector<std::complex<double>>> &h_true,
                   const std::vector<std::vector<std::complex<double>>> &h_est) {
    int num_links = h_true.size();
    int N = h_true[0].size();

    double mse = 0.0;

    for (int i = 0; i < num_links; ++i) {
        for (int k = 0; k < N; ++k) {
            std::complex<double> diff = h_true[i][k] - h_est[i][k];
            mse += std::norm(diff);  // square of magnitude
        }
    }

    mse /= (num_links * N);  // average over all antennas and time steps
    return mse;
}