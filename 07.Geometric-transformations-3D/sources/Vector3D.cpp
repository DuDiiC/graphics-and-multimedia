#include "includes/Vector3D.h"

double* Vector3D::convertToVector(MyPoint3D *point) {
    static double resultVector[3];

    resultVector[0] = point->getX();
    resultVector[1] = point->getY();
    resultVector[2] = point->getZ();

    return resultVector;
}

double* Vector3D::createVector(MyPoint3D point1, MyPoint3D point2) {
    static double resultVector[3];

    resultVector[0] = point2.getX() - point1.getX();
    resultVector[1] = point2.getY() - point1.getY();
    resultVector[2] = point2.getZ() - point1.getZ();

    return &resultVector[0];
}

double Vector3D::length(double *point) {
    return sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));
}

double* Vector3D::crossProduct(const double point1[3], const double point2[3]) {
    static double resultVector[3];

    resultVector[0] = point1[1] * point2[2] - point1[2] * point2[1];
    resultVector[1] = point1[0] * point2[2] - point1[2] * point2[0];
    resultVector[2] = point1[0] * point2[1] - point1[1] * point2[0];

    return &resultVector[0];
}

double Vector3D::dotProduct(const double *point1, const double *point2) {
    return (point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2]);
}

double* Vector3D::normalize(double *point) {
    static double resultVector[3];
    double l = length(&point[0]);

    resultVector[0] = point[0] / l;
    resultVector[1] = point[1] / l;
    resultVector[2] = point[2] / l;

    return &resultVector[0];
}

double* Vector3D::avgVectorVertex(const double* wall1, const double* wall2, const double* wall3) {
    static double resultVector[3];

    resultVector[0] = (wall1[0] + wall2[0] + wall3[0])/3.0;
    resultVector[1] = (wall1[1] + wall2[1] + wall3[1])/3.0;
    resultVector[2] = (wall1[2] + wall2[2] + wall3[2])/3.0;

    return &resultVector[0];
}