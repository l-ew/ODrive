#ifndef _SIN_TRAJ_H
#define _SIN_TRAJ_H

class SinusoidalTrajectory {
public:
    struct Config_t {
        float Tf = 3.0f;   // [s]
    };
    
    struct Step_t {
        float Y;
        float Yd;
        float Ydd;
    };

    bool planSinusoidal(float Xf, float Xi, float Tf);
    Step_t eval(float t);

    Axis* axis_ = nullptr;  // set by Axis constructor
    Config_t config_;

    float Xi_;
    float Xf_;
    float Tf_;
    float t_;
    float max_vel_;
    float omega_;
};

#endif