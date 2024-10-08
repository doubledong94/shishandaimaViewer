
#include "igraph.h"
#include "threepp/math/MathUtils.hpp"
#include "threepp/materials/RawShaderMaterial.hpp"
#include "threepp/core/BufferGeometry.hpp"
#include "threepp/objects/InstancedMesh.hpp"
#include "util/util.h"
#include "error/ErrorManager.h"
#include "threepp/custom/Nodes.h"

Nodes::Nodes(int capacity, float initNodeSize) :threepp::InstancedMesh(NULL, NULL, capacity) {
    nodeCapacity = capacity;
    setCount(nodeCount);
    baseNodeSize = initNodeSize;
    nodeSizes = vector<float>(capacity);
    fill(nodeSizes.begin(), nodeSizes.end(), 1);
    specifiedColors = vector<threepp::Color>(capacity);
    geometry_ = threepp::BufferGeometry::create();
    geometry_->setAttribute("position", threepp::FloatBufferAttribute::create(
        {
            -1,-1,0,
            1,-1,0,
            1,1,0,
            -1,1,0
        }, 3));
    vector<int> index = { 0,1,2,2,3,0 };
    geometry_->setIndex(index);
    shaderMaterial = threepp::RawShaderMaterial::create();
    shaderMaterial->uniforms["alphaUnselected"] = threepp::Uniform();
    shaderMaterial->uniforms["alphaSelected"] = threepp::Uniform();
    shaderMaterial->vertexShader = vertexSource();
    shaderMaterial->fragmentShader = fragmentSource();
    shaderMaterial->side = threepp::Side::Double;
    shaderMaterial->transparent = true;
    shaderMaterial->alphaTest = true;
    shaderMaterial->depthTest = false;
    materials_ = { shaderMaterial };
    instanceMatrix()->setUsage(threepp::DrawUsage::Dynamic);
    // create color attribute
    setColorAt(0, defaultColorForUnselected);
    instanceColor()->setUsage(threepp::DrawUsage::Dynamic);
}

bool Nodes::setPointPositions(const vector<threepp::Vector3>& points) {
    int oldCount = nodeCount;
    nodeCount = std::min(nodeCapacity, (int)points.size());
    for (int i = 0;i < nodeCount;i++) {
        tmpMatrix.makeScale(baseNodeSize * nodeSizes[i], baseNodeSize * nodeSizes[i], baseNodeSize * nodeSizes[i]);
        tmpMatrix.setPosition(points[i].x, points[i].y, points[i].z);
        setMatrixAt(i, tmpMatrix);
    }
    setCount(nodeCount);
    return nodeCount != oldCount;
}

void Nodes::setNodeSize() {
    for (int i = 0;i < nodeCount;i++) {
        setNodeSizeAt(i, nodeSizes[i]);
    }
}

void Nodes::setNodeSizeAt(int i, float size) {
    nodeSizes[i] = size;
    tmpMatrix.makeScale(baseNodeSize * size, baseNodeSize * size, baseNodeSize * size);
    getMatrixAt(i, tmpMatrix2);
    tmpMatrix.copyPosition(tmpMatrix2);
    setMatrixAt(i, tmpMatrix);
}

void Nodes::matrixNeedUpdate() {
    instanceMatrix()->needsUpdate();
}

void Nodes::setCameraDir(const threepp::Vector3& cameraDir) {
    for (int i = 0;i < nodeCount;i++) {
        setCameraDirAti(i, cameraDir);
    }
}

void Nodes::setCameraDirAti(int i, const threepp::Vector3& cameraDir) {
    getMatrixAt(i, tmpMatrix);
    tmpMatrix.lookAt({ 0,0,0 }, cameraDir, { 1,1,1 });
    tmpMatrix.scale({ baseNodeSize * nodeSizes[i],baseNodeSize * nodeSizes[i],baseNodeSize * nodeSizes[i] });
    setMatrixAt(i, tmpMatrix);
}

void Nodes::increaseNodeSize() {
    baseNodeSize *= 1.1f;
    setNodeSize();
    matrixNeedUpdate();
}

