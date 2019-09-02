#ifndef MILKYWAY_H
#define MILKYWAY_H

#include <QImage>
#include <random>

#include "includes/2D/MyPoint2D.h"

class MilkyWay {

public:

    /**
     * Draws the starsNumber stars on empty imgg
     */
    static void draw(QImage* img, int starsNumber);
};


#endif //MILKYWAY_H
