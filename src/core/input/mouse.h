#pragma once
#include <Windows.h>

/*
=========================================================
 Mouse Input Module (Taskr)
=========================================================

Location:
    src/core/input/

Responsibility:
    Handles raw mouse input state.

Design Rules:
    - No engine logic here
    - Frame-based polling system
    - Clean, queryable interface
=========================================================
*/

class Mouse {
public:
    // Must be called once per frame
    static void update();

    // Position
    static POINT getPosition();
    static int getX();
    static int getY();

    // Current state
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