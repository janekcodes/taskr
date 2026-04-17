#pragma once

#include "../input/keyboard.h"
#include "../input/mouse.h"
#include "../player/player.h"
#include "../recorder/recorder.h"

/*
=========================================================
 TaskEngine (Taskr)
=========================================================

Responsibility:
    Central controller for all core systems.

Flow:
    Input → Recorder → Player → Engine

Design:
    - Owns core systems
    - Coordinates update loop
    - No platform-specific logic
=========================================================
*/

class TaskEngine {
public:
    TaskEngine();
    ~TaskEngine();

    // Lifecycle
    void initialize();
    void shutdown();

    // Main loop
    void update();

    // UI / external control hooks
    void startRecording();
    void stopRecording();
    void pauseRecording();

    void play();
    void stopPlayback();

    // State queries (for UI)
    bool isRecording() const;
    bool isPlaying() const;

private:
    Player m_player;
    Recorder m_recorder;
};