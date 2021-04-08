#include <cstdlib>

#include "Particle.h"
#include "Screen.h"

Particle::Particle()
{
    // Choose a random direction from 0 - 2pi rads 
    m_Direction = (TWO_PI * rand()) / RAND_MAX;

    // Choose a random speed
    m_Speed = (0.1 * rand()) / RAND_MAX;

    // Square the speed to give the particles greater separation
    m_Speed *= m_Speed;
}

void Particle::updatePosition(int interval)
{
    m_Direction += interval * 0.0001;

    double xSpeed = m_Speed * cos(m_Direction);
    double ySpeed = m_Speed * sin(m_Direction);

    m_x += xSpeed * interval;
    m_y += ySpeed * interval;
}