#include "Circle.h"

void Circle::draw(QImage *image, int RGBColor) {

    MyPoint2D tempPoint;

    for(int x = 0; x <= radius.lenght()/sqrt(2); x++) {
        double y = sqrt(pow(radius.lenght(), 2)-pow(x, 2));
        tempPoint.setX(x);
        tempPoint.setY((int)y);
        draw8SymetricPixels(image, tempPoint, RGBColor);
    }
}

double Circle::radiusLenght() {
    return this->radius.lenght();
}

void Circle::updateRadius() {
    radius.setStartPoint(centerPoint);
    radius.setEndPoint(pointOnCircle);
}

void Circle::draw8SymetricPixels(QImage *image, MyPoint2D point, int RGBColor) {
    MyPoint2D tempPoint;
    tempPoint.setXY(point.getX()+centerPoint.getX(), point.getY()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(point.getY()+centerPoint.getX(), -point.getX()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(-point.getX()+centerPoint.getX(), -point.getY()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(-point.getY()+centerPoint.getX(), point.getX()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(point.getY()+centerPoint.getX(), point.getX()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(point.getX()+centerPoint.getX(), -point.getY()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(-point.getY()+centerPoint.getX(), -point.getX()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
    tempPoint.setXY(-point.getX()+centerPoint.getX(), point.getY()+centerPoint.getY());
    tempPoint.setPixel(image, RGBColor);
}
