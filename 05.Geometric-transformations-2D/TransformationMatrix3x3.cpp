#include "TransformationMatrix3x3.h"

void TransformationMatrix3x3::updateMatrix() {

    double matrixTab[] = {
        (shx * sin(alpha) + cos(alpha))/sx, (sin(alpha) -shx * cos(alpha))/sy, -(((sx * (double)y0 + sy * shx * (double)x0 + sy * shx * (double)tx + (double)ty * sx) * sin(alpha) + (-shx * sx * (double)y0 + sy * (double)x0 + sy * (double)tx - shx * (double)ty * sx) * cos(alpha) - sy * sx * (double)x0)/(sx * sy)),
        -(((shy * shx + 1.0) * sin(alpha) + shy * cos(alpha))/sx), -((shy * sin(alpha) + (-shy * shx - 1.0) * cos(alpha))/sy), ((shy * sx * (double)y0 + (sy * shy * shx + sy) * (double)x0 + (sy * shy * shx + sy) * (double)tx + shy * (double)ty * sx) * sin(alpha) + ((-shy * shx - 1.0) * sx * (double)y0 + sy * shy * (double)x0 + sy * shy * (double)tx + sy * shy * (double)tx + (-shy * shx - 1.0) * (double)ty * sx) * cos(alpha) + sy * sx * (double)y0)/(sx * sy),
        0.0, 0.0, 1.0
    };

    transformationMatrix = QGenericMatrix<3, 3, double>(matrixTab);

}
