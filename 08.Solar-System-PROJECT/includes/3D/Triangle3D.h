#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H

#include "includes/2D/MyPoint2D.h"
#include "MyPoint3D.h"
#include "includes/2D/Triangle.h"

#include <utility>
#include <vector>

class Triangle3D {

public:

    Triangle3D() {
    }

    Triangle3D(std::vector < MyPoint3D > points, std::vector < double* > normals)
                    : points(std::move(points)), normals(std::move(normals)) {
    }

    Triangle3D(MyPoint3D point1, MyPoint3D point2, MyPoint3D point3);

    ~Triangle3D() {
    }

    void draw(QImage *img, int RGBColor = 0xFFFFFF);

    void setPoints(std::vector < MyPoint3D > points) { this->points = points; }
    void setPoints(MyPoint3D p1, MyPoint3D p2, MyPoint3D p3) {
        points.clear();
        points.push_back(p1); points.push_back(p2); points.push_back(p3);
    }
    std::vector < MyPoint3D > getPoints() { return points; }

    void setPoint(int index, MyPoint3D point) { points[index] = point; }
    MyPoint3D getPoint(int index) { return points[index]; }

    double* getNormal(int index) { return normals[index]; }

    void addPoint(MyPoint3D point) {
        points.push_back(point);
    }

    void removePoint(MyPoint3D point) {
        points.erase(std::remove(points.begin(),
                                 points.end(), point),
                     points.end());
    }

    Triangle* changeInto2D();

private:

    std::vector < MyPoint3D > points;
    std::vector < double* > normals;
};

#endif // TRIANGLE3D_H
