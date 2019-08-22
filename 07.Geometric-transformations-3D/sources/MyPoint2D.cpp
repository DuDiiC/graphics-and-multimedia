#include "includes/MyPoint2D.h"

void MyPoint2D::setPixel(QImage *image, int RGBColor) {

    uchar* bits = (uchar*)image->bits();

    int RGBcolorBlue = RGBColor & 255;
    int RGBcolorGreen = (RGBColor >> 8) & 255;
    int RGBcolorRed = (RGBColor >> 16) & 255;

    if(this->isOnWidget(image)) {
        bits[4*(this->x + this->y*image->width())] = RGBcolorBlue; // blue
        bits[4*(this->x + this->y*image->width())+1] = RGBcolorGreen; // green
        bits[4*(this->x + this->y*image->width())+2] = RGBcolorRed; // red
        bits[4*(this->x + this->y*image->width())+3] = 255; // must be 255
    }
}

void MyPoint2D::setPixel(QImage *image, QColor RGBColor) {

    uchar* bits = (uchar*)image->bits();

    if(this->isOnWidget(image)) {
        bits[4*(this->x + this->y*image->width())] = RGBColor.blue(); // blue
        bits[4*(this->x + this->y*image->width())+1] = RGBColor.green(); // green
        bits[4*(this->x + this->y*image->width())+2] = RGBColor.red(); // red
        bits[4*(this->x + this->y*image->width())+3] = RGBColor.alpha(); // alpha
    }
}

int MyPoint2D::getPixelRGBColor(QImage *image) {

    uchar* bits = (uchar*)image->bits();

    int RGBColorBlue = bits[4*(this->x + this->y * image->width())];
    int RGBColorGreen = (bits[4*(this->x + this->y * image->width())+1] << 8);
    int RGBColorRed = (bits[4*(this->x + this->y * image->width())+2] << 16);

    return RGBColorBlue + RGBColorGreen + RGBColorRed;
}

void MyPoint2D::enlarge(QImage *image, int scale, int RGBColor) {
    MyPoint2D tempPoint;
    for(int x = this->x-scale; x <= this->x+scale; x++) {
        tempPoint.setX(x);
        for(int y = this->y-scale; y <= this->y+scale; y++) {
            tempPoint.setY(y);
            tempPoint.setPixel(image, RGBColor);
        }
    }
}

bool MyPoint2D::isInArea(MyPoint2D point, int scale) {
    if(this->x >= point.getX()-scale && this->x <= point.getX()+scale &&
       this->y >= point.getY()-scale && this->y <= point.getY()+scale)
        return true;
    return false;
}

bool MyPoint2D::isOnWidget(QImage *image) {
    return (this->x >= 0 && this->y >= 0 &&
            this->x < image->width() && this->y < image->height());
}

bool operator==(const MyPoint2D &p1, const MyPoint2D &p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}
