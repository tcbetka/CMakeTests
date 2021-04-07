#include "Swarm.h"
#include "Particle.h"

Swarm::Swarm()
{
    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm ()
{
    delete [] m_pParticles;
}

const Particle* const Swarm::getParticles() const
{
    return m_pParticles;
}