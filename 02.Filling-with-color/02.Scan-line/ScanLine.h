#ifndef SCANLINE_H
#define SCANLINE_H

#include <QImage>
#include <vector>
#include "MyPoint2D.h"
#include "LineSegment.h"

#include "MyPoint2D.h"

class ScanLine {

public:

    ScanLine() {}

    ~ScanLine() {}

    /**
     * The static method, that performs the scan line algorithm.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param startPoint - the starting point of the algorithm
     * @param backgroundRGBColor - the border color to fill the field with.
     */
    static void scanLine(QImage *image, int fillRGBColor = 0xFFFFFF);
};

#endif // SCANLINE_h
