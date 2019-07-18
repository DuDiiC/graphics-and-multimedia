#include "Ellipse.h"

void Ellipse::draw(QImage *image, int RGBColor) {

    // central point
    int x0 = (int)floor((firstPointOnEllipse.getX()+secondPointOnEllipse.getX())/2.0+0.5);
    int y0 = (int)floor((firstPointOnEllipse.getY()+secondPointOnEllipse.getY())/2.0+0.5);

    double a = fabs(secondPointOnEllipse.getX()-x0); // longer
    double b = fabs(secondPointOnEllipse.getY()-y0); // shorter

    double angle = 0.0;

    MyPoint2D tempPoint1, tempPoint2;
    LineSegment tempLineSegment;

    tempPoint1.setXY((int)floor(a*cos(angle)+0.5)+x0,
                     (int)floor(b*sin(angle)+0.5)+y0);

    for(int i = 1; i <= 20; i++) {
        angle = i*2.0*M_PI/20.0;
        tempPoint2.setXY(a*cos(angle)+(double)x0,
                         b*sin(angle)+(double)y0);
        tempLineSegment.setStartPoint(tempPoint1);
        tempLineSegment.setEndPoint(tempPoint2);
        tempLineSegment.draw(image, RGBColor);
        tempPoint1.setXY(tempPoint2.getX(),
                         tempPoint2.getY());
    }

}
