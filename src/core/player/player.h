#pragma once

/*
=========================================================
 Player Module (Taskr)
=========================================================

Location:
    src/core/player/

Responsibility:
    Replays recorded input events.

Role in Engine:
    Recorder → stores actions
    Player   → replays actions
    Engine   → controls flow

Design Rules:
    - No input capture here
    - Only playback state + control
    - Frame update handled externally
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
    PlayerState m_state;
};