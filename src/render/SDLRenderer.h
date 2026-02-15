#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../html/DOMNode.h"
using namespace std;

class SDLRenderer
{
public:
    SDLRenderer(SDL_Renderer* renderer);
    ~SDLRenderer();

    void render(DOMNode* root);

private:
    SDL_Renderer* renderer;
    TTF_Font* fontH1;
    TTF_Font* fontP;

    void renderNode(DOMNode* node, int& y);
    void drawText(const std::string& text, int x, int y, TTF_Font* font);
};

#endif
