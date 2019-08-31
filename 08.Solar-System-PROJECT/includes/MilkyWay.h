#ifndef MILKYWAY_H
#define MILKYWAY_H


#include <QImage>

#include "MyPoint2D.h"

#include <random>


class MilkyWay {

public:
    static void draw(QImage* img, int starsNumber);
};


#endif //MILKYWAY_H
