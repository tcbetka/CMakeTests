#include <cstdlib>

#include "Particle.h"
#include "Screen.h"

Particle::Particle()
{
    // Position in range [-1.0, 1.0]
    m_x = (2.0 * rand() / RAND_MAX) - 1;
    m_y = (2.0 * rand() / RAND_MAX) - 1;

    // Give each particle its own inital x- and y- speeds
    m_xSpeed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
    m_ySpeed = 0.005 * ((2.0 * rand() / RAND_MAX) - 1);
}

void Particle::updatePosition()
{
    m_x += m_xSpeed;
    m_y += m_ySpeed;

    if (m_x <= -1.0 || m_x >= 1.0) {
        m_xSpeed = -m_xSpeed;
    }

    if (m_y <= -1.0 || m_y >= 1.0) {
        m_ySpeed = -m_ySpeed;
    }
}