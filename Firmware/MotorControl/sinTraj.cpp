#include <cmath>
#include "odrive_main.h"
#include "utils.hpp"


bool SinusoidalTrajectory::planSinusoidal(float Xf, float Xi, float Tf) {

    Xi_ = Xi;
    Xf_ = Xf;
    Tf_ = Tf;
    max_vel_ = 2.0f * (Xf - Xi) / Tf
    omega_ = 2.0f * M_PI / Tf;

    return true;
}

SinusoidalTrajectory::Step_t SinusoidalTrajectory::eval(float t) {
    Step_t trajStep;
    if (t < 0.0f) {  // Initial Condition
        trajStep.Y   = Xi_;
        trajStep.Yd  = 0.0f;
        trajStep.Ydd = 0.0f;
    } else if (t < Tf_) {
        trajStep.Y   = Xi_ + 0.5f * max_vel_ * (t_ - sin(omega_ * t_) / omega_);
        trajStep.Yd  = 0.5f * max_vel_ * (1.0f - cos(omega_ * t_));
        trajStep.Ydd = 0.5f * max_vel_ * omega_ * sin(omega_ * t_);
    } else if (t >= Tf_) {  // Final Condition
        trajStep.Y   = Xf_;
        trajStep.Yd  = 0.0f;
        trajStep.Ydd = 0.0f;
    } else {
        // TODO: report error here
    }

    return trajStep;
}