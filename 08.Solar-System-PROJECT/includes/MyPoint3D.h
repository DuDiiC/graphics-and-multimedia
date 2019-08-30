#ifndef MYPOINT3D_H
#define MYPOINT3D_H

#include "MyPoint2D.h"

class MyPoint3D {

private:
    int x;
    int y;
    int z;

    int d;

public:

    MyPoint3D() {
    }

    MyPoint3D(int dP) : d(dP) {
    }

    MyPoint3D(int xP, int yP, int zP, int dP) : x(xP), y(yP), z(zP), d(dP) {
    }

    ~MyPoint3D() {
    }

    int getX() { return this->x; }
    void setX(int x) { this->x = x; }

    int getY() { return this->y; }
    void setY(int y) { this->y = y; }

    int getZ() { return this->z; }
    void setZ(int z) { this->z = z; }

    int getD() { return this->d; }
    void setD(int d) { this->d = d; }

    void setXYZ(int x, int y, int z) { setX(x); setY(y); setZ(z); }

    void setXYZD(int x, int y, int z, int d) { setX(x); setY(y); setZ(z); setD(d); }

    MyPoint2D* changeInto2D();

    friend bool operator==(const MyPoint3D& p1, const MyPoint3D& p2);

};

#endif // MYPOINT3D_H
