#pragma once
#include <string>

/*
=========================================================
 Time Utility Module (Taskr)
=========================================================

Location:
    src/core/utils/

Responsibility:
    Provides time-related helper functions.

Future Role:
    - Timestamping events
    - Recording playback timing
    - Debug performance tracking
=========================================================
*/

class Time {
public:
    static long long nowMillis();
    static std::string nowString();
};