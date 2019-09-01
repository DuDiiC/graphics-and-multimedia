#include "includes/Matrices/PlanetTransformationMatrix.h"

void PlanetTransformationMatrix::updateMatrix() {

    double matrixTab[] {
            sin(alphaOrbit)*(sin(alphax)*sin(alphaz)-cos(alphax)*sin(alphay)*cos(alphaz))+cos(alphaOrbit)*cos(alphay)*cos(alphaz), sin(alphaOrbit)*(cos(alphax)*sin(alphay)*sin(alphaz)+sin(alphax)*cos(alphaz))-cos(alphaOrbit)*cos(alphay)*sin(alphaz), cos(alphaOrbit)*sin(alphay)+sin(alphaOrbit)*cos(alphax)*cos(alphay), sin(alphaOrbit)*(cos(alphax)*(-sin(alphay)*(y0*sin(alphaz)-x0*cos(alphaz))-z0*cos(alphay))+sin(alphax)*(-x0*sin(alphaz)-y0*cos(alphaz))+z0)+cos(alphaOrbit)*(cos(alphay)*(y0*sin(alphaz)-x0*cos(alphaz))-z0*sin(alphay)+x0),
            cos(alphax)*sin(alphaz)+sin(alphax)*sin(alphay)*cos(alphaz), cos(alphax)*cos(alphaz)-sin(alphax)*sin(alphay)*sin(alphaz), -sin(alphax)*cos(alphay), -sin(alphax)*(-sin(alphay)*(y0*sin(alphaz)-x0*cos(alphaz))-z0*cos(alphay))+cos(alphax)*(-x0*sin(alphaz)-y0*cos(alphaz))+y0,
            cos(alphaOrbit)*(sin(alphax)*sin(alphaz)-cos(alphax)*sin(alphay)*cos(alphaz))-sin(alphaOrbit)*cos(alphay)*cos(alphaz),cos(alphaOrbit)*(cos(alphax)*sin(alphay)*sin(alphaz)+sin(alphax)*cos(alphaz))+sin(alphaOrbit)*cos(alphay)*sin(alphaz), cos(alphaOrbit)*cos(alphax)*cos(alphay)-sin(alphaOrbit)*sin(alphay), cos(alphaOrbit)*(cos(alphax)*(-sin(alphay)*(y0*sin(alphaz)-x0*cos(alphaz))-z0*cos(alphay))+sin(alphax)*(-x0*sin(alphaz)-y0*cos(alphaz))+z0)-sin(alphaOrbit)*(cos(alphay)*(y0*sin(alphaz)-x0*cos(alphaz))-z0*sin(alphay)+x0),
            0.0, 0.0, 0.0, 1.0
    };

    planetTransformationMatrix = new QGenericMatrix<4, 4, double>(matrixTab);
}