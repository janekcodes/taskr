#pragma once

/*
=========================================================
 Player Module (Taskr)
=========================================================

Location:
    src/core/player/

Responsibility:
    Executes (replays) recorded input events.

Role in Engine:
    Recorder → stores actions
    Player → replays actions
    Engine → controls flow
=========================================================
*/

class Player {
public:
    Player();
    ~Player();

    // Lifecycle
    void initialize();
    void shutdown();

    // Playback control
    void play();
    void stop();
    void pause();

    // State query
    bool isPlaying() const;

private:
    bool m_isPlaying;
};