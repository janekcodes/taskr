#include "recorder.h"

/*
=========================================================
 Recorder Implementation (Skeleton)
=========================================================
*/

Recorder::Recorder()
    : m_isRecording(false)
{
    // Reserved for setup
}

Recorder::~Recorder() {
    stopRecording();
}

void Recorder::initialize() {
    // Future:
    // - Prepare event buffer
    // - Hook input system (keyboard/mouse)
}

void Recorder::shutdown() {
    // Future:
    // - Stop recording safely
    stopRecording();
}

void Recorder::startRecording() {
    // Future:
    // - Begin capturing input events
    // - Push events into memory buffer
    m_isRecording = true;
}

void Recorder::stopRecording() {
    // Future:
    // - Stop capturing input events
    m_isRecording = false;
}

bool Recorder::isRecording() const {
    return m_isRecording;
}