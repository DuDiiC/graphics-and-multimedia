#include "BSplineCurve.h"

int BSplineCurve::pointInSet(MyPoint2D point, int scale) {

    for(int i = 0; i < bSplinePoints.size(); i++) {
        if(point.isInArea(bSplinePoints[i], scale)) {
            return i;
        }
    }
    return -1;
}

void BSplineCurve::draw(QImage *image, int RBGColor) {

    if(this->bSplinePoints.size() > 3) {
        MyPoint2D tempPoint;
        for(int i = 0; i < bSplinePoints.size()-3; i++) {
            for(double t = 0.0; t < 1.0; t += 0.0005) {
                tempPoint.setX((int)pointOnCurve(t, i, 1));
                tempPoint.setY((int)pointOnCurve(t, i, 0));
                tempPoint.setPixel(image);
            }
        }
    }
}

double BSplineCurve::pointOnCurve(double t, int startPointNumber, bool XorY) {

    double P0, P1, P2, P3;

    if(XorY) { // if true it's X
        P0 = (double)bSplinePoints[startPointNumber].getX();
        P1 = (double)bSplinePoints[startPointNumber+1].getX();
        P2 = (double)bSplinePoints[startPointNumber+2].getX();
        P3 = (double)bSplinePoints[startPointNumber+3].getX();
    } else { // if false it's Y
        P0 = (double)bSplinePoints[startPointNumber].getY();
        P1 = (double)bSplinePoints[startPointNumber+1].getY();
        P2 = (double)bSplinePoints[startPointNumber+2].getY();
        P3 = (double)bSplinePoints[startPointNumber+3].getY();
    }

    double tmpForP0 = (-pow(t,3)+3*pow(t,2)-3*t+1)/6.0;
    double tmpForP1 = (3*pow(t, 3)-6*pow(t,2)+4)/6.0;
    double tmpForP2 = (-3*pow(t, 3)+3*pow(t,2)+3*t+1)/6.0;
    double tmpForP3 = pow(t,3)/6.0;

    return tmpForP0*P0 + tmpForP1*P1 + tmpForP2*P2 + tmpForP3*P3;
}
