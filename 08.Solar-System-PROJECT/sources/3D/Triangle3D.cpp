#include "includes/3D/Triangle3D.h"

Triangle3D::Triangle3D(MyPoint3D point1, MyPoint3D point2, MyPoint3D point3) {
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
}

void Triangle3D::draw(QImage *img, int RGBColor) {
    changeInto2D()->draw(img, RGBColor);
}

Triangle* Triangle3D::changeInto2D() {

    std::vector < MyPoint2D > points2D;

    for(auto & point : points) {
        MyPoint2D tempPoint = *(point.changeInto2D());
        points2D.push_back(tempPoint);
    }

    return new Triangle(points2D);
}
