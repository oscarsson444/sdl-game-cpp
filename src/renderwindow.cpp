#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow has FAILED. SDL_Error:" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture *p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 32;
    dst.h = 32;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}