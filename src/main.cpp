/*
=========================================================
 Taskr - Minimal Windows Automation Engine
=========================================================

This is the initial UI + window foundation of Taskr.

 Current State:
 --------------
 - Native WinAPI window system
 - Minimal responsive UI layout
 - Interactive button-based control panel

 Purpose:
 --------
 - Provide a clean native Windows interface
 - Introduce a basic control system (Start / Stop / Play)
 - Establish the foundation for automation features

 Architecture Role:
 -------------------
 Platform Layer → handles Windows system interaction
 UI Layer       → renders layout + user controls
 Core (Next)    → will connect input + automation engine

 Design Goals:
 -------------
 - No external dependencies
 - Fully native WinAPI (C++)
 - Lightweight and fast
 - Clean and minimal UI system
 - Easy to extend into full automation engine

 Notes:
 ------
 This version introduces the first interactive UI layer.
 Buttons currently serve as placeholders for upcoming
 automation features (recording, playback, input hooks).

=========================================================
*/

#include <windows.h>

// =========================================================
// Button Identifiers (ADDED)
// =========================================================
#define ID_BTN_START 101
#define ID_BTN_STOP  102
#define ID_BTN_PLAY  103

/*
=========================================================
 Window Procedure (Event Handler)
=========================================================
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    // -----------------------------------------------------
    // CREATE (ADDED - initialize buttons)
    // -----------------------------------------------------
    case WM_CREATE: {
        RECT rect;
        GetClientRect(hwnd, &rect);

        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        int btnWidth = 220;
        int btnHeight = 45;
        int spacing = 15;

        int totalHeight = (btnHeight * 3) + (spacing * 2);
        int startY = (height - totalHeight) / 2;
        int centerX = (width - btnWidth) / 2;

        CreateWindowW(
            L"BUTTON", L"Start Recording",
            WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            centerX, startY,
            btnWidth, btnHeight,
            hwnd,
            (HMENU)ID_BTN_START,
            NULL, NULL
        );

        CreateWindowW(
            L"BUTTON", L"Stop Recording",
            WS_VISIBLE | WS_CHILD,
            centerX, startY + btnHeight + spacing,
            btnWidth, btnHeight,
            hwnd,
            (HMENU)ID_BTN_STOP,
            NULL, NULL
        );

        CreateWindowW(
            L"BUTTON", L"Play",
            WS_VISIBLE | WS_CHILD,
            centerX, startY + (btnHeight + spacing) * 2,
            btnWidth, btnHeight,
            hwnd,
            (HMENU)ID_BTN_PLAY,
            NULL, NULL
        );

        return 0;
    }

    // -----------------------------------------------------
    // COMMAND HANDLER (ADDED - button clicks)
    // -----------------------------------------------------
    case WM_COMMAND: {
        int id = LOWORD(wParam);

        switch (id) {
        case ID_BTN_START:
            MessageBoxW(hwnd, L"Start Recording clicked", L"Taskr", MB_OK);
            break;

        case ID_BTN_STOP:
            MessageBoxW(hwnd, L"Stop Recording clicked", L"Taskr", MB_OK);
            break;

        case ID_BTN_PLAY:
            MessageBoxW(hwnd, L"Play clicked", L"Taskr", MB_OK);
            break;
        }

        return 0;
    }

    // -----------------------------------------------------
    // Window close event
    // -----------------------------------------------------
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    // -----------------------------------------------------
    // Keyboard input handling
    // ESC → exit application
    // -----------------------------------------------------
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            PostQuitMessage(0);
        }
        return 0;

    // -----------------------------------------------------
    // Paint / Render UI
    // -----------------------------------------------------
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT rect;
        GetClientRect(hwnd, &rect);

        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        // =================================================
        // Background rendering (solid white)
        // =================================================
        HBRUSH bg = CreateSolidBrush(RGB(255, 255, 255));
        FillRect(hdc, &rect, bg);
        DeleteObject(bg);

        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(0, 0, 0));

        int titleSize = height / 10;
        if (titleSize < 24) titleSize = 24;
        if (titleSize > 72) titleSize = 72;

        int subtitleSize = height / 20;
        if (subtitleSize < 14) subtitleSize = 14;
        if (subtitleSize > 36) subtitleSize = 36;

        HFONT titleFont = CreateFontW(
            titleSize, 0, 0, 0, FW_BOLD,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH,
            L"Segoe UI"
        );

        HFONT subtitleFont = CreateFontW(
            subtitleSize, 0, 0, 0, FW_NORMAL,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH,
            L"Segoe UI"
        );

        HFONT oldFont = (HFONT)SelectObject(hdc, titleFont);

        const wchar_t* title = L"Taskr";
        const wchar_t* subtitle = L"In Progress 🚧";

        RECT titleRect = rect;
        titleRect.bottom = height / 2;

        RECT subtitleRect = rect;
        subtitleRect.top = height / 2;

        DrawTextW(
            hdc,
            title,
            -1,
            &titleRect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE
        );

        SelectObject(hdc, subtitleFont);
        DrawTextW(
            hdc,
            subtitle,
            -1,
            &subtitleRect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE
        );

        SelectObject(hdc, oldFont);
        DeleteObject(titleFont);
        DeleteObject(subtitleFont);

        EndPaint(hwnd, &ps);
        return 0;
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/*
=========================================================
 Entry Point (WinMain)
=========================================================
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    const wchar_t CLASS_NAME[] = L"TaskrWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Taskr",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        900, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}