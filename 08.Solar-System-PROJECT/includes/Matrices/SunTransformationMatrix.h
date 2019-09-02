#ifndef SUNTRANSFORMATIONMATRIX_H
#define SUNTRANSFORMATIONMATRIX_H

#include <cmath>
#include <QGenericMatrix>

class SunTransformationMatrix {

public:
    SunTransformationMatrix(double alphaX, double alphaY, double alphaZ) :
                                alphax(alphaX), alphay(alphaY), alphaz(alphaZ) {
    }

    ~SunTransformationMatrix() {
    }

    void setAlphaXFromDegrees(int degreesX) {
        this->alphax = (double)degreesX * M_PI/180.0;
        updateMatrix();
    }

    void setAlphaYFromDegrees(int degreesY) {
        this->alphay = (double)degreesY * M_PI/180.0;
        updateMatrix();
    }

    void setAlphaZFromDegrees(int degreesZ) {
        this->alphaz = (double)degreesZ * M_PI/180.0;
        updateMatrix();
    }

    QGenericMatrix<4, 4, double>* getSunTransformationMatrix() { return sunTransformationMatrix; }

    /**
     * updateMatrix is method calling after modyfying some values in transformation matrix
     */
    void updateMatrix();

private:

    QGenericMatrix<4, 4, double> *sunTransformationMatrix;

    /**
     * values in radians, between (-PI, PI), value to rotation
     */
    double alphax;
    double alphay;
    double alphaz;
};


#endif //SUNTRANSFORMATIONMATRIX_H
