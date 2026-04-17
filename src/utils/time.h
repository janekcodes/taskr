#pragma once
#include <string>

/*
=========================================================
 Time System (Taskr)
=========================================================

Responsibility:
    Provides both utility time functions and engine timing.

Use Cases:
    - Event timestamps (Recorder)
    - Playback synchronization (Player)
    - Engine frame timing (TaskEngine)
=========================================================
*/

class Time {
public:
    // Absolute system time
    static long long nowMillis();
    static std::string nowString();

    // Engine timing (call once per frame)
    static void update();

    static float deltaTime();        // time between frames (seconds)
    static float timeSinceStart();   // total runtime (seconds)

private:
    static long long m_startTime;
    static long long m_lastFrameTime;
    static float m_deltaTime;
};