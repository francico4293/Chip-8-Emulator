#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "chip8_memory.h"
#include "chip8_registers.h"
#include "chip8_stack.h"

struct chip8 {
    struct chip8Memory memory;
    struct chip8Stack stack;
    struct chip8Registers registers;
};

#endif
