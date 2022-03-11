#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H

#include "config.h"

struct chip8Memory {
    char memory[CHIP8_MEMORY_SIZE];
};

void chip8MemorySet(struct chip8Memory* memory, int index, char val);

char chip8MemoryGet(struct chip8Memory* memory, int index);

#endif
