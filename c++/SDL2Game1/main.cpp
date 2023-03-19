#include <SDL2/SDL.h>
#include <iostream>
#include "src/player.hpp"

int main(int argc, char* argv[]) {

    SDL_Window* window = SDL_CreateWindow("Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Init(SDL_INIT_EVERYTHING);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }


    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    bool keep_window_opened = true;

    while (keep_window_opened) {
        while (SDL_PollEvent(&event) > 0) {
            switch (event.type) {
            case SDL_QUIT:
                keep_window_opened = false;
                break;
            }
        }
        PLAYER(120, 150, 50, 50, window);
    }
    return 0;
}