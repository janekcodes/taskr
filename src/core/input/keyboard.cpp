#include "keyboard.h"

/*
=========================================================
 Keyboard Input Implementation
=========================================================
*/

Keyboard::Keyboard() {
    // Reserved for future initialization
}

Keyboard::~Keyboard() {
    // Reserved for cleanup (hooks later)
}

void Keyboard::initialize() {
    // Future:
    // - SetWindowsHookEx(WH_KEYBOARD_LL, ...)
    // - Register callback for key events
}

void Keyboard::shutdown() {
    // Future:
    // - Unhook keyboard listener
}

bool Keyboard::isKeyDown(int key) {
    // Temporary implementation (polling-based)
    return (GetAsyncKeyState(key) & 0x8000);
}