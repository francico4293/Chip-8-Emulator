#ifndef CHIP8STACK_H
#define CHIP8STACK_H

#include "config.h"

struct chip8;

struct chip8Stack {
    short stack[CHIP8_TOTAL_STACK_DEPTH];
};

void chip8StackPush(struct chip8* chip8, short value);

short chip8StackPop(struct chip8* chip8);

#endif
