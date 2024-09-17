#include "util/util.h"
#include "util/timer.h"
#include "error/ErrorManager.h"
#include "hotkey/DoubleClickStateMachine.h"

DoubleClickStateMachine::DoubleClickStateMachine(const long& timeoutMilli) {
    this->timeoutMilli = timeoutMilli;
    this->timer = new Timer([&]() {
        this->timer->stop();
        this->handleMessage(msg_first_click_timeout);
        }, timeoutMilli);
}

void DoubleClickStateMachine::onClick(const std::function<void(void)>& onDoubleClick) {
    this->onDoubleClick = onDoubleClick;
    handleMessage(msg_click_down);
}

void DoubleClickStateMachine::handleMessage(int msg) {
    // update state according to msg and currentState
    switch (currentState) {
    case state_init:
        switch (msg) {
        case msg_click_down:
            currentState = state_first_click_down_and_time_counting;
            break;
        case msg_first_click_timeout:
            // ignore
            break;
        default:
            break;
        }
        break;
    case state_first_click_down_and_time_counting:
        switch (msg) {
        case msg_click_down:
            currentState = state_second_click_down_before_timeout;
            break;
        case msg_first_click_timeout:
            currentState = state_timeout_before_second_click;
            break;
        default:
            break;
        }
        break;
    case state_second_click_down_before_timeout:
        break;
    case state_timeout_before_second_click:
        break;
    default:
        break;
    }

    // react on currentState
    switch (currentState) {
    case state_init:
        break;
    case state_first_click_down_and_time_counting:
        startTimeout();
        break;
    case state_second_click_down_before_timeout:
        cancelTimeout();
        onDoubleClick();
        currentState = state_init;
        break;
    case state_timeout_before_second_click:
        currentState = state_init;
        break;
    default:
        break;
    }
}

void DoubleClickStateMachine::startTimeout() {
    if (timer->isRunning()) {
        timer->stop();
    }
    timer->start();
}

void DoubleClickStateMachine::cancelTimeout() {
    timer->stop();
}
