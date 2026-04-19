#pragma once

#include <vector>
#include "../events/input_events.h"
#include <windows.h>

enum class PlayerState {
    Stopped,
    Playing,
    Paused
};

/*
=========================================================
 Player Module (Taskr)
=========================================================

Responsibility:
    Replays recorded mouse input events.

Flow:
    Recorder → stores events
    Player   → plays events back
    Engine   → controls execution

Design:
    - Time-based playback
    - No input capture
=========================================================
*/

class Player {
public:
    Player();
    ~Player();

    // Playback control
    void play(const std::vector<MouseEvent>& events);
    void stop();
    void pause();

    // Called every frame
    void update();

    // State queries
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

private:
    PlayerState m_state = PlayerState::Stopped;

    std::vector<MouseEvent> m_events;
    size_t m_index = 0;

    long long m_startTime = 0;
};