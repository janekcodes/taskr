#include "recorder.h"
#include "../../utils/time.h"

/*
=========================================================
 Recorder Implementation
=========================================================
*/

Recorder::Recorder()
    : m_state(RecorderState::Stopped),
      m_startTime(0)
{
}

Recorder::~Recorder() {
    stopRecording();
}

void Recorder::startRecording() {
    if (m_state != RecorderState::Recording) {

        m_events.clear();                    // 🔥 clear old recording
        m_startTime = Time::nowMillis();     // 🔥 start timestamp

        m_state = RecorderState::Recording;
    }
}

void Recorder::stopRecording() {
    m_state = RecorderState::Stopped;
}

void Recorder::pauseRecording() {
    if (m_state == RecorderState::Recording) {
        m_state = RecorderState::Paused;
    }
}

void Recorder::update() {
    if (m_state != RecorderState::Recording) return;

    POINT p;
    GetCursorPos(&p);

    long long now = Time::nowMillis();

    // 🔥 store mouse position with relative time
    m_events.push_back({
        now - m_startTime,
        p
    });
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

const std::vector<MouseEvent>& Recorder::getEvents() const {
    return m_events;
}