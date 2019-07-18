#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QImage>
#include <vector>
#include <algorithm>
#include <cmath>
#include "MyPoint2D.h"

class BezierCurve {

private:

    /**
     * The set of points used to create a curve.
     */
    std::vector < MyPoint2D > bezierPoints;

    /**
     * Calculete coordinates for single point in curve.
     * @param t - parameter to calculate values from the range (0; 1)
     * @param startPointNumber - start point to calculate from bezierPoints vector
     * @param XorY - if true, calculate x coordinate, in other case y
     * @return
     */
    double pointOnCurve(double t, int startPointNumber, bool XorY);

public:

    BezierCurve() {}

    ~BezierCurve() {}

    std::vector < MyPoint2D > getBezierPoints() { return this->bezierPoints; }
    void setBezierPoints(std::vector < MyPoint2D > bezierPoints) {
        this->bezierPoints = bezierPoints;
    }
    void setBezierPoint(MyPoint2D point, int position) {
        this->bezierPoints[position] = point;
    }

    /**
     * Adds a point to the end of the vector.
     */
    void inline addPoint(MyPoint2D point) {
        bezierPoints.push_back(point);
    }

    /**
     * Removes the selected point from the vector.
     */
    void inline removePoint(MyPoint2D point) {
        bezierPoints.erase(std::remove(bezierPoints.begin(),
                                       bezierPoints.end(), point),
                           bezierPoints.end());
    }

    /**
     *
     * @param point - searched point
     * @param scale - determines the area in each direction from the center of the point where it look for the point
     * @return position of the point in vector, or -1 if the point is not in the vector.
     */
    int pointInSet(MyPoint2D point, int scale);

    /**
     * Draw the bezier curve, using the vector of points.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBColor - the color to use
     */
    void draw(QImage *image, int RBGColor = 0xFFFFFF);
};

#endif // BEZIERCURVE_H
