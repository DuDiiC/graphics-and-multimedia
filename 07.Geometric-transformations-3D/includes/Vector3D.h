#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "MyPoint3D.h"
#include <cmath>

class Vector3D {

    /**
     * Fukncja tworzaca wektor zaczepiony w punkcie point1 i prowadacy do punktu point2
     */
     static double* createVector(MyPoint3D *point1, MyPoint3D *point2);

    /**
     * Dlugosc wektora
     */
    static double lenght(double *point);

    /**
     * Iloczyn wektorowy
     */
    static double* crossProduct(const double *point1, const double *point2);

    /**
     * Iloczyn skalarny
     */
    static double dotProduct(const double *point1, const double *point2);

    /**
     * normalizacja wektora
     */
    static double* normalize(double *point);

};


#endif //VECTOR3D_H
