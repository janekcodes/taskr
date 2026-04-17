#include "player.h"

/*
=========================================================
 Player Implementation
=========================================================
*/

Player::Player()
    : m_state(PlayerState::Stopped)
{
}

Player::~Player() {
    stop();
}

void Player::play() {
    if (m_state != PlayerState::Playing) {
        m_state = PlayerState::Playing;
    }
}

void Player::stop() {
    m_state = PlayerState::Stopped;
}

void Player::pause() {
    if (m_state == PlayerState::Playing) {
        m_state = PlayerState::Paused;
    }
}

bool Player::isPlaying() const {
    return m_state == PlayerState::Playing;
}

bool Player::isPaused() const {
    return m_state == PlayerState::Paused;
}

bool Player::isStopped() const {
    return m_state == PlayerState::Stopped;
}