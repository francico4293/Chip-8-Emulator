#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    // create a window titled "Chip 8 Window" with a width of 640px and a height of 320px
    SDL_Window* window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER, 
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, 
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto out;
            }
        }

        SDL_Rect rectangle;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        
        rectangle.x = 0;
        rectangle.y = 0;
        rectangle.w = 40;
        rectangle.h = 40;

        SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
    }

out:
    SDL_DestroyWindow(window);
    return 0;
}