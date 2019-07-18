#include "FloodFill.h"

void FloodFill::floodFill(QImage *image, MyPoint2D startPoint, int fillRGBColor) {

    std::stack < MyPoint2D > points;
    MyPoint2D tempPoint, tempPoint2;

    if(startPoint.getPixelRGBColor(image) != fillRGBColor) {

        points.push(startPoint);

        while(!points.empty()) {
            tempPoint = points.top();
            points.pop();
            if(tempPoint.isOnWidget(image)) {
                tempPoint.setPixel(image, fillRGBColor);
            }
            // check other pixels in the area
            // left
            tempPoint2.setXY(tempPoint.getX()-1, tempPoint.getY());
            if(tempPoint2.isOnWidget(image) && tempPoint2.getPixelRGBColor(image) != fillRGBColor) {
                points.push(tempPoint2);
            }
            // upper
            tempPoint2.setXY(tempPoint.getX(), tempPoint.getY()-1);
            if(tempPoint2.isOnWidget(image) && tempPoint2.getPixelRGBColor(image) != fillRGBColor) {
                points.push(tempPoint2);
            }
            // right
            tempPoint2.setXY(tempPoint.getX()+1, tempPoint.getY());
            if(tempPoint2.isOnWidget(image) && tempPoint2.getPixelRGBColor(image) != fillRGBColor) {
                points.push(tempPoint2);
            }
            // bottom
            tempPoint2.setXY(tempPoint.getX(), tempPoint.getY()+1);
            if(tempPoint2.isOnWidget(image) && tempPoint2.getPixelRGBColor(image) != fillRGBColor) {
                points.push(tempPoint2);
            }
        }
    }
}
