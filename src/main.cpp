#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../include/RenderWindow.hpp"
#include "../include/Entity.hpp"
#include "../include/Input.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL_Init has FAILED. SDL_Error:" << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        std::cout << "IMG_Init has FAILED. IMG_Error:" << SDL_GetError() << std::endl;
    }

    RenderWindow window("Majesticus");
    Entity player(100, 100, window.loadTexture("res/gfx/skepp.png"));

    while (1)
    {
        window.clear();
        doInput();
        window.render(player.getTexture(), player.getX(), player.getY());
        window.display();
        SDL_Delay(1000 / 60);
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
