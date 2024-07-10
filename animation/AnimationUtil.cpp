#include "../util/util.h"
#include "AnimationUtil.h"
#include "math.h"

float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

void AnimValue::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void AnimationInstace::upadteAnim() {
    if (currentProgress > -1 and currentProgress < progress.size()) {
        float x = lerp(startValue.x, endValue.x, progress[currentProgress]);
        float y = lerp(startValue.y, endValue.y, progress[currentProgress]);
        float z = lerp(startValue.z, endValue.z, progress[currentProgress]);
        currentValue.set(x, y, z);
        currentProgress++;
    }
}

bool AnimationInstace::animFinished() {
    return currentProgress >= progress.size();
}

void AnimationInstace::start() {
    if (currentProgress < 0) {
        currentProgress = 0;
    }
}

AnimationInstace::AnimationInstace() {
    progress.clear();
    int animCount = 30;
    for (int i = 0;i < animCount + 1;i++) {
        float p = i * 1.0f / animCount;
        p = sin(p * M_PI - M_PI_2) / 2 + 0.5;
        progress.push_back(p);
    }
}

int AnimationUtil::tokenCount = -1;
map<int, AnimationInstace*> AnimationUtil::runningAnim;
map<int, function<void(AnimValue)>> AnimationUtil::endListener;

void AnimationUtil::upadteAnim() {
    set<int> finished;
    for (auto& anim : runningAnim) {
        if (anim.second->animFinished()) {
            finished.insert(anim.first);
        }
    }
    for (int i : finished) {
        if (endListener.count(i)) {
            endListener[i](runningAnim[i]->endValue);
        }
        delete runningAnim[i];
        runningAnim.erase(i);
    }
    for (auto& anim : runningAnim) {
        anim.second->upadteAnim();
    }
}

bool AnimationUtil::isAnimRunning(int token) {
    return runningAnim.count(token);
}

AnimValue AnimationUtil::getCurrentAnimValue(int token) {
    return runningAnim[token]->currentValue;
}

AnimValue AnimationUtil::getLastAnimValue(int token) {
    return runningAnim[token]->lastValue;
}

void AnimationUtil::saveCurrentValueAsLastValue(int token) {
    runningAnim[token]->lastValue = runningAnim[token]->currentValue;
}

int AnimationUtil::addAnimation(AnimValue start, AnimValue end) {
    tokenCount++;
    auto* anim = new AnimationInstace();
    anim->startValue = start;
    anim->endValue = end;
    anim->lastValue = start;
    anim->start();
    runningAnim[tokenCount] = anim;
    return tokenCount;
}

void AnimationUtil::applyAnimAction(int token, const function<void(AnimValue, AnimValue)>& action) {
    if (isAnimRunning(token)) {
        action(getCurrentAnimValue(token), getLastAnimValue(token));
        saveCurrentValueAsLastValue(token);
    }
}

void AnimationUtil::addEndListener(int token, const function<void(AnimValue)>& listener) {
    endListener[token] = listener;
}

