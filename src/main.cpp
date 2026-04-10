/*
=========================================================
 Taskr - Minimal Windows Automation Engine
=========================================================

 This is the initial UI + window foundation of Taskr.

 Purpose:
 --------
 - Create a native WinAPI window
 - Render a minimal responsive UI
 - Serve as the base for future automation modules

 Architecture Role:
 -------------------
 Platform Layer → handles Windows system interaction
 UI Layer       → renders simple state ("In Progress")
 Future Core    → will connect input + automation engine

 Design Goals:
 -------------
 - No external dependencies
 - Fully native WinAPI (C++)
 - Lightweight and fast
 - Easy to extend into automation engine

=========================================================
*/

#include <windows.h>

/*
=========================================================
 Window Procedure (Event Handler)
=========================================================

 Handles all Windows messages:
 - Paint events (UI rendering)
 - Keyboard input
 - Window lifecycle events
=========================================================
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

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

        // Transparent text background for clean UI
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(0, 0, 0));

        // =================================================
        // Responsive font scaling
        // - Adjusts text size based on window height
        // - Keeps UI readable at all sizes
        // =================================================
        int fontSize = height / 8;

        // Clamp font size for usability
        if (fontSize < 18) fontSize = 18;
        if (fontSize > 80) fontSize = 80;

        HFONT font = CreateFontW(
            fontSize, 0, 0, 0, FW_BOLD,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH,
            L"Segoe UI"
        );

        HFONT oldFont = (HFONT)SelectObject(hdc, font);

        // =================================================
        // UI Text (temporary system state display)
        // =================================================
        const wchar_t* text = L"Taskr: In Progress 🚧";

        // Centered rendering (modern UI style)
        DrawTextW(
            hdc,
            text,
            -1,
            &rect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE
        );

        // Cleanup GDI objects (important for memory safety)
        SelectObject(hdc, oldFont);
        DeleteObject(font);

        EndPaint(hwnd, &ps);
        return 0;
    }
    }

    // Default Windows behavior for unhandled messages
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/*
=========================================================
 Entry Point (WinMain)
=========================================================
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    // -----------------------------------------------------
    // Window Class Definition
    // -----------------------------------------------------
    const wchar_t CLASS_NAME[] = L"TaskrWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    // Cursor style
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    // Default window background
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);

    // -----------------------------------------------------
    // Window Creation
    // -----------------------------------------------------
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

    // Show window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // -----------------------------------------------------
    // Main Message Loop
    // -----------------------------------------------------
    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}