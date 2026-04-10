#pragma once
#include <windows.h>

/*
=========================================================
 Keyboard Input Module (Taskr)
=========================================================

Location:
    src/core/input/

Responsibility:
    Handles all keyboard input logic for Taskr.

Design Rule:
    - This module ONLY deals with raw keyboard state/input
    - It does NOT control engine logic directly
    - Engine will consume processed input later
=========================================================
*/

class Keyboard {
public:
    Keyboard();
    ~Keyboard();

    void initialize();
    void shutdown();

    // Temporary helper (will later be replaced by hook system)
    bool isKeyDown(int key);
};