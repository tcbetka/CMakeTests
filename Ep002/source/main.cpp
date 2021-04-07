#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sin;

#include "Screen.h"

int main() 
{
    Screen screen;
    if (!screen.init()) {
        cout << "SDL Init failure. Good-bye." << endl;
        return 1;
    }
    cout << "SDL Init succeeded!" << endl;

    while(true) {
        // Update particles
        int elapsed = SDL_GetTicks();
        unsigned char red = static_cast<unsigned char>((1 + sin(elapsed * 0.0007)) * 128);
        unsigned char green = static_cast<unsigned char>((1 + sin(elapsed * 0.0008)) * 128);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsed * 0.0009)) * 128);

        // Draw particles
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }

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