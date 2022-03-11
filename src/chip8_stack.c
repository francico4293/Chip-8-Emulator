#include "chip8_stack.h"
#include "chip8.h"
#include <assert.h>

static void chip8StackInBounds(struct chip8* chip8) {
    assert(chip8->registers.SP < CHIP8_TOTAL_STACK_DEPTH);
}

void chip8StackPush(struct chip8* chip8, short value) {
    chip8StackInBounds(chip8);
    chip8->stack.stack[chip8->registers.SP] = value;
    chip8->registers.SP += 1;
}

short chip8StackPop(struct chip8* chip8) {
    chip8->registers.SP -= 1;
    chip8StackInBounds(chip8);
    return chip8->stack.stack[chip8->registers.SP];
}
