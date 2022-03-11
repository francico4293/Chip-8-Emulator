#include "chip8_memory.h"
#include <assert.h>

void memoryBoundsCheck(int index) {
    assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}

void chip8MemorySet(struct chip8Memory* memory, int index, char val) {
    memoryBoundsCheck(index);
    memory->memory[index] = val;
}

char chip8MemoryGet(struct chip8Memory* memory, int index) {
    memoryBoundsCheck(index);
    return memory->memory[index];
}
