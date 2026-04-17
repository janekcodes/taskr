#pragma once
#include <vector>

/*
=========================================================
 Recorder Module (Taskr)
=========================================================

Responsibility:
    Records user input events (keyboard + mouse)
    for later playback by Player.

Role in Engine:
    Input → Recorder → Player → Engine

Design:
    - No playback logic
    - State-based recording system
    - Future: event buffer storage
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

    // State queries
    bool isRecording() const;
    bool isPaused() const;
    bool isStopped() const;

private:
    RecorderState m_state = RecorderState::Stopped;

    // Future:
    // std::vector<InputEvent> m_events;
};