#pragma once
#include <windows.h>

/*
=========================================================
 Mouse Input Module (Taskr)
=========================================================

Location:
    src/core/input/

Responsibility:
    Handles all mouse input logic for Taskr.

Design Rule:
    - Only raw mouse state handling here
    - No automation logic
    - Engine will interpret events later
=========================================================
*/

class Mouse {
public:
    Mouse();
    ~Mouse();

    void initialize();
    void shutdown();

    POINT getPosition();
    bool leftDown();
    bool rightDown();
};