#include "mouse.h"

/*
=========================================================
 Mouse Input Implementation
=========================================================
*/

bool Mouse::currentLeft = false;
bool Mouse::previousLeft = false;

bool Mouse::currentRight = false;
bool Mouse::previousRight = false;

POINT Mouse::position = { 0, 0 };

void Mouse::update() {
    // Store previous state
    previousLeft  = currentLeft;
    previousRight = currentRight;

    // Update button states
    currentLeft  = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
    currentRight = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;

    // Update cursor position
    GetCursorPos(&position);
}

POINT Mouse::getPosition() {
    return position;
}

int Mouse::getX() {
    return position.x;
}

int Mouse::getY() {
    return position.y;
}

bool Mouse::isLeftDown() {
    return currentLeft;
}

bool Mouse::isRightDown() {
    return currentRight;
}

bool Mouse::isLeftPressed() {
    return currentLeft && !previousLeft;
}

bool Mouse::isRightPressed() {
    return currentRight && !previousRight;
}

bool Mouse::isLeftReleased() {
    return !currentLeft && previousLeft;
}

bool Mouse::isRightReleased() {
    return !currentRight && previousRight;
}