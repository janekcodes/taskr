#pragma once

/*
=========================================================
 Player Module (Taskr)
=========================================================

Responsibility:
    Handles playback of recorded input events.

Role in Engine:
    Recorder → stores input
    Player   → replays input
    Engine   → controls flow

Design:
    - No input capture
    - Pure playback state machine
=========================================================
*/

enum class PlayerState {
    Stopped,
    Playing,
    Paused
};

class Player {
public:
    Player();
    ~Player();

    // Playback control
    void play();
    void stop();
    void pause();

    // State queries
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

private:
    PlayerState m_state = PlayerState::Stopped;
};