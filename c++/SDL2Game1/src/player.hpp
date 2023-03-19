#include <iostream>
#include <SDL2/SDL.h>

void PLAYER(int posx, int posy, int width, int heigth, SDL_Window* window) {
    // renderer
    SDL_Renderer* windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_RenderClear(windowRenderer);

    SDL_Rect rect;
    rect.x = posx;
    rect.y = posy;
    rect.w = width;
    rect.h = heigth;

    SDL_SetRenderDrawColor(windowRenderer, 255, 255, 230, 255);
    SDL_RenderFillRect(windowRenderer, &rect);
    
    SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0, 255);

    SDL_RenderPresent(windowRenderer);
}