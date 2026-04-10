#include "mouse.h"

/*
=========================================================
 Mouse Input Implementation
=========================================================
*/

Mouse::Mouse() {
    // Reserved
}

Mouse::~Mouse() {
    // Reserved
}

void Mouse::initialize() {
    // Future:
    // - SetWindowsHookEx(WH_MOUSE_LL, ...)
}

void Mouse::shutdown() {
    // Future:
    // - Remove mouse hook
}

POINT Mouse::getPosition() {
    POINT p;
    GetCursorPos(&p);
    return p;
}

bool Mouse::leftDown() {
    return (GetAsyncKeyState(VK_LBUTTON) & 0x8000);
}

bool Mouse::rightDown() {
    return (GetAsyncKeyState(VK_RBUTTON) & 0x8000);
}