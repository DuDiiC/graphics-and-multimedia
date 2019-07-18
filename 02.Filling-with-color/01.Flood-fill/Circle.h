#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <QImage>
#include "MyPoint2D.h"
#include "LineSegment.h"

class Circle {

private:

    /**
     * The point in center of circle.
     */
    MyPoint2D centerPoint;

    /**
     * Some point on circle.
     */
    MyPoint2D pointOnCircle;

    /**
     * Circle's radius.
     */
    LineSegment radius;

    /**
     * Updates the radius, when centerPoint or pointOnCircle will be modified.
     */
    void updateRadius();

    /**
     * Draws eight symetric points based on coordinates of given point.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param point - point to create seven other
     * @param RGBColor - the color to use
     */
    void draw8SymetricPixels(QImage *image, MyPoint2D point, int RGBColor = 0xFFFFFF);

public:

    Circle() {}

    Circle(MyPoint2D cP, MyPoint2D pOC) : centerPoint(cP), pointOnCircle(pOC) {
        updateRadius();
    }

    ~Circle() {}

    MyPoint2D getCenterPoint() { return this->centerPoint; }
    void setCenterPoint(MyPoint2D centerPoint) {
        this->centerPoint = centerPoint;
        updateRadius();
    }

    MyPoint2D getPointOnCircle() { return this->pointOnCircle; }
    void setPointOnCircle(MyPoint2D pointOnCircle) {
        this->pointOnCircle = pointOnCircle;
        updateRadius();
    }

    /**
     * Draw the circle, based on given points and radius.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBColor  - the color to use
     */
    void draw(QImage *image, int RGBColor = 0xFFFFFF);

    /**
     * Calculate radius lenght.
     * @return double value of radius lenght.
     */
    double radiusLenght();
};

#endif // CIRCLE_H
