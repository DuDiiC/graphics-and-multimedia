#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <includes/MyPoint2D.h>
#include <QImage>
#include <cmath>

class LineSegment {

private:

    /**
     * Start point of line segment.
     */
    MyPoint2D startPoint;

    /**
     * End point of line segment.
     */
    MyPoint2D endPoint;

    /**
     * a valuue from formula: f(x) = ax + b
     */
    double a;

public:

    LineSegment() {}

    LineSegment(MyPoint2D sP, MyPoint2D eP) : startPoint(sP), endPoint(eP) {
        updateA();
    }

    ~LineSegment() {}

    MyPoint2D getStartPoint() { return this->startPoint; }
    void setStartPoint(MyPoint2D startPoint) {
        this->startPoint = startPoint;
        updateA();
    }

    MyPoint2D getEndPoint() { return this->endPoint; }
    void setEndPoint(MyPoint2D endPoint) {
        this->endPoint = endPoint;
        updateA();
    }

    double getA() { return this->a; }

    /**
     * Updates the a, when start or end point will be moddified.
     */
    void updateA();

    /**
     * Draws the line segment, between startPoint and endPoint.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBColor - the color to use
     */
    void draw(QImage *image, int RGBColor = 0xFFFFFF);

    /**
     * Calculates line segment lenght.
     * @return double value of line segment lenght.
     */
    double lenght();

};

#endif // LINESEGMENT_H
