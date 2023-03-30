#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../include/RenderWindow.hpp"
#include "../include/Defs.hpp"

RenderWindow::RenderWindow(const char *p_title)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow has FAILED. SDL_Error:" << SDL_GetError() << std::endl;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer has FAILED. SDL_Error:" << SDL_GetError() << std::endl;
    }
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);
    if (texture == nullptr)
    {
        std::cout << "IMG_loadTexture has FAILED. IMG_Error:" << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture *p_tex, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(p_tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, p_tex, NULL, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}