void Nodes::decreaseNodeSize() {
    baseNodeSize /= 1.1f;
    setNodeSize();
    matrixNeedUpdate();
}

void Nodes::applyColor() {
    for (int i = 0;i < nodeCount;i++) {
        setColorAt(i, defaultColorForUnselected);
    }
    for (int i : selected) {
        setColorAt(i, defaultColorForSelected);
    }
    // overide default color if specified
    for (int i : colorSpecified) {
        setColorAt(i, specifiedColors[i]);
    }
    // mark as selected
    threepp::Color encodedColor;
    for (int i : selected) {
        getColorAt(i, encodedColor);
        encodedColor.r = encodeIntoRgb(encodedColor.r, 0.2);
        setColorAt(i, encodedColor);
    }
    // mark as hovered
    for (int i : hovered) {
        getColorAt(i, encodedColor);
        encodedColor.g = encodeIntoRgb(encodedColor.g, 0.2);
        setColorAt(i, encodedColor);
    }
    // mark as fixed position
    for (int i : positionFixed) {
        getColorAt(i, encodedColor);
        encodedColor.b = encodeIntoRgb(encodedColor.b, 0.2);
        setColorAt(i, encodedColor);
    }
    // mark as styled
    for (int i : styled) {
        getColorAt(i, encodedColor);
        encodedColor.r = encodeIntoRgb(encodedColor.r, 0.002);
        setColorAt(i, encodedColor);
    }
    for (int i : styled2) {
        getColorAt(i, encodedColor);
        encodedColor.r = encodeIntoRgb(encodedColor.r, 0.004);
        setColorAt(i, encodedColor);
    }
    for (int i : styled3) {
        getColorAt(i, encodedColor);
        encodedColor.r = encodeIntoRgb(encodedColor.r, 0.006);
        setColorAt(i, encodedColor);
    }
    for (int i : styled4) {
        getColorAt(i, encodedColor);
        encodedColor.r = encodeIntoRgb(encodedColor.r, 0.008);
        setColorAt(i, encodedColor);
    }
    for (int i : styled5) {
        getColorAt(i, encodedColor);
        encodedColor.g = encodeIntoRgb(encodedColor.g, 0.002);
        setColorAt(i, encodedColor);
    }
    for (int i : styled6) {
        getColorAt(i, encodedColor);
        encodedColor.g = encodeIntoRgb(encodedColor.g, 0.004);
        setColorAt(i, encodedColor);
    }
    for (int i : styled7) {
        getColorAt(i, encodedColor);
        encodedColor.b = encodeIntoRgb(encodedColor.b, 0.002);
        setColorAt(i, encodedColor);
    }
    for (int i : styled8) {
        getColorAt(i, encodedColor);
        encodedColor.b = encodeIntoRgb(encodedColor.b, 0.004);
        setColorAt(i, encodedColor);
    }
    instanceColor()->needsUpdate();
}

void Nodes::getColors(vector<threepp::Color>& colors) {
    colors.clear();
    for (int i = 0;i < nodeCount;i++) {
        threepp::Color c;
        getColorAt(i, c);
        colors.push_back(c);
    }
}

float Nodes::encodeIntoRgb(float rgb, float info) {
    return rgb + info / 100;
}

void Nodes::updateAlphaUnselected(float alpha) {
    shaderMaterial->uniforms.at("alphaUnselected").setValue(alpha);
}

void Nodes::updateAlphaSelected(float alpha) {
    shaderMaterial->uniforms.at("alphaSelected").setValue(alpha);
}

std::shared_ptr<Nodes> Nodes::create(int capacity, float initNodeSize) {
    return std::shared_ptr<Nodes>(new Nodes(capacity, initNodeSize));
}

void Nodes::setSpecifiedColorAt(int index, const threepp::Color& color, bool overwrite) {
    index = std::min(nodeCapacity - 1, index);
    if (colorSpecified.count(index) and not overwrite) {
        return;
    }
    threepp::Color color2;
    color2.copy(color);
    color2.r = int(color2.r * 100) / 100.0f;
    color2.g = int(color2.g * 100) / 100.0f;
    color2.b = int(color2.b * 100) / 100.0f;
    colorSpecified.insert(index);
    specifiedColors[index].copy(color2);
}

