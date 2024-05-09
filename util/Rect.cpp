//
// Created by ydd on 10/28/23.
//

#include "util.h"
#include "Rect.h"

Rect::Rect(float left, float bottom, float right, float top) {
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
}

void Rect::splitIntoRects(int rowCount, int columnCount, vector<Rect *> &ret, float ratioWidthToHeight) {
    float cellHeight = (top - bottom) / rowCount;
    float cellWidth = cellHeight * ratioWidthToHeight;
    float offsetX = (cellWidth * columnCount - (right - left)) / 2;
    for (int row = rowCount - 1; row > -1; row--) {
        for (int column = 0; column < columnCount; ++column) {
            ret.push_back(new Rect(left + column * cellWidth - offsetX, bottom + row * cellHeight, left + (column + 1) * cellWidth - offsetX, bottom + (row + 1) * cellHeight));
        }
    }
}

float Rect::area() {
    return (top - bottom) * (right - left);
}
