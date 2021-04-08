#ifndef PARTICLE_H
#define PARTICLE_H

#include <ctime>
#include <cmath>

struct Particle
{
    double m_x{0.0};
    double m_y{0.0};
    double m_Speed{0.0};
    double m_Direction{0.0};
    static constexpr double TWO_PI = 2.0 * M_PI;
    
    Particle();
    void updatePosition(int interval);
};

#endif // PARTICLE_H