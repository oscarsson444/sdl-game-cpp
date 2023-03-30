#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../include/RenderWindow.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init has FAILED. SDL_Error:" << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init has FAILED. IMG_Error:" << SDL_GetError() << std::endl;
    }

    RenderWindow window("Game", 1280, 720);

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();
        window.render(grassTexture);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
