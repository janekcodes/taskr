#include "keyboard.h"

std::unordered_map<int, bool> Keyboard::currentState;
std::unordered_map<int, bool> Keyboard::previousState;

void Keyboard::update() {
    previousState = currentState;

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