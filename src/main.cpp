#include <windows.h>

#include "utils/time.h"
#include "core/engine/task_engine.h"

// =========================================================
// Button IDs
// =========================================================
#define ID_BTN_START 101
#define ID_BTN_STOP  102
#define ID_BTN_PLAY  103

TaskEngine g_engine;

// =========================================================
// Window Procedure
// =========================================================
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {

        g_engine.initialize();

        RECT rect;
        GetClientRect(hwnd, &rect);

        int width = rect.right - rect.left;

        int btnW = 200;
        int btnH = 40;
        int spacing = 12;

        int startX = (width - btnW) / 2;
        int startY = 320;

        CreateWindowW(L"BUTTON", L"Start Recording",
            WS_VISIBLE | WS_CHILD,
            startX, startY, btnW, btnH,
            hwnd, (HMENU)ID_BTN_START, NULL, NULL);

        CreateWindowW(L"BUTTON", L"Stop",
            WS_VISIBLE | WS_CHILD,
            startX, startY + btnH + spacing, btnW, btnH,
            hwnd, (HMENU)ID_BTN_STOP, NULL, NULL);

        CreateWindowW(L"BUTTON", L"Play",
            WS_VISIBLE | WS_CHILD,
            startX, startY + (btnH + spacing) * 2, btnW, btnH,
            hwnd, (HMENU)ID_BTN_PLAY, NULL, NULL);

        return 0;
    }

    case WM_COMMAND: {
        switch (LOWORD(wParam)) {

        case ID_BTN_START:
            g_engine.startRecording();
            break;

        case ID_BTN_STOP:
            g_engine.stopRecording();
            g_engine.stopPlayback();
            break;

        case ID_BTN_PLAY:
            g_engine.play();
            break;
        }

        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
    }

    case WM_DESTROY:
        g_engine.shutdown();
        PostQuitMessage(0);
        return 0;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
            PostQuitMessage(0);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT rect;
        GetClientRect(hwnd, &rect);

        int w = rect.right - rect.left;
        int h = rect.bottom - rect.top;

        // =================================================
        // BACKGROUND (dark theme)
        // =================================================
        HBRUSH bg = CreateSolidBrush(RGB(18, 18, 22));
        FillRect(hdc, &rect, bg);
        DeleteObject(bg);

        SetBkMode(hdc, TRANSPARENT);

        // =================================================
        // TITLE
        // =================================================
        SetTextColor(hdc, RGB(235, 235, 235));

        HFONT titleFont = CreateFontW(
            54, 0, 0, 0, FW_BOLD,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH,
            L"Segoe UI"
        );

        HFONT old = (HFONT)SelectObject(hdc, titleFont);

        RECT titleRect = rect;
        titleRect.top = 80;
        titleRect.bottom = 200;

        DrawTextW(hdc, L"Taskr", -1, &titleRect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        SelectObject(hdc, old);
        DeleteObject(titleFont);

        // =================================================
        // STATE TEXT (dynamic)
        // =================================================
        const wchar_t* state = L"Idle";
        COLORREF color = RGB(160, 160, 160);

        if (g_engine.isRecording()) {
            state = L"Recording...";
            color = RGB(255, 80, 80);
        }
        else if (g_engine.isPlaying()) {
            state = L"Playing...";
            color = RGB(80, 160, 255);
        }

        SetTextColor(hdc, color);

        HFONT stateFont = CreateFontW(
            24, 0, 0, 0, FW_NORMAL,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH,
            L"Segoe UI"
        );

        SelectObject(hdc, stateFont);

        RECT stateRect = rect;
        stateRect.top = 180;
        stateRect.bottom = 260;

        DrawTextW(hdc, state, -1, &stateRect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        DeleteObject(stateFont);

        EndPaint(hwnd, &ps);
        return 0;
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// =========================================================
// ENTRY POINT
// =========================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    const wchar_t CLASS_NAME[] = L"TaskrWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Taskr",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        900, 600,
        NULL, NULL,
        hInstance, NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);

        Time::update();
        g_engine.update();
    }

    return 0;
}