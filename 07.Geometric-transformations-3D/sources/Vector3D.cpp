#include "includes/Vector3D.h"

double *Vector3D::createVector(MyPoint3D *point1, MyPoint3D *point2) {
    double resultPoint[3];

    resultPoint[0] = point2->getX() - point1->getX();
    resultPoint[1] = point2->getY() - point1->getY();
    resultPoint[2] = point2->getZ() - point1->getZ();

    return &resultPoint[0];
}

double Vector3D::lenght(double *point) {
    return sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));
}

double* Vector3D::crossProduct(const double *point1, const double *point2) {
    double resultPoint[3];

    resultPoint[0] = point1[1] * point2[2] - point1[2] * point2[1];
    resultPoint[1] = point1[0] * point2[2] - point1[2] * point2[0];
    resultPoint[2] = point1[0] * point2[1] - point1[1] * point2[0];

    return &resultPoint[0];
}

double Vector3D::dotProduct(const double *point1, const double *point2) {
    return (point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2]);
}

double *Vector3D::normalize(double *point) {
    double resultPoint[3];
    double l = lenght(&point[0]);

    resultPoint[0] = point[0] / l;
    resultPoint[1] = point[1] / l;
    resultPoint[2] = point[2] / l;

    return &resultPoint[0];
}

