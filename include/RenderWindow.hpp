#ifndef RENDERWINDOW_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char *p_title);
    SDL_Texture *loadTexture(const char *p_filePath);
    void cleanUp();
    void clear();
    void render(SDL_Texture *p_tex, int x, int y);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif