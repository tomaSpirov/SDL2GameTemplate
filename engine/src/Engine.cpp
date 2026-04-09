#include "Engine.h"

#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <stdexcept>
#include <iostream>

namespace Engine
{
    void Init()
    {
        // -----------------------------
        // SDL core systems
        // -----------------------------
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
        {
            throw std::runtime_error(std::string("SDL_Init failed: ") + SDL_GetError());
        }

        // -----------------------------
        // SDL_image
        // -----------------------------
        int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
        {
            throw std::runtime_error(std::string("IMG_Init failed: ") + IMG_GetError());
        }

        // -----------------------------
        // SDL_mixer
        // -----------------------------
        int mixFlags = MIX_INIT_OGG | MIX_INIT_MP3;
        if ((Mix_Init(mixFlags) & mixFlags) != mixFlags)
        {
            throw std::runtime_error(std::string("Mix_Init failed: ") + Mix_GetError());
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            throw std::runtime_error(std::string("Mix_OpenAudio failed: ") + Mix_GetError());
        }

        // -----------------------------
        // SDL_ttf
        // -----------------------------
        if (TTF_Init() == -1)
        {
            throw std::runtime_error(std::string("TTF_Init failed: ") + TTF_GetError());
        }

        std::cout << "[Engine] SDL2 systems initialized successfully.\n";
    }

    void Shutdown()
    {
        // Shutdown order is important

        // SDL_ttf
        TTF_Quit();

        // SDL_mixer
        Mix_CloseAudio();
        Mix_Quit();

        // SDL_image
        IMG_Quit();

        // SDL core
        SDL_Quit();

        std::cout << "[Engine] SDL2 systems shut down.\n";
    }

    SDL_Window* CreateWindow(const std::string& title, int width, int height)
    {
        SDL_Window* window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
        );

        if (!window)
        {
            throw std::runtime_error(std::string("SDL_CreateWindow failed: ") + SDL_GetError());
        }

        return window;
    }

    void DestroyWindow(SDL_Window* window)
    {
        if (window)
            SDL_DestroyWindow(window);
    }
}

