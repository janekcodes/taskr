#include "time.h"
#include <chrono>
#include <ctime>

/*
=========================================================
 Time Implementation (Taskr)
=========================================================
*/

long long Time::m_startTime = 0;
long long Time::m_lastFrameTime = 0;
float Time::m_deltaTime = 0.0f;

/*
---------------------------------------------------------
 Absolute Time
---------------------------------------------------------
*/

long long Time::nowMillis() {
    using namespace std::chrono;

    return duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    ).count();
}

std::string Time::nowString() {
    std::time_t t = std::time(nullptr);
    char buffer[64];

    std::strftime(
        buffer,
        sizeof(buffer),
        "%Y-%m-%d %H:%M:%S",
        std::localtime(&t)
    );

    return std::string(buffer);
}

/*
---------------------------------------------------------
 Engine Timing
---------------------------------------------------------
*/

void Time::update() {
    long long current = nowMillis();

    // First frame init
    if (m_startTime == 0) {
        m_startTime = current;
        m_lastFrameTime = current;
    }

    m_deltaTime = (current - m_lastFrameTime) / 1000.0f;
    m_lastFrameTime = current;
}

float Time::deltaTime() {
    return m_deltaTime;
}

float Time::timeSinceStart() {
    return (nowMillis() - m_startTime) / 1000.0f;
}