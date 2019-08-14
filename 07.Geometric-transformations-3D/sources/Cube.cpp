#include "includes/Cube.h"
#include <iostream>
#include <includes/TriangleTexturing.h>

Cube::Cube(int a, int d) {
    x = a;
    y = a;
    z = a;
    this->d = d;
    setValues();
}

Cube::Cube(int x, int y, int z, int d) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->d = d;
    setValues();
}

void Cube::draw(QImage *img, int RGBColor) {

    img->fill(Qt::black);
    for(int i = 0; i < triangles.size(); i++) {
        triangles[i].changeInto2D()->draw(img, RGBColor);
    }

    QImage *frontSource = new QImage("/home/maciejdudek/Pulpit/LGM koncowe/Fourth-Semester-Graphics/07.Geometric-transformations-3D/resources/front.jpg");

    MyPoint2D   p1(0, frontSource->height()-1), p2(0, 0), p3(frontSource->width()-1, 0),
                p4(frontSource->width()-1, 0), p5(frontSource->width()-1, frontSource->height()-1), p6(0, frontSource->height());

    Triangle t0 = Triangle(p1, p2, p3);
    Triangle t1 = Triangle(p6, p5, p4);

    Triangle tt0 = *(triangles[0].changeInto2D());
    Triangle tt1 = *(triangles[1].changeInto2D());

    TriangleTexturing::texturing(frontSource, t0, img, tt0);
    TriangleTexturing::texturing(frontSource, t1, img, tt1);
}

void Cube::updateValues(TransformationMatrix4x4 *matrix) {
    for(int i = 0; i < points.size(); i++) {

        MyPoint3D newPoint;

        //std::cout << points[i].getX() << " " << points[i].getY() << " " <<  points[i].getZ() << std::endl;

        double tempPointTab[] = { (int)points[i].getX(), (int)points[i].getY(), (int)points[i].getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        tempPointM = matrix->getTransformationMatrix() * tempPointM;

        newPoint.setXYZ(tempPointM.data()[0], tempPointM.data()[1], tempPointM.data()[2]);
        newPoint.setD(d);

        points[i] = newPoint;

        //std::cout << points[i].getX() << " " << points[i].getY() << " " <<  points[i].getZ() << std::endl;

    }

    setTriangles();
}

void Cube::setValues() {

    setPoints();
    setTriangles();
}

void Cube::setPoints() {
    points.clear();

    MyPoint3D tempPoint(50);

    // 0
    tempPoint.setXYZD(-x, -y, z, d);
    points.push_back(tempPoint);
    // 1
    tempPoint.setXYZD(-x, y, z, d);
    points.push_back(tempPoint);
    // 2
    tempPoint.setXYZD(x, y, z, d);
    points.push_back(tempPoint);
    // 3
    tempPoint.setXYZD(x, -y, z, d);
    points.push_back(tempPoint);
    // 4
    tempPoint.setXYZD(x, -y, -z, d);
    points.push_back(tempPoint);
    // 5
    tempPoint.setXYZD(x, y, -z, d);
    points.push_back(tempPoint);
    // 6
    tempPoint.setXYZD(-x, y, -z, d);
    points.push_back(tempPoint);
    // 7
    tempPoint.setXYZD(-x, -y, -z, d);
    points.push_back(tempPoint);
}

void Cube::setTriangles() {
    triangles.clear();

    Triangle3D tempTriangle;

    tempTriangle.setPoints(points[0], points[3], points[4]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[0], points[7], points[4]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[2], points[1], points[6]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[2], points[5], points[6]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[3], points[4], points[5]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[3], points[2], points[5]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[1], points[0], points[7]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[1], points[6], points[7]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[0], points[1], points[2]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[0], points[3], points[2]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[5], points[6], points[7]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[5], points[4], points[7]);
    triangles.push_back(tempTriangle);
}
