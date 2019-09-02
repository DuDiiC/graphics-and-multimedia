#include "includes/2D/LineSegment.h"

void LineSegment::draw(QImage *image, int RGBColor) {
    MyPoint2D tempPoint;

    int x, y, dx, dy;
    float t;

    dx = abs(endPoint.getX()-startPoint.getX());
    dy = abs(endPoint.getY()-startPoint.getY());

    // for only one point
    if(startPoint.getX() == endPoint.getX() && startPoint.getY() == endPoint.getY()) {
        tempPoint.setX(startPoint.getX());
        tempPoint.setY(startPoint.getY());
        tempPoint.setPixel(image, RGBColor);
    // for a in set [-1, 1] and startX < endX
    } else if(dx >= dy && startPoint.getX() < endPoint.getX()) {
        for(int x = startPoint.getX(); x <= endPoint.getX(); x++) {
            t = (float)(x - startPoint.getX())/(endPoint.getX()-startPoint.getX());
            y = (int)(startPoint.getY() + t * (endPoint.getY() - startPoint.getY()));
            tempPoint.setX(x);
            tempPoint.setY(y);
            tempPoint.setPixel(image, RGBColor);
        }
    // for a in set [-1, 1] and startX > endX
    } else if(dx >= dy && startPoint.getX() > endPoint.getX()) {
        for(int x = endPoint.getX(); x <= startPoint.getX(); x++) {
            t = (float)(x - endPoint.getX())/(startPoint.getX()-endPoint.getX());
            y = (int)(endPoint.getY() + t * (startPoint.getY()-endPoint.getY()));
            tempPoint.setX(x);
            tempPoint.setY(y);
            tempPoint.setPixel(image, RGBColor);
        }
    // for a in set (-inf, -1)u(1, +inf) and startY < endY
    } else if(dy > dx && startPoint.getY() < endPoint.getY()) {
        for(int y = startPoint.getY(); y <= endPoint.getY(); y++) {
            t = (float)(y - startPoint.getY())/(endPoint.getY()-startPoint.getY());
            x = (int)(startPoint.getX() + t * (endPoint.getX()-startPoint.getX()));
            tempPoint.setX(x);
            tempPoint.setY(y);
            tempPoint.setPixel(image, RGBColor);
        }
    // for a in set (-inf, -1)u(1, +inf) and startY > endY
    } else if(dy > dx && startPoint.getY() > endPoint.getY()) {
        for(int y = endPoint.getY(); y <= startPoint.getY(); y++) {
            t = (float)(y - endPoint.getY())/(startPoint.getY()-endPoint.getY());
            x = (int)(endPoint.getX() + t * (startPoint.getX()-endPoint.getX()));
            tempPoint.setX(x);
            tempPoint.setY(y);
            tempPoint.setPixel(image, RGBColor);
        }
    }
}

void LineSegment::updateA() {
    if((startPoint.getX() != endPoint.getX())) {
        a = (double)(endPoint.getY()-startPoint.getY())/(endPoint.getX()-startPoint.getX());
    } else {
        a = 0;
    }
}

double LineSegment::lenght() {
    double temp1 = pow((endPoint.getX()-startPoint.getX()), 2);
    double temp2 = pow((endPoint.getY()-startPoint.getY()), 2);
    return sqrt(temp1+temp2);
}
