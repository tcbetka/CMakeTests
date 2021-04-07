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

void Swarm::updateSwarm(int elapsed)
{
    int interval = elapsed - m_lastTime;

    for (int i = 0; i < N_PARTICLES; i++) {
        m_pParticles[i].updatePosition(interval);
    }

    m_lastTime = elapsed;
}