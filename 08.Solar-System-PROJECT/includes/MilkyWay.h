//
// Created by maciejdudek on 30.08.2019.
//

#ifndef MILKYWAY_H
#define MILKYWAY_H


#include <QImage>

#include "MyPoint2D.h"

#include <cstdlib>


class MilkyWay {

public:
    static void draw(QImage* img, int starsNumber);
};


#endif //MILKYWAY_H
