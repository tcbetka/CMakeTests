#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>

#include "Screen.h"

int main() 
{
    Screen screen;
    screen.init();

    cout << "SDL succeeded!" << endl;


    // Now mess with certain pixels
    //buffer[30000] = 0x00FFFFFF; // ARGB
    //for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
    //    buffer[i] = 0x00FFFF00; //  ARGB
    //}
    screen.processEvents();

    screen.close();

    return 0;
}