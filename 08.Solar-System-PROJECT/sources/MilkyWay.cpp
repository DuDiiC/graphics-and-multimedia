//
// Created by maciejdudek on 30.08.2019.
//

#include "includes/MilkyWay.h"
#include <iostream>

void MilkyWay::draw(QImage *img, int starsNumber) {

    int x, y;
    MyPoint2D tempPoint;

    for(int i = 0; i < starsNumber - (starsNumber/10); i++) {

        x = rand()%(img->width());
        y = rand()%(img->height());

        tempPoint.setXY(x, y);
        tempPoint.setPixel(img);
    }

    for(int i = 0; i < starsNumber / 10; i++) {

        x = rand()%(img->width());
        y = rand()%(img->height());

        tempPoint.setXY(x, y);
        tempPoint.enlarge(img, 1);
    }
}
