#pragma once
#include <windows.h>

/*
=========================================================
 Shared Input Event Definitions
=========================================================
*/

struct MouseEvent {
    long long time;
    POINT position;
};