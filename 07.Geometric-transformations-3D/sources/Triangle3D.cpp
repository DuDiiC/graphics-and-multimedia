#include "includes/Triangle3D.h"

void Triangle3D::draw(QImage *img, int RGBColor) {
    changeInto2D()->draw(img, RGBColor);
}

Triangle* Triangle3D::changeInto2D() {

    std::vector < MyPoint2D > points2D;

    for(int i = 0; i < points.size(); i++) {
        MyPoint2D tempPoint = *(points[i].changeInto2D());
        points2D.push_back(tempPoint);
    }

    return new Triangle(points2D);
}
