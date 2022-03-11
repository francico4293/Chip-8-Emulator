#ifndef CHIP8REGISTERS_H
#define CHIP8REGISTERS_H

#include "config.h"

struct chip8Registers {
    char V[CHIP8_TOTAL_DATA_REGISTERS];  // 16 general purpose 8-bit registers
    short I;  // 16-bit register generally for storing memory addresses
    char soundTimer;  // 8-bit register for sound timer
    char delayTimer;  // 8-bit register for delay timer
    short PC;  // 16-bit program counter
    char SP;  // b-bit stack pointer
};

#endif
