#pragma once
#ifndef INIT_H
#define INIT_H


#include <SDL_image.h>
#include <SDL.h>
class Init {
public:
    void startSDL();
   
    int SCREEN_HEIGHT = 600;
    int SCREEN_WIDTH = 800;
    SDL_Renderer* gRenderer;
    SDL_Window* window;

};

#endif
