#include "threepp/math/MathUtils.hpp"
#include "threepp/math/Vector3.hpp"

#include <limits>
#include <memory>

#include "ThreeDControls.h"

#include "threepp/input/PeripheralsEventSource.hpp"

#include "threepp/cameras/OrthographicCamera.hpp"
#include "threepp/cameras/PerspectiveCamera.hpp"

#include <cmath>
#include <iostream>

using namespace threepp;

namespace {

    const float EPS = 0.000001f;

    enum State {

        NONE,
        ROTATE,
        DOLLY,
        PAN,
        ROTATEZ,

    };


}// namespace

struct ThreeDControls::Impl {

    PeripheralsEventSource& canvas;
    ThreeDControls& scope;
    Camera& camera;

    std::unique_ptr<KeyListener> keyListener;
    std::unique_ptr<MouseListener> mouseListener;

    State state = State::NONE;

    float scale = 1.f;
    Vector3 panOffset;

    Vector2 rotateStart;
    Vector2 rotateEnd;
    Vector2 rotateDelta;

    Vector2 rotateZStart;
    Vector2 rotateZEnd;
    Vector2 rotateZDelta;

    Vector2 panStart;
    Vector2 panEnd;
    Vector2 panDelta;

    Vector2 dollyStart;
    Vector2 dollyEnd;
    Vector2 dollyDelta;

    Impl(ThreeDControls& scope, PeripheralsEventSource& canvas, Camera& camera)
        : scope(scope), canvas(canvas), camera(camera),
        keyListener(std::make_unique<MyKeyListener>(scope)),
        mouseListener(std::make_unique<MyMouseListener>(scope)) {

        canvas.addMouseListener(*mouseListener);
        canvas.addKeyListener(*keyListener);

        update();
    }

