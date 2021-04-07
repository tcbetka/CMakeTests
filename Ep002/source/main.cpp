#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sin;

#include <cstdlib>
using std::srand;

#include <ctime>
using std::time;

#include "Screen.h"
#include "Swarm.h"

static constexpr double HALF_SCREEN_WIDTH = Screen::SCREEN_WIDTH / 2;
static constexpr double HALF_SCREEN_HEIGHT = Screen::SCREEN_HEIGHT / 2;

int main() 
{
    // Seed our RNG
    srand(time(nullptr));

    Screen screen;
    if (!screen.init()) {
        cout << "SDL Init failure. Good-bye." << endl;
        return 1;
    }
    cout << "SDL Init succeeded!" << endl;

    Swarm swarm;

    while(true) {

        // Clear the screen and then update particle positions
        screen.clearScreen();
        swarm.updateSwarm();

        // Update particle color
        int elapsed = SDL_GetTicks();

        unsigned char red = static_cast<unsigned char>((1 + sin(elapsed * 0.0007)) * 128);
        unsigned char green = static_cast<unsigned char>((1 + sin(elapsed * 0.0008)) * 128);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsed * 0.0009)) * 128);

        const Particle* const pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::N_PARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * HALF_SCREEN_WIDTH;
            int y = (particle.m_y * HALF_SCREEN_WIDTH) + HALF_SCREEN_HEIGHT;
            screen.setPixel(x, y, red, green, blue);
        }

        /*
        // Draw particles
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        */

        // Draw the screen
        screen.updateScreen();

        // Check for messages/events
        if (!screen.processEvents()) {
            break;
        }
    }
    
    screen.close();

    return 0;
}