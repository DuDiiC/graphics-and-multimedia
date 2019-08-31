#include "includes/MilkyWay.h"

void MilkyWay::draw(QImage *img, int starsNumber) {

    int x, y;
    MyPoint2D tempPoint;

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution< int > widthRand(0, img->width()-1);
    std::uniform_int_distribution< int > heightRand(0, img->height()-1);

    for(int i = 0; i < starsNumber; i++) {

        x = widthRand(e1);
        y = heightRand(e1);

        tempPoint.setXY(x, y);
        tempPoint.setPixel(img);
    }
}
