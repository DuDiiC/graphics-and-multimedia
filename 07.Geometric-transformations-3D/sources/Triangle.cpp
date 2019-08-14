#include "includes/Triangle.h"

Triangle::Triangle() {
}

Triangle::Triangle(std::vector< MyPoint2D > points) {
    this->points = points;
}

Triangle::Triangle(MyPoint2D point1, MyPoint2D point2, MyPoint2D point3) {
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
}

Triangle::~Triangle() {
}

void Triangle::draw(QImage *img, int RGBColor) {

    LineSegment tempLine;

    for(int i = 0; i < points.size()-1; i++) {
        tempLine.setStartPoint(points[i]);
        tempLine.setEndPoint(points[i+1]);

        tempLine.draw(img, RGBColor);
    }
//    tempLine.setStartPoint(points[0]);
//    tempLine.draw(img, RGBColor);
}

int Triangle::pointInSet(MyPoint2D point, int scale) {
    for(int i = 0; i < points.size(); i++) {
        if(point.isInArea(points[i], scale)) {
            return i;
        }
    }
    return -1;
}

int Triangle::minimumX() {
    int result = points[0].getX();
    if(points[1].getX() < result) result = points[1].getX();
    if(points[2].getX() < result) result = points[2].getX();
    return result;
}

int Triangle::maximumX() {
    int result = points[0].getX();
    if(points[1].getX() > result) result = points[1].getX();
    if(points[2].getX() > result) result = points[2].getX();
    return result;
}

int Triangle::minimumY() {
    int result = points[0].getY();
    if(points[1].getY() < result) result = points[1].getY();
    if(points[2].getY() < result) result = points[2].getY();
    return result;
}
int Triangle::maximumY() {
    int result = points[0].getY();
    if(points[1].getY() > result) result = points[1].getY();
    if(points[2].getY() > result) result = points[2].getY();
    return result;
}
