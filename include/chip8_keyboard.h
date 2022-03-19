#ifndef CHIP8KEYBOARD_H
#define CHIP8KEYBOARD_H

#include <stdbool.h>
#include "config.h"

struct chip8Keyboard {
    bool keyboard[CHIP8_TOTAL_KEYS];
};

int chip8KeyboardMap(char* map, char key);

void chip8KeyboardDown(struct chip8Keyboard* keyboard, int key);

void chip8KeyboardUp(struct chip8Keyboard*, int key);

bool chip8KeyboardIsDown(struct chip8Keyboard*, int key);

#endif
