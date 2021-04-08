#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm
{
private:
    Particle* m_pParticles{nullptr};
    int m_lastTime{0};

public:
    static constexpr int N_PARTICLES = 10;

    Swarm();
    ~Swarm();
    const Particle* const getParticles() const;
    void updateSwarm(int elapsed);

};

#endif // SWARM_H