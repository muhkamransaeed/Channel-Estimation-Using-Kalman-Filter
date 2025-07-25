# Channel-Estimation-Using-Kalman-Filter

This project simulates a MIMO wireless communication system to compare two channel estimation techniques: Kalman filtering and Least Squares (LS) under time-varying fading conditions modeled by a Gauss-Markov process.

## 1. Channel Modeling
The wireless channel is modeled as time-varying, capturing the dynamic nature of real-world communication environments. Specifically, it follows a first-order Gauss-Markov process, which introduces temporal correlation between consecutive channel states. This means that the current channel state is influenced by its previous state, allowing for a realistic simulation of slow or fast fading scenarios depending on the chosen correlation factor. Such modeling is essential for analyzing systems where past channel conditions impact future transmissions, especially in mobile or rapidly changing environments.
### Parameters:

## α (Alpha) — Time Correlation Coefficient:
This parameter controls how much the current channel state depends on its previous state. A value close to 1 indicates strong temporal correlation, meaning the channel changes slowly over time (i.e., slow fading). Conversely, a lower α implies the channel changes more rapidly (i.e., fast fading).

## Q — Process Noise:
The process noise determines the random variation or unpredictability in the channel from one time step to the next. It models how much the channel can change independently of its previous state. A larger Q means more channel variation (less predictable), while a smaller Q keeps the channel more stable between updates.

## 2. Pilot Signal Generation
The system generates pilot signals for each transmit antenna, which act as known reference signals embedded within the transmission. These pilots are essential for estimating the MIMO (Multiple-Input Multiple-Output) channel, as they allow the receiver to assess how the wireless channel distorts the transmitted signals. By analyzing the received pilot signals, the system can accurately estimate the channel state information, which is critical for tasks such as equalization, beamforming, and coherent detection in modern wireless communication systems.
## 3. Noise Addition
AWGN (Additive White Gaussian Noise) is added to the received signal using a random generator.

## 4. Channel Estimation
### Kalman Filter Estimation:

The Kalman filter is used to recursively predict and update the channel state over time. It leverages the Kalman equations to combine the prior channel estimate, process noise variance, and new observations to produce an improved estimate. The prediction step uses the known dynamics (e.g., Gauss-Markov process) to estimate the current channel based on the previous state, while the update step incorporates actual observations (such as received pilot signals) to correct this prediction. This approach enables accurate tracking of time-varying channels, even in the presence of noise and uncertainty.

### Least Squares Estimation:

The Least Squares (LS) method is a simple and intuitive approach for estimating the channel in communication systems. This method assumes that the system is linear and the transmitted symbols are known, making it computationally efficient. However, LS does not account for noise or prior channel statistics, which can reduce its accuracy in noisy environments.
## 5. Performance Metric
The Mean Squared Error (MSE) is computed between the true channel and the estimated channel for both the Kalman filter and the LS methods. The results show that the Kalman filter consistently achieves significantly lower MSE, demonstrating its superior accuracy in tracking the time-varying channel compared to the LS approach.
