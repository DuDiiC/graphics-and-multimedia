#ifndef BSPLINECURVE_H
#define BSPLINECURVE_H

#include <QImage>
#include <vector>
#include <algorithm>
#include <cmath>
#include "MyPoint2D.h"

class BSplineCurve {

private:

    /**
     * The set of points used to create a curve.
     */
    std::vector < MyPoint2D > bSplinePoints;

    /**
     * Calculete coordinates for single point in curve.
     * @param t - parameter to calculate values from the range (0; 1)
     * @param startPointNumber - start point to calculate from bSplinePoints vector
     * @param XorY - if true, calculate x coordinate, in other case y
     * @return double value of x or y coordinate for single point in curve.
     */
    double pointOnCurve(double t, int startPointNumber, bool XorY);

public:

    BSplineCurve() {}

    ~BSplineCurve() {}

    std::vector < MyPoint2D > getBSplinePoints() { return this->bSplinePoints; }
    void setBSplinePoints(std::vector < MyPoint2D > bezierPoints) {
        this->bSplinePoints = bezierPoints;
    }
    void setBSplinePoint(MyPoint2D point, int position) {
        this->bSplinePoints[position] = point;
    }

    /**
     * Adds a point to the end of the vector.
     */
    void inline addPoint(MyPoint2D point) {
        bSplinePoints.push_back(point);
    }

    /**
     * Removes the selected point from the vector.
     */
    void inline removePoint(MyPoint2D point) {
        bSplinePoints.erase(std::remove(bSplinePoints.begin(),
                                        bSplinePoints.end(), point),
                            bSplinePoints.end());
    }

    /**
     * Checks whether the point is in the vector of points.
     * @param point - searched point
     * @param scale - determines the area in each direction from the center of the point where it look for the point
     * @return position of the point in vector, or -1 if the point is not in the vector.
     */
    int pointInSet(MyPoint2D point, int scale);

    /**
     * Draw the b-spline curve, using the vector of points.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBColor - the color to use
     */
    void draw(QImage *image, int RBGColor = 0xFFFFFF);
};

#endif // BSPLINECURVE_H
