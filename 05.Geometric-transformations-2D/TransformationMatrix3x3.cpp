#include "TransformationMatrix3x3.h"

void TransformationMatrix3x3::updateMatrix() {

    double translationTab[] = {
        1.0, 0.0, tx,
        0.0, 1.0, ty,
        0.0, 0.0, 1.0
    };

    double scalingTab[] = {
        sx, 0.0, x0 - x0 * sx,
        0.0, sy, y0 - sy * y0,
        0.0, 0.0, 1.0
    };

    double rotationTab[] = {
        cos(alpha), -sin(alpha), -x0 * cos(alpha) + y0 * sin(alpha) + x0,
        sin(alpha), cos(alpha), -x0 * sin(alpha) - y0 * cos(alpha) + y0,
        0.0, 0.0, 1.0
    };

    double shearingTab[] = {
        shx * shy + 1.0, shx, -y0 * shx - x0 * shx * shy,
        shy, 1.0, -x0 * shy,
        0.0, 0.0, 1.0
    };

    QGenericMatrix<3, 3, double> translation(translationTab);
    QGenericMatrix<3, 3, double> scaling(scalingTab);
    QGenericMatrix<3, 3, double> rotation(rotationTab);
    QGenericMatrix<3, 3, double> shearing(shearingTab);

    transformationMatrix = translation * scaling * rotation * shearing;
}
