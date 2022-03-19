#ifndef CHIP8SCREEN_H
#define CHIP8SCREEN_H

#include <stdbool.h>
#include "config.h"

struct chip8Screen {
    bool pixels[CHIP8_HEIGHT][CHIP8_WIDTH];
};

void chip8ScreenSet(struct chip8Screen* screen, int x, int y);

bool chip8ScreenIsSet(struct chip8Screen* screen, int x, int y);

bool chip8ScreenDrawSprite(struct chip8Screen* screen, int x, int y, char* sprite, int num);

#endif
