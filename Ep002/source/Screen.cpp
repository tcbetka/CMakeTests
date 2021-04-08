#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::hex;

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

    m_pixelBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]{0};
    m_blurBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]{0};

    // Init both buffers with all 0's for the colors
    memset(m_pixelBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_blurBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

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
    cout << "r: " << (int)red << endl;
    cout << "g: " << (int)green << endl;
    cout << "b: " << (int)blue << endl;

    Uint32 color = (red << 16) | (green << 8) | blue;

    // Move down 'y' number of rows, and then move over by 'x'
    m_pixelBuffer[(y * SCREEN_WIDTH) + x] = color;
    cout << hex << color << endl;
}

void Screen::updateScreen()
{
    // Draw the screen
    SDL_UpdateTexture(m_texture, nullptr, m_pixelBuffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Screen::boxBlur()
{
    // Copy all pixels into the blur buffer
    //memcpy(m_blurBuffer, m_pixelBuffer, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    Uint32* temp = m_pixelBuffer;
    m_pixelBuffer = m_blurBuffer;
    m_blurBuffer = temp;

    // Blur the pixels
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {

            // Grab the pixel values for the surrounding pixels, and average them
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int currentX = x + col;
                    int currentY = y + row;

                    if (currentX >= 0 &&  currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
                        Uint32 color = m_blurBuffer[(currentY * SCREEN_WIDTH) + currentX];
                        Uint8 red = color & 0xffff0000;
                        Uint8 green = color & 0xff00ff00;
                        Uint8 blue = color & 0xff0000ff;

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }

            // Take the average of the pixel in question, and the 8 surrounding pixels
            Uint8 red = redTotal / 9;
            Uint8 green = greenTotal / 9;
            Uint8 blue = blueTotal / 9;

            setPixel(x, y, red, green, blue);
        }
    }
}

void Screen::close()
{
    // Destroy window and stuff, then exit
    delete [] m_pixelBuffer;
    delete [] m_blurBuffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit(); 
}