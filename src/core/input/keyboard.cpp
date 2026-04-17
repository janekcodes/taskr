#include "keyboard.h"

/*
=========================================================
 Keyboard Input Implementation
=========================================================
*/

bool Keyboard::currentState[256] = { false };
bool Keyboard::previousState[256] = { false };

void Keyboard::update() {
    // Copy current state → previous state
    for (int i = 0; i < 256; ++i) {
        previousState[i] = currentState[i];
    }

    // Refresh current key states
    for (int key = 0; key < 256; ++key) {
        currentState[key] = (GetAsyncKeyState(key) & 0x8000) != 0;
    }
}

bool Keyboard::isKeyDown(Key key) {
    return currentState[static_cast<int>(key)];
}

bool Keyboard::isKeyPressed(Key key) {
    int k = static_cast<int>(key);
    return currentState[k] && !previousState[k];
}

bool Keyboard::isKeyReleased(Key key) {
    int k = static_cast<int>(key);
    return !currentState[k] && previousState[k];
}