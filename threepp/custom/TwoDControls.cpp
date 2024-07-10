//
// Created by ydd on 10/22/23.
//

#include "threepp/canvas/Canvas.hpp"
#include "threepp/math/Spherical.hpp"
#include "threepp/cameras/Camera.hpp"
#include "threepp/cameras/OrthographicCamera.hpp"
#include "threepp/cameras/PerspectiveCamera.hpp"
#include "threepp/math/Vector3.hpp"
#include "threepp/math/Vector2.hpp"
#include "threepp/input/KeyListener.hpp"
#include "threepp/input/MouseListener.hpp"
#include "threepp/math/MathUtils.hpp"
#include <cmath>

#include "TwoDControls.h"

using namespace threepp;

const float EPS = 0.000001f;
struct TwoDControls::Impl {
    State state = State::NONE;

    Canvas& canvas;
    Camera& camera;
    TwoDControls& scope;

    std::unique_ptr<KeyListener> keyListener;
    std::unique_ptr<MouseListener> mouseListener;

    float scale = 1.f;
    Vector3 panOffset;

    Vector2 panStart;
    Vector2 panEnd;
    Vector2 panDelta;

    Vector2 dollyStart;
    Vector2 dollyEnd;
    Vector2 dollyDelta;

    Vector2 rotateStart;
    Vector2 rotateDelta;
    float accumulatedRotation = 0;

    Impl(TwoDControls& scope, Canvas& canvas, Camera& camera)
        : scope(scope), canvas(canvas), camera(camera),
        keyListener(std::make_unique<MyKeyListener>(scope)),
        mouseListener(std::make_unique<MyMouseListener>(scope)) {
        canvas.addMouseListener(*mouseListener.get());
        canvas.addKeyListener(*keyListener.get());

        update();
    }

    void update() {
        Vector3 offset;

        auto& position = this->camera.position;

        offset.copy(position).sub(scope.target);

        // move target to panned location

        if (scope.enableDamping) {

            scope.target.addScaledVector(panOffset, scope.dampingFactor);

        } else {

            scope.target.add(panOffset);
        }

        offset.multiplyScalar(scale);
        position.copy(scope.target).add(offset);

        this->camera.lookAt(scope.target);

        camera.rotateZ(accumulatedRotation + rotateDelta.x * scope.rotateSpeed);

        if (scope.enableDamping) {

            panOffset.multiplyScalar(1 - scope.dampingFactor);

        } else {

            panOffset.set(0, 0, 0);
        }

        scale = 1;
    }

    void panLeft(float distance, const Matrix4& objectMatrix) {

        Vector3 v;

        v.setFromMatrixColumn(objectMatrix, 0);// get X column of objectMatrix
        v.multiplyScalar(-distance);

        panOffset.add(v);
    }

    void panUp(float distance, const Matrix4& objectMatrix) {

        Vector3 v;

        if (scope.screenSpacePanning) {

            v.setFromMatrixColumn(objectMatrix, 1);

        } else {

            v.setFromMatrixColumn(objectMatrix, 0);
            v.crossVectors(this->camera.up, v);
        }

        v.multiplyScalar(distance);

        panOffset.add(v);
    }

    void pan(float deltaX, float deltaY) {

        Vector3 offset;

        if (auto perspective = camera.as<PerspectiveCamera>()) {

            // perspective
            auto& position = this->camera.position;
            offset.copy(position).sub(scope.target);
            auto targetDistance = offset.length();

            // half of the fov is center to top of screen
            targetDistance *= std::tan((perspective->fov / 2) * math::PI / 180.f);

            // we use only clientHeight here so aspect ratio does not distort speed
            const auto size = canvas.size();
            panLeft(2 * deltaX * targetDistance / (float)size.height, *this->camera.matrix);
            panUp(2 * deltaY * targetDistance / (float)size.height, *this->camera.matrix);
        } else if (auto ortho = camera.as<OrthographicCamera>()) {

            const auto size = canvas.size();

            // orthographic
            panLeft(
                deltaX * (ortho->right - ortho->left) / this->camera.zoom / size.width,
                *this->camera.matrix);
            panUp(
                deltaY * (ortho->top - ortho->bottom) / this->camera.zoom / size.height,
                *this->camera.matrix);
        }
    }

    void dollyIn(float dollyScale) {

        if (camera.as<PerspectiveCamera>()) {

            scale /= dollyScale;

        } else if (camera.as<OrthographicCamera>()) {

            this->camera.zoom = std::max(scope.minZoom, std::min(scope.maxZoom, this->camera.zoom * dollyScale));
            this->camera.updateProjectionMatrix();
        }
    }

    void dollyOut(float dollyScale) {

        if (camera.as<PerspectiveCamera>()) {
            scale *= dollyScale;
        } else if (camera.as<OrthographicCamera>()) {
            this->camera.zoom = std::max(scope.minZoom, std::min(scope.maxZoom, this->camera.zoom / dollyScale));
            this->camera.updateProjectionMatrix();
        }
    }

    void handleMouseDownDolly(const Vector2& pos) {

        dollyStart.copy(pos);
    }

    void handleMouseDownPan(const Vector2& pos) {

        panStart.copy(pos);
    }

    void handleMouseDownRotate(const Vector2& pos) {
        rotateStart.copy(pos);
    }

