#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "MyPoint3D.h"
#include <cmath>

class Vector3D {

public:

    /**
     * zamienia punkt klasy MyPoint3D na wektor zapisany jako tablica double
     */
    static void convertToVector(MyPoint3D point, double *resultVector);

    /**
     * Fukncja tworzaca wektor zaczepiony w punkcie point1 i prowadacy do punktu point2
     */
    static void createVector(MyPoint3D point1, MyPoint3D point2, double *resultVector);
    static void createVector(double *point1, double* point2, double* resultVector);
    /**
     * Dlugosc wektora
     */
    static double length(double *vector);

    /**
     * Iloczyn wektorowy
     */
    static void crossProduct(const double *vector1, const double *vector2, double *resultVector);

    /**
     * Iloczyn skalarny
     */
    static double dotProduct(const double *vector1, const double *vector2);

    /**
     * normalizacja wektora
     */
    static void normalize(double *vector, double *resultVector);

    /**
     * liczby sredni wektor normalny wierzcholka na podstawie scian, do ktorych nalezy
     */
    static void *avgVectorVertex(const double *wall1, const double *wall2, const double *wall3, double *resultVector);

    static void removeNegativeZero(double* vector);
};


#endif //VECTOR3D_H
