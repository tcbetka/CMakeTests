#ifndef PARTICLE_H
#define PARTICLE_H

#include <ctime>

struct Particle
{
    double m_x{0.0};
    double m_y{0.0};
    double m_xSpeed{0.0};
    double m_ySpeed{0.0};

    Particle();
    void updatePosition();
};

#endif // PARTICLE_H