    void handleMouseUpRotate(const Vector2& pos) {
        accumulatedRotation += rotateDelta.x * scope.rotateSpeed;
        rotateDelta.set(0, 0);
    }

    void handleMouseMoveDolly(const Vector2& pos) {

        dollyEnd.copy(pos);

        dollyDelta.subVectors(dollyEnd, dollyStart);

        if (dollyDelta.x > 0) {
            dollyOut(scope.getZoomScale2());
        } else if (dollyDelta.x < 0) {
            dollyIn(scope.getZoomScale2());
        }

        dollyStart.copy(dollyEnd);

        scope.update();
    }


    void handleMouseMovePan(const Vector2& pos) {

        panEnd.copy(pos);

        panDelta.subVectors(panEnd, panStart).multiplyScalar(scope.panSpeed);

        pan(panDelta.x, panDelta.y);

        panStart.copy(panEnd);

        scope.update();
    }

    void handleMouseWheel(const Vector2& delta) {
        if (delta.y < 0) {
            dollyIn(scope.getZoomScale());
        } else if (delta.y > 0) {
            dollyOut(scope.getZoomScale());
        }
        scope.update();
    }

    void handleMouseMoveRotate(const Vector2& pos) {
        rotateDelta.subVectors(pos, rotateStart);
        scope.update();
    }

    struct MyKeyListener : KeyListener {
        TwoDControls& controls;

        explicit MyKeyListener(TwoDControls& controls) : controls(controls) {}
    };

    struct MyMouseMoveListener : MouseListener {
        TwoDControls& controls;

        explicit MyMouseMoveListener(TwoDControls& controls) : controls(controls) {}

        void onMouseMove(const Vector2& pos) override {
            if (controls.enabled) {
                switch (controls.pimpl_->state) {
                case State::DOLLY:
                    controls.pimpl_->handleMouseMoveDolly(pos);
                    break;
                case State::PAN:
                    controls.pimpl_->handleMouseMovePan(pos);
                    break;
                case State::ROTATE:
                    controls.pimpl_->handleMouseMoveRotate(pos);
                    break;
                }
            }
        }
    };

    struct MyMouseUpListener : MouseListener {
        TwoDControls& scope;
        MouseListener* mouseMoveListener;

        MyMouseUpListener(TwoDControls& scope, MyMouseMoveListener* mouseMoveListener)
            : scope(scope), mouseMoveListener(mouseMoveListener) {
        }

        void onMouseUp(int button, const Vector2& pos) override {
            if (scope.enabled) {
                if (scope.pimpl_->state == State::ROTATE) {
                    scope.pimpl_->handleMouseUpRotate(pos);
                }
                scope.pimpl_->canvas.removeMouseListener(*mouseMoveListener);
                scope.pimpl_->canvas.removeMouseListener(*this);
                scope.pimpl_->state = State::NONE;
            }
        }
    };

    struct MyMouseListener : MouseListener {
        TwoDControls& scope;
        MyMouseMoveListener mouseMoveListener;
        MyMouseUpListener mouseUpListener;

        explicit MyMouseListener(TwoDControls& scope)
            : scope(scope), mouseMoveListener(scope), mouseUpListener(scope, &mouseMoveListener) {
        }

        void onMouseDown(int button, const Vector2& pos) override {
            if (scope.enabled) {
                switch (button) {
                case 0:// LEFT
                    scope.pimpl_->handleMouseDownPan(pos);
                    scope.pimpl_->state = State::PAN;
                    break;
                case 1:// RIGHT
                    scope.pimpl_->handleMouseDownPan(pos);
                    scope.pimpl_->state = State::PAN;
                    break;
                case 2:// MIDDLE
                    scope.pimpl_->handleMouseDownRotate(pos);
                    scope.pimpl_->state = State::ROTATE;
                    break;
                }
            }
            if (scope.pimpl_->state != State::NONE) {

                scope.pimpl_->canvas.addMouseListener(mouseMoveListener);
                scope.pimpl_->canvas.addMouseListener(mouseUpListener);
            }
        }

        void onMouseWheel(const Vector2& delta) override {
            if (scope.enabled && scope.pimpl_->state == State::NONE) {
                scope.pimpl_->handleMouseWheel(delta);
            }
        }
    };

};

TwoDControls::TwoDControls(Camera& camera, Canvas& canvas) : pimpl_(std::make_unique<Impl>(*this, canvas, camera)) {}

void TwoDControls::update() {
    pimpl_->update();
}

void TwoDControls::reset() {
    target.set(0, 0, 0);
    pimpl_->accumulatedRotation = 0;
}

void TwoDControls::pan(float x, float y) {
    pimpl_->panLeft(-x, *pimpl_->camera.matrix);
    pimpl_->panUp(y, *pimpl_->camera.matrix);
    update();
}

void TwoDControls::panByMouse(float x, float y) {
    pimpl_->pan(-x, -y);
    update();
}

void TwoDControls::zoomByKey(bool zoomIn) {
    if (zoomIn) {
        pimpl_->dollyOut(pimpl_->scope.getZoomScale());
    } else {
        pimpl_->dollyIn(pimpl_->scope.getZoomScale());
    }
    update();
}

float TwoDControls::getZoomScale() const {
    return std::pow(0.95f, this->zoomSpeed);
}

float TwoDControls::getZoomScale2() const {
    return std::pow(0.95f, this->zoomSpeed2);
}

TwoDControls::~TwoDControls() = default;
