#include "Engine.h"
#include <SDL.h>

int main(int argc, char** argv)
{
    Engine::Init();

    SDL_Window* window = Engine::CreateWindow("My Game", 800, 600);

    bool running = true;
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
        }

        SDL_Delay(16);
    }

    Engine::DestroyWindow(window);
    Engine::Shutdown();
    return 0;
}

