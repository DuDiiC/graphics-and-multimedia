#include "ColorPallete.h"

void ColorPallete::setPallete(QImage *image, ColorPalleteVal colorType, int colorVal) {

    QColor color = QColor(0, 0, 0);
    MyPoint2D *tempPoint = new MyPoint2D();

    if(colorType == RGB_R) {
        color.setRed(colorVal);
        for(int g = 0; g < image->height(); g++) {
            color.setGreen(g);
            tempPoint->setY(g);
            for(int b = 0; b < image->width(); b++) {
                color.setBlue(b);
                tempPoint->setX(b);
                tempPoint->setPixel(image, color);
            }
        }
    } else if(colorType== RGB_G) {
        color.setGreen(colorVal);
        for(int r = 0; r < image->height(); r++) {
            color.setRed(r);
            tempPoint->setY(r);
            for(int b = 0; b < image->width(); b++) {
                color.setBlue(b);
                tempPoint->setX(b);
                tempPoint->setPixel(image, color);
            }
        }
    } else if(colorType == RGB_B) {
        color.setBlue(colorVal);
        for(int r = 0; r < image->height(); r++) {
            color.setRed(r);
            tempPoint->setY(r);
            for(int g = 0; g < image->width(); g++) {
                color.setGreen(g);
                tempPoint->setX(g);
                tempPoint->setPixel(image, color);
            }
        }
    } else if(colorType == HSV_H) {
        for(int s = 0; s < image->height(); s++) {
            tempPoint->setY(s);
            for(int v = 0; v < image->width(); v++) {
                tempPoint->setX(v);
                color.setHsv(colorVal, s, v);
                tempPoint->setPixel(image, color);
            }
        }
    } else if(colorType == HSV_S) {
        for(int h = 0; h < image->height(); h++) {
            tempPoint->setY(h);
            for(int v = 0; v < image->width(); v++) {
                tempPoint->setX(v);
                color.setHsv(h, colorVal, v);
                tempPoint->setPixel(image, color);
            }
        }
    } else if(colorType == HSV_V) {
        for(int h = 0; h < image->height(); h++) {
            tempPoint->setY(h);
            for(int s = 0; s < image->width(); s++) {
                tempPoint->setX(s);
                color.setHsv(h, s, colorVal);
                tempPoint->setPixel(image, color);
            }
        }
    }

    delete tempPoint;
}
