#include "threepp/threepp.hpp"
#include "threepp/materials/SpriteMaterial.hpp"
#include "threepp/objects/Sprite.hpp"
#include "threepp/objects/LineSegments.hpp"
#include "threepp/materials/LineBasicMaterial.hpp"
#include "threepp/loaders/TextureLoader.hpp"
#include "util/util.h"
#include "igraph.h"
#include "threepp/custom/BoundFrame.h"
#include "file/FileManager.h"

using namespace threepp;

std::shared_ptr<threepp::Texture> BoundFrame::dragTexture = NULL;
std::shared_ptr<threepp::Texture> BoundFrame::resizeTexture = NULL;

BoundFrame::BoundFrame() {
    if (not resizeTexture) {
        TextureLoader loader;
        resizeTexture = loader.load(FileManager::boundFrameResizeIconPath, true);
    }
    if (not dragTexture) {
        TextureLoader loader;
        dragTexture = loader.load(FileManager::boundFrameDragIconPath, false);
    }
    start = { 0,0,0 };
    if (is2D) {
        end = { 10,-10,0 };
    } else {
        end = { 10,-10,10 };
    }
    auto dragMaterial = SpriteMaterial::create();
    dragMaterial->map = dragTexture;
    dragMaterial->map->offset.set(0.5, 0.5);
    dragIcon = Sprite::create(dragMaterial);

    auto resizeMatrial = SpriteMaterial::create();
    resizeMatrial->map = resizeTexture;
    resizeMatrial->map->offset.set(0.5, 0.5);
    resizeIcon = Sprite::create(resizeMatrial);
    add(dragIcon);
    add(resizeIcon);

    auto lineMat = LineBasicMaterial::create({ {"color", Color::white} });
    lineMat->side = threepp::Side::Double;
    frameGeo = BufferGeometry::create();
    frameGeo->setAttribute("position", threepp::FloatBufferAttribute::create(std::vector<float>(12 * 12), 3));
    frameGeo->getAttribute<float>("position")->setUsage(threepp::DrawUsage::Dynamic);
    frameGeo->setDrawRange(0, 4 * 6);
    frame = LineSegments::create(frameGeo, lineMat);
    add(frame);
    applyPosAndSize();
    scaleIcon();
}

void BoundFrame::clearFrame() {
    frameGeo->setDrawRange(0, 0);
}

void BoundFrame::applyPosAndSize() {
    dragIcon->position.x = start.x;
    dragIcon->position.y = start.y;
    if (is2D) {
        dragIcon->position.z = 0;
    } else {
        dragIcon->position.z = start.z;
    }
    resizeIcon->position.x = end.x;
    resizeIcon->position.y = end.y;
    if (is2D) {
        resizeIcon->position.z = 0;
    } else {
        resizeIcon->position.z = end.z;
    }
    auto positionAttr = frameGeo->getAttribute<float>("position");
    if (is2D) {
        positionAttr->setXYZ(0, start.x, start.y, 0);
        positionAttr->setXYZ(1, start.x, end.y, 0);
        positionAttr->setXYZ(2, start.x, end.y, 0);
        positionAttr->setXYZ(3, end.x, end.y, 0);
        positionAttr->setXYZ(4, end.x, end.y, 0);
        positionAttr->setXYZ(5, end.x, start.y, 0);
        positionAttr->setXYZ(6, end.x, start.y, 0);
        positionAttr->setXYZ(7, start.x, start.y, 0);
    } else {
        positionAttr->setXYZ(0, start.x, start.y, start.z);
        positionAttr->setXYZ(1, end.x, start.y, start.z);
        positionAttr->setXYZ(2, start.x, start.y, start.z);
        positionAttr->setXYZ(3, start.x, end.y, start.z);
        positionAttr->setXYZ(4, start.x, start.y, start.z);
        positionAttr->setXYZ(5, start.x, start.y, end.z);
        positionAttr->setXYZ(6, end.x, end.y, end.z);
        positionAttr->setXYZ(7, start.x, end.y, end.z);
        positionAttr->setXYZ(8, end.x, end.y, end.z);
        positionAttr->setXYZ(9, end.x, start.y, end.z);
        positionAttr->setXYZ(10, end.x, end.y, end.z);
        positionAttr->setXYZ(11, end.x, end.y, start.z);
        positionAttr->setXYZ(12, end.x, start.y, start.z);
        positionAttr->setXYZ(13, end.x, start.y, end.z);
        positionAttr->setXYZ(14, end.x, start.y, start.z);
        positionAttr->setXYZ(15, end.x, end.y, start.z);
        positionAttr->setXYZ(16, start.x, end.y, start.z);
        positionAttr->setXYZ(17, start.x, end.y, end.z);
        positionAttr->setXYZ(18, start.x, end.y, start.z);
        positionAttr->setXYZ(19, end.x, end.y, start.z);
        positionAttr->setXYZ(20, start.x, start.y, end.z);
        positionAttr->setXYZ(21, start.x, end.y, end.z);
        positionAttr->setXYZ(22, start.x, start.y, end.z);
        positionAttr->setXYZ(23, end.x, start.y, end.z);
    }
    positionAttr->needsUpdate();
    frameGeo->computeBoundingBox();
    frameGeo->computeBoundingSphere();
}

void BoundFrame::onDrag(float deltaX, float deltaY, float deltaZ) {
    if (raycastOnDrag) {
        offset(deltaX, deltaY, deltaZ);
    } else {
        resize(deltaX, deltaY, deltaZ);
    }
}

void BoundFrame::offset(float dx, float dy, float dz) {
    start.add({ dx, dy, dz });
    end.add({ dx, dy, dz });
    applyPosAndSize();
}

void BoundFrame::resize(float dx, float dy, float dz) {
    end.add({ dx, dy, dz });
    applyPosAndSize();
    scaleIcon();
}

void BoundFrame::scaleIcon() {
    threepp::Vector3 squareOrCube;
    squareOrCube.subVectors(end, start);
    squareOrCube.divideScalar(6);
    if (is2D) {
        scaleIcon(max(abs(squareOrCube.x), abs(squareOrCube.y)));
    } else {
        scaleIcon(max(max(abs(squareOrCube.x), abs(squareOrCube.y)), abs(squareOrCube.z)));
    }
}

void BoundFrame::scaleIcon(float iconSize) {
    iconSize *= 0.7;
    dragIcon->scale = { iconSize,iconSize,iconSize };
    float resizeSize = iconSize * 0.7;
    resizeIcon->scale = { resizeSize,resizeSize,resizeSize };
}

void BoundFrame::setDim(bool is2D) {
    if (is2D) {
        start.z = 0;
        end.z = 0;
        frameGeo->setDrawRange(0, 4 * 6);
    } else {
        start.z = 0;
        end.z = (abs(end.x - start.x) + abs(end.y - end.y)) / 2;
        frameGeo->setDrawRange(0, 12 * 6);
    }
    if (not (is2D ^ this->is2D)) {
        return;
    }
    this->is2D = is2D;
    applyPosAndSize();
}

void BoundFrame::raycast(const threepp::Raycaster& raycaster, std::vector<threepp::Intersection>& intersects) {
    dragIcon->raycast(raycaster, intersects);
    raycastOnDrag = not intersects.empty();
    resizeIcon->raycast(raycaster, intersects);
}

std::shared_ptr<BoundFrame> BoundFrame::create() {
    return std::shared_ptr<BoundFrame>(new BoundFrame());
}

