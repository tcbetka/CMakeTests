#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm
{
private:
    Particle* m_pParticles{nullptr};

public:
    static constexpr int N_PARTICLES = 5000;

    Swarm();
    ~Swarm();
    const Particle* const getParticles() const;

};

#endif // SWARM_H