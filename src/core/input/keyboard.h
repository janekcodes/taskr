#pragma once
#include <Windows.h>
#include <unordered_map>

/*
=========================================================
 Keyboard Input Module (Taskr)
=========================================================

Location:
    src/core/input/

Responsibility:
    Handles raw keyboard input state.

Design Rules:
    - No engine/game logic here
    - Provides clean, queryable input state
    - Polling-based for now (hook system later)
=========================================================
*/

enum class Key {
    Escape = VK_ESCAPE,
    Space  = VK_SPACE,

    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44
    // Expand as needed
};

class Keyboard {
public:
    // Must be called once per frame/update loop
    static void update();

    // Current state
    static bool isKeyDown(Key key);

    // Edge detection
    static bool isKeyPressed(Key key);   // down this frame, not last
    static bool isKeyReleased(Key key);  // up this frame, down last

private:
    static std::unordered_map<int, bool> currentState;
    static std::unordered_map<int, bool> previousState;
};