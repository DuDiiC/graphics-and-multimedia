#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <QImage>
#include <stack>

#include "MyPoint2D.h"

class FloodFill {

public:

    FloodFill() {}

    ~FloodFill() {}

    /**
     * The static method, that performs the flood filling algorithm.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param startPoint - the starting point of the algorithm
     * @param backgroundRGBColor - the border color to fill the field with.
     */
    static void floodFill(QImage *image, MyPoint2D startPoint, int fillRGBColor = 0xFFFFFF);
};

#endif // FLOODFILL_H