void Nodes::mapNodeForDeletion(igraph_vector_int_t* mapForDeleteNodes) {
    set<int> oldColorSpecified;
    oldColorSpecified.insert(colorSpecified.begin(), colorSpecified.end());
    vector<threepp::Color> oldSpecifiedColors = specifiedColors;
    set<int> oldPositionFixed = positionFixed;
    vector<float> oldNodeSizes = nodeSizes;
    colorSpecified.clear();
    positionFixed.clear();
    for (int i = 0; i < igraph_vector_int_size(mapForDeleteNodes); ++i) {
        int oldIndex = VECTOR(*mapForDeleteNodes)[i];
        if (oldColorSpecified.count(oldIndex)) {
            colorSpecified.insert(i);
            specifiedColors[i].copy(oldSpecifiedColors[oldIndex]);
        }
        if (oldPositionFixed.count(oldIndex)) {
            positionFixed.insert(i);
        }
        nodeSizes[i] = oldNodeSizes[oldIndex];
    }
}

void Nodes::toFile(ofstream& f) {
    f << positionFixed.size() << "\n";
    for (int i : positionFixed) {
        f << i << "\n";
    }
    f << colorSpecified.size() << "\n";
    for (int i : colorSpecified) {
        f << i << "\n";
    }
    f << specifiedColors.size() << "\n";
    for (auto& c : specifiedColors) {
        f << c.r << "\n";
        f << c.g << "\n";
        f << c.b << "\n";
    }
}

void Nodes::fromFile(ifstream& f) {
    positionFixed.clear();
    colorSpecified.clear();
    specifiedColors.clear();
    int positionFixedSize = getInt(f);
    for (int i = 0;i < positionFixedSize;i++) {
        positionFixed.insert(getInt(f));
    }
    int colorSpecifiedSize = getInt(f);
    for (int i = 0;i < colorSpecifiedSize;i++) {
        colorSpecified.insert(getInt(f));
    }
    int colorCount = getInt(f);
    for (int i = 0;i < colorCount;i++) {
        float r = getFloat(f);
        float g = getFloat(f);
        float b = getFloat(f);
        specifiedColors.push_back({ r,g,b });
    }
}

std::string Nodes::vertexSource() {
    return R"(
               #version 330 core
               uniform mat4 modelViewMatrix; 
               uniform mat4 projectionMatrix; 
               uniform float alphaUnselected;
               uniform float alphaSelected;
               in vec3 position;
	           in mat4 instanceMatrix;
               in vec3 instanceColor;
               out vec2 uv_frag;
               out vec3 vColor;
               out float vAlpha;
               out float vHovered;
               out float vFixed;
               out float vStyled;
               out float vStyled2;
               out float vStyled3;
               out float vStyled4;
               out float vStyled5;
               out float vStyled6;
               out float vStyled7;
               out float vStyled8;
               void main() {
                    uv_frag = position.xy;
                    vColor = instanceColor;

                    float statePartR = fract(fract(instanceColor.r) * 100);
                    bool selected = statePartR > 0.1 && statePartR < 0.3;
                    vAlpha = selected ? alphaSelected : alphaUnselected;

                    float statePartG = fract(fract(instanceColor.g) * 100);
                    vHovered = statePartG > 0.1 && statePartG < 0.3 ? 1 : 0;

                    float statePartB = fract(fract(instanceColor.b) * 100);
                    vFixed = statePartB > 0.1 && statePartB < 0.3 ? 1 : 0;

                    float statePartStyle = fract(fract(fract(instanceColor.r) * 100) * 100);
                    vStyled = statePartStyle > 0.1 && statePartStyle < 0.3 ? 1 : 0;
                    vStyled2 = statePartStyle > 0.3 && statePartStyle < 0.5 ? 1 : 0;
                    vStyled3 = statePartStyle > 0.5 && statePartStyle < 0.7 ? 1 : 0;
                    vStyled4 = statePartStyle > 0.7 && statePartStyle < 0.9 ? 1 : 0;
                    float statePartStyleG = fract(fract(fract(instanceColor.g) * 100) * 100);
                    vStyled5 = statePartStyleG > 0.1 && statePartStyleG < 0.3 ? 1 : 0;
                    vStyled6 = statePartStyleG > 0.3 && statePartStyleG < 0.5 ? 1 : 0;
                    float statePartStyleB = fract(fract(fract(instanceColor.b) * 100) * 100);
                    vStyled7 = statePartStyleB > 0.1 && statePartStyleB < 0.3 ? 1 : 0;
                    vStyled8 = statePartStyleB > 0.3 && statePartStyleB < 0.5 ? 1 : 0;

                    gl_Position = projectionMatrix * modelViewMatrix * instanceMatrix * vec4( position, 1.0 );
               })";
}

