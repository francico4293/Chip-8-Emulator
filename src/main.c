#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8_stack.h"
#include "chip8_keyboard.h"

char keyboardMap[CHIP8_TOTAL_KEYS] = {
    SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5,
    SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_a, SDLK_b,
    SDLK_c, SDLK_d, SDLK_e, SDLK_f
};

int main(int argc, char* argv[]) {
    struct chip8 chip8;

    chip8Init(&chip8);

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
            } else if (event.type == SDL_KEYDOWN) {
                char key = event.key.keysym.sym;
                int vKey = chip8KeyboardMap(keyboardMap, key);
                if (vKey != -1) {
                    chip8KeyboardDown(&chip8.keyboard, vKey);
                }
            } else if (event.type == SDL_KEYUP) {
                char key = event.key.keysym.sym;
                int vKey = chip8KeyboardMap(keyboardMap, key);
                if (vKey != -1) {
                    chip8KeyboardUp(&chip8.keyboard, vKey);
                }
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