#include "SDLWindow.h"
#include <iostream>
using namespace std;

SDLWindow::SDLWindow(int width, int height)
{
    running = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout<<"SDL Init Error: "<<SDL_GetError()<<endl;
        running = false;
        return;
    }

    window = SDL_CreateWindow(
        "MiniBrowser",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if(!window)
    {
        cout<<"WIndow Error: "<<SDL_GetError()<<endl;
        running = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer)
    {
        cout<<"Renderer Error: "<<SDL_GetError()<<endl;
        running = false;
        return;
    }
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool SDLWindow::isRunning()
{
    return running;
}

void SDLWindow::pollEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

SDL_Renderer* SDLWindow::getRenderer()
{
    return renderer;
}