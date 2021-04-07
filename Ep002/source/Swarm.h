#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm
{
private:
    Particle* m_pParticles{nullptr};

public:
    static constexpr int N_PARTICLES = 1500;

    Swarm();
    ~Swarm();
    const Particle* const getParticles() const;
    void updateSwarm();

};

#endif // SWARM_H