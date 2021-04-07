#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>

int main() 
{
    constexpr int SCREEN_WIDTH = 1280;
    constexpr int SCREEN_HEIGHT = 800;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init failed" << std::endl;
        return -1;
    }

    cout << "SDL succeeded!" << endl;

    // SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
    SDL_Window* window = SDL_CreateWindow("Particle Explosion Simulator", 
            400, 400, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        cout << "Error: " << SDL_GetError();
        return 1;
    }

    bool quit = false;
    SDL_Event event;
    while(!quit) 
    {
        // Update particles
        // Draw particles
        
        // Check for messages/events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

        }
    }

    // Destroy window and then exit
    SDL_DestroyWindow(window);
    SDL_Quit(); 

    return 0;
}