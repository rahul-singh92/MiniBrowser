#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include <SDL2/SDL.h>

class SDLWindow
{
    public:
        SDLWindow(int width, int height);
        ~SDLWindow();

        bool isRunning();
        void pollEvents();

        SDL_Renderer* getRenderer();
    
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool running;
};

#endif