#include "chip8_keyboard.h"
#include <assert.h>

static void chip8KeyboardInbounds(int key) {
    assert(key >= 0 && key < CHIP8_TOTAL_KEYS);
}

int chip8KeyboardMap(char* map, char key) {
    for (int index = 0; index < CHIP8_TOTAL_KEYS; index++) {
        if (map[index] == key) {
            return index;
        }
    }

    return -1;
}

void chip8KeyboardDown(struct chip8Keyboard* keyboard, int key) {
    keyboard->keyboard[key] = true;
}

void chip8KeyboardUp(struct chip8Keyboard* keyboard, int key) {
    keyboard->keyboard[key] = false;
}

bool chip8KeyboardIsDown(struct chip8Keyboard* keyboard, int key){
    return keyboard->keyboard[key];
}
