#include <cstdlib>

#include "Particle.h"


Particle::Particle()
{
    // Position in range [-1.0, 1.0]
    m_x = (2.0 * rand() / RAND_MAX) - 1;
    m_y = (2.0 * rand() / RAND_MAX) - 1;
}