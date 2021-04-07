#include <cstdlib>
#include <cmath>

#include "Particle.h"
#include "Screen.h"

Particle::Particle()
{
    // Choose a random direction from 0 - 2pi rads 
    m_Direction = (2 * M_PI * rand()) / RAND_MAX;

    // Choose a random speed
    m_Speed = (0.0005 * rand()) / RAND_MAX;
}

void Particle::updatePosition(int interval)
{
    double xSpeed = m_Speed * cos(m_Direction);
    double ySpeed = m_Speed * sin(m_Direction);

    m_x += xSpeed * interval;
    m_y += ySpeed * interval;
}