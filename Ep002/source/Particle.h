#ifndef PARTICLE_H
#define PARTICLE_H

#include <ctime>

struct Particle
{
    double m_x{0.0};
    double m_y{0.0};
    double m_Speed{0.0};
    double m_Direction{0.0};


    Particle();
    void updatePosition(int interval);
};

#endif // PARTICLE_H