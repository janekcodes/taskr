#pragma once
#include <windows.h>

/*
=========================================================
 WinHooks Module (Taskr)
=========================================================

Location:
    src/core/platform/windows/

Responsibility:
    Handles low-level Windows input hooks.

Future Role:
    - Capture global keyboard input (WH_KEYBOARD_LL)
    - Capture global mouse input (WH_MOUSE_LL)
    - Feed events into Recorder module
=========================================================
*/

class WinHooks {
public:
    WinHooks();
    ~WinHooks();

    bool initialize();
    void shutdown();

private:
    HHOOK m_keyboardHook;
    HHOOK m_mouseHook;

    static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
};