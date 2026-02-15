#include "SDLRenderer.h"
#include <iostream>
using namespace std;

SDLRenderer::SDLRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;

    if (TTF_Init() < 0)
    {
        cout << "TTF Init Error: " << TTF_GetError() << endl;
    }

    fontH1 = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial.ttf", 42);
    fontP  = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial.ttf", 24);

    if (!fontH1 || !fontP)
    {
        cout << "Font Load Error: " << TTF_GetError() << endl;
    }
}

SDLRenderer::~SDLRenderer()
{
    if (fontH1) TTF_CloseFont(fontH1);
    if (fontP) TTF_CloseFont(fontP);
    TTF_Quit();
}

void SDLRenderer::drawText(const string& text, int x, int y, TTF_Font* font)
{
    SDL_Color black = {0, 0, 0, 255};

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), black);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

void SDLRenderer::renderNode(DOMNode* node, int& y)
{
    if (node->tagName == "h1")
    {
        drawText(node->textContent, 40, y, fontH1);
        y += 60;
    }
    else if (node->tagName == "p")
    {
        drawText(node->textContent, 40, y, fontP);
        y += 40;
    }

    for (auto child : node->children)
    {
        renderNode(child, y);
    }
}

void SDLRenderer::render(DOMNode* root)
{
    // white background
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int y = 30;
    renderNode(root, y);

    SDL_RenderPresent(renderer);
}
