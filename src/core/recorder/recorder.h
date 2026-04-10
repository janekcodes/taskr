#pragma once
#include <vector>

/*
=========================================================
 Recorder Module (Taskr)
=========================================================

Location:
    src/core/recorder/

Responsibility:
    Records user input events (keyboard + mouse)
    and stores them for later playback by Player.

Role in Engine:
    Input → Recorder → Player → Engine
=========================================================
*/

class Recorder {
public:
    Recorder();
    ~Recorder();

    // Lifecycle
    void initialize();
    void shutdown();

    // Recording control
    void startRecording();
    void stopRecording();

    bool isRecording() const;

private:
    bool m_isRecording;
};