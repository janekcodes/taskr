#include "recorder.h"

/*
=========================================================
 Recorder Implementation
=========================================================
*/

Recorder::Recorder()
    : m_state(RecorderState::Stopped)
{
}

Recorder::~Recorder() {
    stopRecording();
}

void Recorder::startRecording() {
    if (m_state != RecorderState::Recording) {
        m_state = RecorderState::Recording;

        // Future:
        // - clear event buffer
        // - begin capturing input
    }
}

void Recorder::stopRecording() {
    m_state = RecorderState::Stopped;

    // Future:
    // - finalize recording session
}

void Recorder::pauseRecording() {
    if (m_state == RecorderState::Recording) {
        m_state = RecorderState::Paused;
    }
}

bool Recorder::isRecording() const {
    return m_state == RecorderState::Recording;
}

bool Recorder::isPaused() const {
    return m_state == RecorderState::Paused;
}

bool Recorder::isStopped() const {
    return m_state == RecorderState::Stopped;
}