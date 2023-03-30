#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void doInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}