#pragma once
#include <vector>
#include "../events/input_events.h"
#include <windows.h>

/*
=========================================================
 Recorder Module (Taskr)
=========================================================

Responsibility:
    Records user input events (mouse for now)

Design:
    - State-driven (Stopped / Recording / Paused)
    - Stores timestamped input events
    - No playback logic here
=========================================================
*/

enum class RecorderState {
    Stopped,
    Recording,
    Paused
};

class Recorder {
public:
    Recorder();
    ~Recorder();

    // Recording control
    void startRecording();
    void stopRecording();
    void pauseRecording();

    // Called every frame (VERY IMPORTANT)
    void update();

    // State queries
    bool isRecording() const;
    bool isPaused() const;
    bool isStopped() const;

    // Access recorded data
    const std::vector<MouseEvent>& getEvents() const;

private:
    RecorderState m_state = RecorderState::Stopped;

    long long m_startTime = 0;

    std::vector<MouseEvent> m_events;
};