#include "BezierCurve.h"

int BezierCurve::pointInSet(MyPoint2D point, int scale) {

    for(int i = 0; i < bezierPoints.size(); i++) {
        if(point.isInArea(bezierPoints[i], scale)) {
            return i;
        }
    }
    return -1;
}

void BezierCurve::draw(QImage *image, int RBGColor) {

    if(this->bezierPoints.size() > 3) {
        MyPoint2D tempPoint;
        for(int i = 0; i < bezierPoints.size()-3; i+=3) {
            for(double t = 0.0; t < 1.0; t += 0.0005) {
                tempPoint.setX((int)pointOnCurve(t, i, 1));
                tempPoint.setY((int)pointOnCurve(t, i, 0));
                tempPoint.setPixel(image);
            }
        }
    }
}

double BezierCurve::pointOnCurve(double t, int startPointNumber, bool XorY) {

    double P0, P1, P2, P3;

    if(XorY) { // if true it's X
        P0 = (double)bezierPoints[startPointNumber].getX();
        P1 = (double)bezierPoints[startPointNumber+1].getX();
        P2 = (double)bezierPoints[startPointNumber+2].getX();
        P3 = (double)bezierPoints[startPointNumber+3].getX();
    } else { // if false it's Y
        P0 = (double)bezierPoints[startPointNumber].getY();
        P1 = (double)bezierPoints[startPointNumber+1].getY();
        P2 = (double)bezierPoints[startPointNumber+2].getY();
        P3 = (double)bezierPoints[startPointNumber+3].getY();
    }

    return pow((1-t), 3)*P0 +
            (double)3*(pow((1-t), 2))*t*P1 +
            (double)3*(1-t)*pow(t, 2)*P2 +
            pow(t, 3)*P3;
}
