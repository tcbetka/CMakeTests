#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sin;
using std::cos;

#include <iomanip>
using std::hex;

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

    while(true) 
    {
        cout << "Foo!" << endl;

        // Grab the time since the program started
        int elapsed = SDL_GetTicks();

        // Update particle positions
        //swarm.updateSwarm(elapsed);

        // Update particle color
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        cout << "red: " << (int)red << endl;
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        cout << "green: " << (int)green << endl;
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        cout << "blue: " << (int)blue << endl;

        const Particle* const pParticles = swarm.getParticles();
        
        // for (int i = 0; i < Swarm::N_PARTICLES; i++) {
        //     Particle particle = pParticles[i];

        //     int x = (particle.m_x + 1) * HALF_SCREEN_WIDTH;
        //     int y = (particle.m_y * HALF_SCREEN_WIDTH) + HALF_SCREEN_HEIGHT;
        //     screen.setPixel(x, y, red, green, blue);
        // }

        screen.boxBlur();

        // Draw the screen
        screen.updateScreen();

        // Check for messages/events
        if (!screen.processEvents()) {
            break;
        }

        SDL_Delay(1000);
    }
    
    screen.close();

    return 0;
}