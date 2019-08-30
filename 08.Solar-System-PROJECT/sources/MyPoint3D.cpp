#include "includes/MyPoint3D.h"

MyPoint2D* MyPoint3D::changeInto2D() {

    int xPrim, yPrim;

    xPrim = (double)(x*d)/(double)(z+d);
    yPrim = (double)(y*d)/(double)(z+d);

    return new MyPoint2D(xPrim+500, yPrim+400);
}

bool operator==(const MyPoint3D& p1, const MyPoint3D& p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z));
}
