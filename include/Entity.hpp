#ifndef ENTITY_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(double p_x, double p_y, SDL_Texture *p_tex);
    int getX() { return x; }
    int getY() { return y; }
    SDL_Texture *getTexture() { return tex; }

private:
    double x, y;
    SDL_Rect currentFrame;
    SDL_Texture *tex;
};

#endif