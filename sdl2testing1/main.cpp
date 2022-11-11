#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

SDL_Window* window =  SDL_CreateWindow("Window 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
SDL_Renderer* windowrenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

void React1() {
    SDL_RenderClear(windowrenderer);

    SDL_Rect rect;
    rect.x = 130;
    rect.y = 100;
    rect.w = 30;
    rect.h = 30;

    SDL_SetRenderDrawColor(windowrenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(windowrenderer, &rect);

    SDL_SetRenderDrawColor(windowrenderer, 0, 0, 0, 255);

    SDL_RenderPresent(windowrenderer);
}

int main() {
    if (!window) {
        cout << "An error ocurred" << endl;
        return -1;
    }

    SDL_Event window_event;

    bool keep_window_open = true;
    while (keep_window_open) {
        while (SDL_PollEvent(&window_event) > 0) {
            switch (window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }
        React1();
    }
}