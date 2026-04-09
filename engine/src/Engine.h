#pragma once
#include <string>
#include <SDL.h>

namespace Engine
{
    // Initializes all SDL2 subsystems + SDL_image + SDL_mixer + SDL_ttf
    void Init();

    // Shuts down all SDL systems in correct order
    void Shutdown();

    // Optional helper: create a window
    SDL_Window* CreateWindow(const std::string& title, int width, int height);

    // Optional helper: destroy a window
    void DestroyWindow(SDL_Window* window);
}

