#include "chip8_screen.h"
#include <assert.h>
#include <string.h>

void chip8ScreenInBounds(int x, int y) {
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}

void chip8ScreenSet(struct chip8Screen* screen, int x, int y){
    chip8ScreenInBounds(x, y);
    screen->pixels[y][x] = true;
}

bool chip8ScreenIsSet(struct chip8Screen* screen, int x, int y){
    chip8ScreenInBounds(x, y);
    return screen->pixels[y][x];
}

bool chip8ScreenDrawSprite(struct chip8Screen* screen, int x, int y, char* sprite, int num) {
    bool pixelCollision = false;

    for (int ly = 0; ly < num; ly++) {
        char c = sprite[ly];
        for (int lx = 0; lx < 8; lx++) {
            if ((c & (0b10000000 >> lx)) == 0) {
                continue;
            }

            screen->pixels[ly + y][lx + x] = true;
        }
    }

    return pixelCollision;
}
