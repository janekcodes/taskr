#include "task_engine.h"

/*
=========================================================
 TaskEngine Implementation
=========================================================
*/

TaskEngine::TaskEngine() {
}

TaskEngine::~TaskEngine() {
    shutdown();
}

void TaskEngine::initialize() {
    // Future: initialize systems if needed
}

void TaskEngine::shutdown() {
    m_player.stop();
    m_recorder.stopRecording();
}

void TaskEngine::update() {
    // Update input systems
    Keyboard::update();
    Mouse::update();

    // Future: pass input into recorder here
    if (m_recorder.isRecording()) {
        // TODO: capture input events
    }

    // Future: playback execution
    if (m_player.isPlaying()) {
        // TODO: replay recorded events
    }
}

/*
=========================================================
 External Control (UI Hooks)
=========================================================
*/

void TaskEngine::startRecording() {
    m_recorder.startRecording();
}

void TaskEngine::stopRecording() {
    m_recorder.stopRecording();
}

void TaskEngine::pauseRecording() {
    m_recorder.pauseRecording();
}

void TaskEngine::play() {
    m_player.play();
}

void TaskEngine::stopPlayback() {
    m_player.stop();
}

/*
=========================================================
 State Queries
=========================================================
*/

bool TaskEngine::isRecording() const {
    return m_recorder.isRecording();
}

bool TaskEngine::isPlaying() const {
    return m_player.isPlaying();
}