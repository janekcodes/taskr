#pragma once
#include <Windows.h>

/*
=========================================================
 Mouse Input Module (Taskr)
=========================================================

Responsibility:
    Handles raw mouse input state.

Design:
    - Frame-based polling
    - No engine logic
    - Clean state + position tracking
=========================================================
*/

class Mouse {
public:
    static void update();

    // Position
    static POINT getPosition();
    static int getX();
    static int getY();

    // Button state
    static bool isLeftDown();
    static bool isRightDown();

    // Edge detection
    static bool isLeftPressed();
    static bool isRightPressed();
    static bool isLeftReleased();
    static bool isRightReleased();

private:
    static bool currentLeft;
    static bool previousLeft;

    static bool currentRight;
    static bool previousRight;

    static POINT position;
};