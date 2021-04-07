#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>

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

        // Draw particles
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 255, 255, 0);
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