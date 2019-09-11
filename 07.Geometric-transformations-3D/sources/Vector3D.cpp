#include "includes/Vector3D.h"
#include <iostream>

void Vector3D::convertToVector(MyPoint3D point, double *resultVector) {;

    resultVector[0] = (double)point.getX();
    resultVector[1] = (double)point.getY();
    resultVector[2] = (double)point.getZ();

    removeNegativeZero(resultVector);

    //std::cout << "convertToVector(): " << resultVector[0] << " " << resultVector[1] << " " << resultVector[2] << std::endl;
}

void Vector3D::createVector(MyPoint3D point1, MyPoint3D point2, double *resultVector) {

    //std::cout << point1.getX() << " " << point1.getY() << " " << point1.getZ() << std::endl;
    //std::cout << point2.getX() << " " << point2.getY() << " " << point2.getZ() << std::endl;

    resultVector[0] = (double)point2.getX() - (double)point1.getX();
    resultVector[1] = (double)point2.getY() - (double)point1.getY();
    resultVector[2] = (double)point2.getZ() - (double)point1.getZ();

    removeNegativeZero(resultVector);

    //std::cout << "createVector(): " << resultVector[0] << " " << resultVector[1] << " " << resultVector[2] << std::endl;
}

void Vector3D::createVector(double *point1, double* point2, double* resultVector) {

    resultVector[0] = point2[0] - point1[0];
    resultVector[1] = point2[1] - point1[1];
    resultVector[2] = point2[2] - point1[2];
}

double Vector3D::length(double *vector) {
    return sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
}

void Vector3D::crossProduct(const double *vector1, const double *vector2, double *resultVector) {

    resultVector[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    resultVector[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    resultVector[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    removeNegativeZero(resultVector);

    //std::cout << "crossProduct(): " << resultVector[0] << " " << resultVector[1] << " " << resultVector[2] << std::endl;
}

double Vector3D::dotProduct(const double *vector1, const double *vector2) {
    return (vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2]);
}

void Vector3D::normalize(double *vector, double *resultVector) {

    double l = length(vector);

    resultVector[0] = vector[0] / l;
    resultVector[1] = vector[1] / l;
    resultVector[2] = vector[2] / l;

    removeNegativeZero(resultVector);

    //std::cout << "normalize(): " << l << " " << resultVector[0] << " " << resultVector[1] << " " << resultVector[2] << std::endl;
}

void * Vector3D::avgVectorVertex(const double *wall1, const double *wall2, const double *wall3, double *resultVector) {

    resultVector[0] = (wall1[0] + wall2[0] + wall3[0])/3.0;
    resultVector[1] = (wall1[1] + wall2[1] + wall3[1])/3.0;
    resultVector[2] = (wall1[2] + wall2[2] + wall3[2])/3.0;

    removeNegativeZero(resultVector);

    //std::cout << "avgVectorVertex(): " << resultVector[0] << " " << resultVector[1] << " " << resultVector[2] << std::endl;
}

void Vector3D::removeNegativeZero(double* vector) {
    for(int i = 0; i < 3; i++) {
        if (vector[i] == -0.0) vector[i] = 0.0;
    }
}