std::string Nodes::fragmentSource() {
    return R"(
                #version 330 core
                in vec3 vColor;
                in vec2 uv_frag;
                in float vAlpha;
                in float vHovered;
                in float vFixed;
                in float vStyled;
                in float vStyled2;
                in float vStyled3;
                in float vStyled4;
                in float vStyled5;
                in float vStyled6;
                in float vStyled7;
                in float vStyled8;
                out vec4 pc_fragColor;
                void main() {
                    vec3 color = vColor;
                    float alpha = vAlpha;
                    if (vHovered > 0.5){
                        color += vec3(0.2);
                        alpha += 0.2;
                    }
                    if (vFixed < 0.5 || (abs(uv_frag.x) < 0.9 && abs(uv_frag.y) < 0.9)){
                        float l = length(uv_frag);
                        if (vStyled8>0.5 && l<0.5){
                            alpha = 0;
                        } else if (vStyled5>0.5 && (uv_frag.y>0 && uv_frag.y<0.7 && uv_frag.x>0.0 && uv_frag.x<0.7)) {

                        } else if (l>0.7){
                            alpha = 0;
                        } else {
                            if (vStyled > 0.5) {
                                if (l> 0.6) {
                                } else if (l> 0.5) {
                                    color -= vec3(0.3);
                                }
                            }
                            if (vStyled7 > 0.5) {
                                if (l < 0.3) {
                                    color -= vec3(0.3);
                                }
                            }
                            if (vStyled6 > 0.5) {
                                if (l > 0.6) {
                                    color += vec3(0.3);
                                }
                            }
                            if (vStyled4 > 0.5) {
                                if (abs(uv_frag.x)<0.15) {
                                    color -= vec3(0.3);
                                } else if (abs(uv_frag.y)<0.15){
                                    color -= vec3(0.3);
                                }
                            }
                            if (vStyled3 > 0.5) {
                                if (l> 0.6) {
                                } else if (l> 0.5) {
                                    color -= vec3(0.3);
                                } else if (l> 0.4) {
                                } else if (l> 0.3) {
                                    color -= vec3(0.3);
                                } else if (l> 0.2) {
                                } else if (l> 0.1) {
                                    color -= vec3(0.3);
                                }
                            }
                            if (vStyled2 > 0.5) {
                                if (uv_frag.y> 0.6) {
                                } else if (uv_frag.y> 0.5) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.y> 0.3) {
                                } else if (uv_frag.y> 0.2) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.y> 0.0) {
                                } else if (uv_frag.y> -0.1) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.y> -0.3) {
                                } else if (uv_frag.y> -0.4) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.y> -0.6) {
                                } else if (uv_frag.y> -0.7) {
                                    color -= vec3(0.3);
                                }

                                if (uv_frag.x> 0.6) {
                                } else if (uv_frag.x> 0.5) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.x> 0.3) {
                                } else if (uv_frag.x> 0.2) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.x> 0.0) {
                                } else if (uv_frag.x> -0.1) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.x> -0.3) {
                                } else if (uv_frag.x> -0.4) {
                                    color -= vec3(0.3);
                                } else if (uv_frag.x> -0.6) {
                                } else if (uv_frag.x> -0.7) {
                                    color -= vec3(0.3);
                                }
                            }
                        }
                    }
                    pc_fragColor = vec4( color, alpha );
                })";
}

