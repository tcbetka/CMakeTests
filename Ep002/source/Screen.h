#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>

class Screen
{
private:
    SDL_Window* m_window{nullptr};
    SDL_Renderer* m_renderer{nullptr};
    SDL_Texture* m_texture{nullptr};
    Uint32* m_buffer{nullptr};

public:
    static constexpr int SCREEN_WIDTH{800};
    static constexpr int SCREEN_HEIGHT{600};

    Screen();
    bool init();
    bool processEvents();
    void close();
};


#endif // SCREEN_H