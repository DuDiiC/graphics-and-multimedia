#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QImage>
#include <cmath>
#include "MyPoint2D.h"
#include "LineSegment.h"

class Ellipse {


private:
    /**
     * The first point that is useful for creating an ellipse.
     */
    MyPoint2D firstPointOnEllipse;

    /**
     * The second point that is useful for creating an ellipse.
     */
    MyPoint2D secondPointOnEllipse;

public:

    Ellipse() {}

    Ellipse(MyPoint2D fPOE, MyPoint2D sPOE) : firstPointOnEllipse(fPOE), secondPointOnEllipse(sPOE) {}

    ~Ellipse() {}

    MyPoint2D getCenterPoint() { return this->firstPointOnEllipse; }
    void setCenterPoint(MyPoint2D centerPoint) { this->firstPointOnEllipse = centerPoint; }

    MyPoint2D getPointOnEllipse() { return this->secondPointOnEllipse; }
    void setPointOnEllipse(MyPoint2D pointOnEllipse) { this->secondPointOnEllipse = pointOnEllipse; }

    /**
     * Draws the ellipse, using the start and end point of the rectangle's diagonal, in which is entred.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBColor - the color to use
     */
    void draw(QImage *image, int RGBColor = 0xFFFFFF);
};


#endif // ELLIPSE_H
