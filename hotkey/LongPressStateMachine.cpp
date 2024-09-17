#include "util/util.h"
#include "util/timer.h"
#include "hotkey/LongPressStateMachine.h"

LongPressStateMachine::LongPressStateMachine(const long& timeoutMilli) {
    this->timeoutMilli = timeoutMilli;
    this->timer = new Timer([&]() {
        this->timer->stop();
        this->handleMessage(msg_timeout);
        }, timeoutMilli);
}

void LongPressStateMachine::onPress(std::function<void(void)>& onLongPress) {
    this->onLongPress = onLongPress;
    handleMessage(msg_press);
}

void LongPressStateMachine::onRelease() {
    handleMessage(msg_release);
}

void LongPressStateMachine::handleMessage(int msg) {
    // update state according to msg and currentState
    switch (currentState) {
    case state_init:
        switch (msg) {
        case msg_press:
            currentState = state_pressed;
            break;
        case msg_release:
            // igore
            break;
        case msg_timeout:
            // igore
            break;
        default:
            break;
        }
        break;
    case state_pressed:
        switch (msg) {
        case msg_press:
            // ignore
            break;
        case msg_release:
            currentState = state_released_before_timeout;
            break;
        case msg_timeout:
            currentState = state_timeout_before_released;
            break;
        default:
            break;
        }
        break;
    case state_released_before_timeout:
        break;
    case state_timeout_before_released:
        break;
    default:
        break;
    }
    // react on currentState
    switch (currentState) {
    case state_init:
        break;
    case state_pressed:
        startTimeout();
        break;
    case state_released_before_timeout:
        cancelTimeout();
        currentState = state_init;
        break;
    case state_timeout_before_released:
        onLongPress();
        currentState = state_init;
        break;
    default:
        break;
    }
}

void LongPressStateMachine::startTimeout() {
    cancelTimeout();
    timer->start();
}

void LongPressStateMachine::cancelTimeout() {
    if (timer->isRunning()) {
        timer->stop();
    }
}