    bool update() {

        Vector3 offset;

        auto& position = this->camera.position;

        offset.copy(position).sub(scope.target);

        Vector3 axis;
        Matrix4 mat;
        Vector3 eyeDirection;
        Vector3 objectUpDirection;
        Vector3 objectSidewaysDirection;
        Vector3 moveDirection;

        moveDirection.set(rotateDelta.x, rotateDelta.y, 0);
        float angle = moveDirection.length();
        if (angle) {
            eyeDirection.copy(offset).normalize();
            objectUpDirection.copy(this->camera.up).normalize();
            objectSidewaysDirection.crossVectors(objectUpDirection, eyeDirection).normalize();
            objectUpDirection.setLength(-rotateDelta.y);
            objectSidewaysDirection.setLength(rotateDelta.x);
            moveDirection.copy(objectUpDirection.add(objectSidewaysDirection));
            axis.crossVectors(moveDirection, offset).normalize();
            mat.makeRotationAxis(axis, angle);
            offset.applyMatrix4(mat);
            this->camera.up.applyMatrix4(mat);
        }

        // move target to panned location

        scope.target.add(panOffset);

        offset.multiplyScalar(scale);
        position.copy(scope.target).add(offset);

        this->camera.lookAt(scope.target);
        if (rotateZDelta.x) {
            camera.getWorldDirection(axis);
            mat.makeRotationAxis(axis, -rotateZDelta.x);
            this->camera.up.applyMatrix4(mat);
        }

        if (scope.enableDamping and not scope.dragging) {
            rotateDelta.multiplyScalar(1 - scope.dampingFactor);
            rotateZDelta.multiplyScalar(1 - scope.dampingFactor);

        } else {
            rotateDelta.set(0, 0);
            rotateZDelta.set(0, 0);
        }
        panOffset.set(0, 0, 0);

        scale = 1;

        return false;
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

        } else {

            // camera neither orthographic nor perspective
            std::cerr << "[ThreeDControls] encountered an unknown camera type - pan disabled." << std::endl;
            scope.enablePan = false;
        }
    }

    void dollyIn(float dollyScale) {

        if (camera.as<PerspectiveCamera>()) {

            scale /= dollyScale;

        } else if (camera.as<OrthographicCamera>()) {

            this->camera.zoom = std::max(scope.minZoom, std::min(scope.maxZoom, this->camera.zoom * dollyScale));
            this->camera.updateProjectionMatrix();
        } else {

            std::cerr << "[OrbotControls] encountered an unknown camera type - dolly/zoom disabled." << std::endl;
            scope.enableZoom = false;
        }
    }

    void dollyOut(float dollyScale) {

        if (camera.as<PerspectiveCamera>()) {
            scale *= dollyScale;
        } else if (camera.as<OrthographicCamera>()) {
            this->camera.zoom = std::max(scope.minZoom, std::min(scope.maxZoom, this->camera.zoom / dollyScale));
            this->camera.updateProjectionMatrix();
        } else {
            std::cerr << "[OrbotControls] encountered an unknown camera type - dolly/zoom disabled." << std::endl;
            scope.enableZoom = false;
        }
    }


    void handleKeyDown(Key key) {

        bool needsUpdate = not scope.enableDamping;

        switch (key) {

        case Key::UP:
            pan(0, scope.keyPanSpeed);
            break;
        case Key::DOWN:
            pan(0, -scope.keyPanSpeed);
            break;
        case Key::LEFT:
            pan(scope.keyPanSpeed, 0);
            break;
        case Key::RIGHT:
            pan(-scope.keyPanSpeed, 0);
            break;
        default:
            needsUpdate = false;
            break;
        }

        if (needsUpdate) {
            scope.update();
        }
    }

    void handleMouseDownRotate(const Vector2& pos) {

        rotateStart.copy(pos);
    }

    void handleMouseDownRotateZ(const Vector2& pos) {
        rotateZStart.copy(pos);
    }

    void handleMouseDownDolly(const Vector2& pos) {

        dollyStart.copy(pos);
    }

    void handleMouseDownPan(const Vector2& pos) {

        panStart.copy(pos);
    }

    void handleMouseMoveRotate(const Vector2& pos) {

        rotateEnd.copy(pos);

        rotateDelta.subVectors(rotateEnd, rotateStart).multiplyScalar(scope.rotateSpeed);

        const auto size = canvas.size();

        rotateDelta.multiplyScalar(30 / static_cast<float>(size.height));

        rotateStart.copy(rotateEnd);

        if (not scope.enableDamping) {
            scope.update();
        }
    }

    void handleMouseMoveRotateZ(const Vector2& pos) {
        rotateZEnd.copy(pos);

        rotateZDelta.subVectors(rotateZEnd, rotateZStart).multiplyScalar(scope.rotateSpeed);

        const auto size = canvas.size();

        rotateZDelta.multiplyScalar(30 / static_cast<float>(size.height));

        rotateZStart.copy(rotateZEnd);

        if (not scope.enableDamping) {
            scope.update();
        }
    }

    void handleMouseMoveDolly(const Vector2& pos) {

        dollyEnd.copy(pos);

        dollyDelta.subVectors(dollyEnd, dollyStart);

        if (dollyDelta.y > 0) {

            dollyIn(scope.getZoomScale());

        } else if (dollyDelta.y < 0) {

            dollyOut(scope.getZoomScale());
        }

        dollyStart.copy(dollyEnd);

        if (not scope.enableDamping) {
            scope.update();
        }
    }


    void handleMouseMovePan(const Vector2& pos) {

        panEnd.copy(pos);

        panDelta.subVectors(panEnd, panStart).multiplyScalar(scope.panSpeed);

        pan(panDelta.x, panDelta.y);

        panStart.copy(panEnd);

        if (not scope.enableDamping) {
            scope.update();
        }
    }

    void handleMouseWheel(const Vector2& delta) {
        if (delta.y < 0) {

            dollyIn(scope.getZoomScale());

        } else if (delta.y > 0) {

            dollyOut(scope.getZoomScale());
        }

        if (not scope.enableDamping) {
            scope.update();
        }
    }

    ~Impl() {

        canvas.removeMouseListener(*mouseListener);
        canvas.removeKeyListener(*keyListener);
    }

    struct MyKeyListener : KeyListener {

        ThreeDControls& controls;

        explicit MyKeyListener(ThreeDControls& controls)
            : controls(controls) {
        }

        void onKeyPressed(KeyEvent evt) override {
            if (controls.enabled && controls.enableKeys && controls.enablePan) {
                controls.pimpl_->handleKeyDown(evt.key);
            }
        }

        void onKeyRepeat(KeyEvent evt) override {
            if (controls.enabled && controls.enableKeys && controls.enablePan) {
                controls.pimpl_->handleKeyDown(evt.key);
            }
        }
    };

    struct MyMouseMoveListener : MouseListener {

        ThreeDControls& controls;

        explicit MyMouseMoveListener(ThreeDControls& controls) : controls(controls) {}

        void onMouseMove(const Vector2& pos) override {
            if (controls.enabled) {

                switch (controls.pimpl_->state) {
                case State::ROTATE:
                    if (controls.enableRotate) {
                        controls.pimpl_->handleMouseMoveRotate(pos);
                    }
                    break;
                case State::DOLLY:
                    if (controls.enableZoom) {
                        controls.pimpl_->handleMouseMoveDolly(pos);
                    }
                    break;
                case State::PAN:
                    if (controls.enablePan) {
                        controls.pimpl_->handleMouseMovePan(pos);
                    }
                    break;
                case State::ROTATEZ:
                    controls.pimpl_->handleMouseMoveRotateZ(pos);
                    break;
                default:
                    //TODO ?
                    break;
                }
            }
        }
    };


    struct MyMouseUpListener : MouseListener {

        ThreeDControls& scope;
        MouseListener* mouseMoveListener;

        MyMouseUpListener(ThreeDControls& scope, MyMouseMoveListener* mouseMoveListener)
            : scope(scope), mouseMoveListener(mouseMoveListener) {
        }

        void onMouseUp(int button, const Vector2& pos) override {
            if (scope.enabled) {

                scope.pimpl_->canvas.removeMouseListener(*mouseMoveListener);
                scope.pimpl_->canvas.removeMouseListener(*this);
                scope.pimpl_->state = State::NONE;
            }
        }
    };

    struct MyMouseListener : MouseListener {

        ThreeDControls& scope;
        MyMouseMoveListener mouseMoveListener;
        MyMouseUpListener mouseUpListener;

        explicit MyMouseListener(ThreeDControls& scope)
            : scope(scope), mouseMoveListener(scope), mouseUpListener(scope, &mouseMoveListener) {
        }

        void onMouseUp(int button, const Vector2& pos) override {
            scope.dragging = false;
        }

        void onMouseDown(int button, const Vector2& pos) override {
            scope.dragging = true;
            if (scope.enabled) {
                switch (button) {
                case 0:// LEFT
                    if (scope.enableRotate) {
                        scope.pimpl_->handleMouseDownRotate(pos);
                        scope.pimpl_->state = State::ROTATE;
                    }
                    break;
                case 1:// RIGHT
                    if (scope.enablePan) {
                        scope.pimpl_->handleMouseDownRotate(pos);
                        scope.pimpl_->handleMouseDownPan(pos);
                        scope.pimpl_->state = State::PAN;
                    }
                    break;
                case 2:// MIDDLE
                    if (scope.enableZoom) {
                        scope.pimpl_->handleMouseDownRotateZ(pos);
                        scope.pimpl_->state = State::ROTATEZ;
                    }
                    break;
                }
            }

            if (scope.pimpl_->state != State::NONE) {

                scope.pimpl_->canvas.addMouseListener(mouseMoveListener);
                scope.pimpl_->canvas.addMouseListener(mouseUpListener);
            }
        }

        void onMouseWheel(const Vector2& delta) override {
            if (scope.enabled && scope.enableZoom && !(scope.pimpl_->state != State::NONE && scope.pimpl_->state != State::ROTATE)) {
                scope.pimpl_->handleMouseWheel(delta);
            }
        }
    };
};

ThreeDControls::ThreeDControls(Camera& camera, PeripheralsEventSource& eventSource)
    : pimpl_(std::make_unique<Impl>(*this, eventSource, camera)) {
}


bool ThreeDControls::update() {

    return pimpl_->update();
}

void threepp::ThreeDControls::reset() {
    target.set(0, 0, 0);
    pimpl_->rotateDelta.set(0, 0);
    pimpl_->rotateZDelta.set(0, 0);
}

float ThreeDControls::getAutoRotationAngle() const {

    return 2 * math::PI / 60 / 60 * this->autoRotateSpeed;
}

float ThreeDControls::getZoomScale() const {

    return std::pow(0.95f, this->zoomSpeed);
}

ThreeDControls::~ThreeDControls() = default;
