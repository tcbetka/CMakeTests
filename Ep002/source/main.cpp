#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>

int main() 
{
    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 600;

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        cout << "Could not create SDL renderer" << endl;
        return 2;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (texture == nullptr) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        cout << "Could not create SDL texture" << endl; 
        return 3;
    }

    // SDL-defined types
    Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]{0};
    memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while(!quit) 
    {
        // Update particles

        // Draw particles

        // Check for messages/events
        while (SDL_PollEvent(&event)) {
            // User clicked the 'X' to close the screen
            if (event.type == SDL_QUIT) {
                quit = true;
            }

        }
    }

    // Destroy window and stuff, then exit
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit(); 

    return 0;
}