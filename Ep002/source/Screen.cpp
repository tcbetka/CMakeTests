#include <iostream>
using std::cout;
using std::endl;

#include "Screen.h"

Screen::Screen()
{
}

bool Screen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL Init failed" << endl;
        return false;
    }

    m_window = SDL_CreateWindow("Particle Explosion Simulator",
                                400, 400, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == nullptr)
    {
        cout << "Error: " << SDL_GetError();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr)
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        cout << "Could not create SDL renderer" << endl;
        return false;
    }

    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (m_texture == nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        cout << "Could not create SDL texture" << endl;
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]{0};

    // Set all bytes in the pixel buffer to be white (0xffffffff)
    memset(m_buffer, 0xff000000, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        m_buffer[i] = 0x00000000;
    }

    return true;
}

bool Screen::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent (&event)) {
        // User clicked the 'X' to close the screen
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    // Don't plot pixels that are off the screen
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }

    Uint32 color = (0xff << 24) + (red << 16) + (green << 8) + blue;

    // Move down 'y' number of rows, and then move over by 'x'
    m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::updateScreen()
{
    // Draw the screen
    SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Screen::close()
{
    // Destroy window and stuff, then exit
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit(); 
}