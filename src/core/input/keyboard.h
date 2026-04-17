#pragma once
#include <Windows.h>

/*
=========================================================
 Keyboard Input Module (Taskr)
=========================================================

Responsibility:
    Handles raw keyboard input state.

Design:
    - Frame-based polling
    - No engine logic
    - Fast array-based state tracking
=========================================================
*/

enum class Key : int {
    Escape = VK_ESCAPE,
    Space  = VK_SPACE,
    P      = 0x50,

    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44
};

class Keyboard {
public:
    static void update();

    static bool isKeyDown(Key key);
    static bool isKeyPressed(Key key);
    static bool isKeyReleased(Key key);

private:
    static bool currentState[256];
    static bool previousState[256];
};