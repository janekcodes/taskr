#include "player.h"
#include "../../utils/time.h"

Player::Player() {}

Player::~Player() {
    stop();
}

/*
=========================================================
 PLAYBACK START
=========================================================
*/

void Player::play(const std::vector<MouseEvent>& events) {
    if (events.empty()) return;

    m_events = events;
    m_index = 0;
    m_startTime = Time::nowMillis();
    m_state = PlayerState::Playing;
}

/*
=========================================================
 STOP PLAYBACK
=========================================================
*/

void Player::stop() {
    m_state = PlayerState::Stopped;
    m_events.clear();
    m_index = 0;
}

/*
=========================================================
 PAUSE (future use)
=========================================================
*/

void Player::pause() {
    if (m_state == PlayerState::Playing) {
        m_state = PlayerState::Paused;
    }
}

/*
=========================================================
 UPDATE LOOP (IMPORTANT)
=========================================================
*/

void Player::update() {
    if (m_state != PlayerState::Playing) return;

    long long now = Time::nowMillis();
    long long elapsed = now - m_startTime;

    // 🔥 play all events that should have happened by now
    while (m_index < m_events.size() &&
           m_events[m_index].time <= elapsed) {

        const POINT& p = m_events[m_index].position;
        SetCursorPos(p.x, p.y);

        m_index++;
    }

    // 🔥 finished playback
    if (m_index >= m_events.size()) {
        stop();
    }
}

/*
=========================================================
 STATE QUERIES
=========================================================
*/

bool Player::isPlaying() const {
    return m_state == PlayerState::Playing;
}

bool Player::isPaused() const {
    return m_state == PlayerState::Paused;
}

bool Player::isStopped() const {
    return m_state == PlayerState::Stopped;
}