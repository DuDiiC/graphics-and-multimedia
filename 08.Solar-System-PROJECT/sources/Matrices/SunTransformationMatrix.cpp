#include "includes/Matrices/SunTransformationMatrix.h"

void SunTransformationMatrix::updateMatrix() {

    double matrixTab[] = {
            cos(alphay) * cos(alphaz), -cos(alphay) * sin(alphaz), sin(alphay), 0.0,
            cos(alphax) * sin(alphaz) + sin(alphax) * sin(alphay) * cos(alphaz), cos(alphax) * cos(alphaz) - sin(alphax) * sin(alphay) * sin(alphaz), -sin(alphax) * cos(alphay), 0.0,
            sin(alphax) * sin(alphaz) - cos(alphax) * sin(alphay) * cos(alphaz), cos(alphax) * sin(alphay) * sin(alphaz) + sin(alphax) * cos(alphaz), cos(alphax) * cos(alphay), 0.0,
            0.0, 0.0, 0.0, 1.0
    };

    sunTransformationMatrix = new QGenericMatrix<4, 4, double>(matrixTab);
}