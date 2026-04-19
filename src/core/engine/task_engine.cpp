#include "task_engine.h"

/*
=========================================================
 TaskEngine Implementation
=========================================================
*/

TaskEngine::TaskEngine() {}

TaskEngine::~TaskEngine() {
    shutdown();
}

void TaskEngine::initialize() {
    // reserved for future systems
}

void TaskEngine::shutdown() {
    m_player.stop();
    m_recorder.stopRecording();
}

/*
=========================================================
 MAIN UPDATE LOOP
=========================================================
*/

void TaskEngine::update() {
    // input polling
    Keyboard::update();
    Mouse::update();

    // ===============================
    // RECORDING
    // ===============================
    if (m_recorder.isRecording()) {
        m_recorder.update(); // 🔥 THIS WAS MISSING
    }

    // ===============================
    // PLAYBACK
    // ===============================
    if (m_player.isPlaying()) {
        m_player.update(); // 🔥 THIS WAS MISSING
    }
}

/*
=========================================================
 CONTROL FROM UI
=========================================================
*/

void TaskEngine::startRecording() {
    m_player.stop();               // stop playback if active
    m_recorder.startRecording();
}

void TaskEngine::stopRecording() {
    m_recorder.stopRecording();
}

void TaskEngine::pauseRecording() {
    m_recorder.pauseRecording();
}

void TaskEngine::play() {
    // 🔥 IMPORTANT: pass recorded data into player
    m_player.play(m_recorder.getEvents());
}

void TaskEngine::stopPlayback() {
    m_player.stop();
}

/*
=========================================================
 STATE QUERIES
=========================================================
*/

bool TaskEngine::isRecording() const {
    return m_recorder.isRecording();
}

bool TaskEngine::isPlaying() const {
    return m_player.isPlaying();
}