#ifndef PLANETTRANSFORMATIONMATRIX_H
#define PLANETTRANSFORMATIONMATRIX_H

#include <cmath>
#include <QGenericMatrix>

class PlanetTransformationMatrix {

public:
    PlanetTransformationMatrix(int X0, int Y0, int Z0, double alphaX, double alphaY, double alphaZ, double alphaO) :
                                x0(X0), y0(Y0), z0(Z0), alphax(alphaX), alphay(alphaY), alphaz(alphaZ), alphaOrbit(alphaO) {
    }

    ~PlanetTransformationMatrix() {
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

    void setAlphaOFromDegrees(int degreesO) {
        this->alphaOrbit = (double)degreesO * M_PI/180.0;
        updateMatrix();
    }

    QGenericMatrix<4, 4, double> *getPlanetTransformationMatrix() { return planetTransformationMatrix; }

    /**
     * updateMatrix is method calling after modyfying some values in transformation matrix
     */
    void updateMatrix();

private:

    QGenericMatrix<4, 4, double> *planetTransformationMatrix;

    int x0;
    int y0;
    int z0;

    double alphax;
    double alphay;
    double alphaz;
    double alphaOrbit;
};


#endif //PLANETTRANSFORMATIONMATRIX_H
