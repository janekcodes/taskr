#include "win_hooks.h"

/*
=========================================================
 WinHooks Implementation (Skeleton)
=========================================================
*/

WinHooks::WinHooks()
    : m_keyboardHook(nullptr), m_mouseHook(nullptr)
{
}

WinHooks::~WinHooks() {
    shutdown();
}

bool WinHooks::initialize() {
    // Future:
    // - SetWindowsHookEx for keyboard and mouse

    return true;
}

void WinHooks::shutdown() {
    // Future:
    // - Unhook Windows hooks safely

    if (m_keyboardHook) {
        UnhookWindowsHookEx(m_keyboardHook);
        m_keyboardHook = nullptr;
    }

    if (m_mouseHook) {
        UnhookWindowsHookEx(m_mouseHook);
        m_mouseHook = nullptr;
    }
}

/*
=========================================================
 Hook callbacks (future implementation)
=========================================================
*/

LRESULT CALLBACK WinHooks::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Future:
    // - Capture key press/release
    // - Send to Recorder

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

LRESULT CALLBACK WinHooks::MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Future:
    // - Capture mouse movement/clicks
    // - Send to Recorder

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}