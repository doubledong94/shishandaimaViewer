//
// Created by ydd on 10/28/23.
//

#ifndef JPARSER_RECT_H
#define JPARSER_RECT_H


class Rect {
public:
    float left;
    float top;
    float right;
    float bottom;

    Rect(float left, float bottom, float right, float top);

    void splitIntoRects(int rowCount, int columnCount, vector<Rect *> &ret, float ratioWidthToHeight);

    float area();
};


#endif //JPARSER_RECT_H
