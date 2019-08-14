#include "includes/MyPoint3D.h"
#include <iostream>

MyPoint2D* MyPoint3D::changeInto2D() {

    int xPrim, yPrim;

    //std::cout << x << " " << y << " " << z << " " << d << std::endl;

    xPrim = (double)(x*d)/(double)(z+d);
    yPrim = (double)(y*d)/(double)(z+d);

    //std::cout << xPrim << " " << yPrim << std::endl;

    return new MyPoint2D(xPrim+400, yPrim+300);
}

bool operator==(const MyPoint3D& p1, const MyPoint3D& p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z));
}
