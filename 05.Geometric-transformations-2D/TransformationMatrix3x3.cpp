#include "TransformationMatrix3x3.h"

void TransformationMatrix3x3::updateMatrix() {

//    double translationTab[] = {
//        1.0, 0.0, tx,
//        0.0, 1.0, ty,
//        0.0, 0.0, 1.0
//    };

//    double translationTabOdwrotna[] = {
//        1.0, 0.0, -tx,
//        0.0, 1.0, -ty,
//        0.0, 0.0, 1.0
//    };

//    double scalingTab[] = {
//        sx, 0.0, x0 - x0 * sx,
//        0.0, sy, y0 - sy * y0,
//        0.0, 0.0, 1.0
//    };

//    double scalingTabOdwrotna[] = {
//        1.0/sx, 0.0, -(x0 - sx * x0)/sx,
//        0.0, 1.0/sy, -(y0 - sy * y0)/sy,
//        0.0, 0.0, 1.0
//    };

//    double rotationTab[] = {
//        cos(alpha), -sin(alpha), -x0 * cos(alpha) + y0 * sin(alpha) + x0,
//        sin(alpha), cos(alpha), -x0 * sin(alpha) - y0 * cos(alpha) + y0,
//        0.0, 0.0, 1.0
//    };

//    double rotationTabOdwrotna[] = {
//        cos(alpha), sin(alpha), x0 * pow(sin(alpha), 2) - y0 * sin(alpha) + x0 * pow(cos(alpha), 2) - x0 * cos(alpha),
//        -sin(alpha), cos(alpha), y0 * pow(sin(alpha), 2) + x0 * sin(alpha) + y0 * pow(cos(alpha), 2) - y0 * cos(alpha),
//        0.0, 0.0, 1.0
//    };

//    double shearingTab[] = {
//        shx * shy + 1.0, shx, -y0 * shx - x0 * shx * shy,
//        shy, 1.0, -x0 * shy,
//        0.0, 0.0, 1.0
//    };

//    double shearingTabOdwrota[] = {
//        1.0, -shx, shx * y0,
//        -shy, shy * shx + 1.0, shy * x0 - shy * shx * y0,
//        0.0, 0.0, 1.0
//    };

//    QGenericMatrix<3, 3, double> translation(translationTab);
//    QGenericMatrix<3, 3, double> scaling(scalingTab);
//    QGenericMatrix<3, 3, double> rotation(rotationTab);
//    QGenericMatrix<3, 3, double> shearing(shearingTab);

//    QGenericMatrix<3, 3, double> translation(translationTabOdwrotna);
//    QGenericMatrix<3, 3, double> scaling(scalingTabOdwrotna);
//    QGenericMatrix<3, 3, double> rotation(rotationTabOdwrotna);
//    QGenericMatrix<3, 3, double> shearing(shearingTabOdwrota);

//    transformationMatrix = translation * scaling * rotation * shearing;

//    double invertMatrixAfterMultiply[] = {
//        1.0/((shy * shx + 1.0) * sx * cos(alpha)), 0.0, -(tx * (x0 - sx * x0) * (- shx * y0 - shy * shx * x0) * (y0 * sin(alpha) - x0 * cos(alpha) + x0))/((shy * shx + 1.0) * sx * cos(alpha)),
//        0.0, 1.0/(sy * cos(alpha)), (shy * ty * x0 * (y0 - sy * y0) * (-x0 * sin(alpha) - y0 * cos(alpha) + y0))/(sy * cos(alpha)),
//        0.0, 0.0, 1.0
//    };

//    transformationMatrix = QGenericMatrix<3, 3, double>(invertMatrixAfterMultiply);

    double matrixTab[] = {
        (shx * sin(alpha) + cos(alpha))/sx, (sin(alpha) -shx * cos(alpha))/sy, -(((sx * (double)y0 + sy * shx * (double)x0 + sy * shx * (double)tx + (double)ty * sx) * sin(alpha) + (-shx * sx * (double)y0 + sy * (double)x0 + sy * (double)tx - shx * (double)ty * sx) * cos(alpha) - sy * sx * (double)x0)/(sx * sy)),
        -(((shy * shx + 1.0) * sin(alpha) + shy * cos(alpha))/sx), -((shy * sin(alpha) + (-shy * shx - 1.0) * cos(alpha))/sy), ((shy * sx * (double)y0 + (sy * shy * shx + sy) * (double)x0 + (sy * shy * shx + sy) * (double)tx + shy * (double)ty * sx) * sin(alpha) + ((-shy * shx - 1.0) * sx * (double)y0 + sy * shy * (double)x0 + sy * shy * (double)tx + sy * shy * (double)tx + (-shy * shx - 1.0) * (double)ty * sx) * cos(alpha) + sy * sx * (double)y0)/(sx * sy),
        0.0, 0.0, 1.0
    };

    transformationMatrix = QGenericMatrix<3, 3, double>(matrixTab);

}
