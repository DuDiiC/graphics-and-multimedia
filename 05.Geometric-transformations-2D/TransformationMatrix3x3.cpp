#include "TransformationMatrix3x3.h"

void TransformationMatrix3x3::updateMatrix() {

    double matrixTab[] = {
//        (shx * sin(alpha) + cos(alpha))/sx, (sin(alpha) -shx * cos(alpha))/sy, -(((sx * (double)y0 + sy * shx * (double)x0 + sy * shx * (double)tx + (double)ty * sx) * sin(alpha) + (-shx * sx * (double)y0 + sy * (double)x0 + sy * (double)tx - shx * (double)ty * sx) * cos(alpha) - sy * sx * (double)x0)/(sx * sy)),
//        -(((shy * shx + 1.0) * sin(alpha) + shy * cos(alpha))/sx), -((shy * sin(alpha) + (-shy * shx - 1.0) * cos(alpha))/sy), ((shy * sx * (double)y0 + (sy * shy * shx + sy) * (double)x0 + (sy * shy * shx + sy) * (double)tx + shy * (double)ty * sx) * sin(alpha) + ((-shy * shx - 1.0) * sx * (double)y0 + sy * shy * (double)x0 + sy * shy * (double)tx + sy * shy * (double)tx + (-shy * shx - 1.0) * (double)ty * sx) * cos(alpha) + sy * sx * (double)y0)/(sx * sy),
//        0.0, 0.0, 1.0
        -(sin(alpha)*shy-cos(alpha))/sx, (sin(alpha)*shx*shy-cos(alpha)*shx+sin(alpha))/sx, -((sin(alpha)*shx*shy-cos(alpha)*shx+sin(alpha))*ty+(cos(alpha)-sin(alpha)*shy)*tx-x0*sx+(sin(alpha)*y0*shx-sin(alpha)*x0)*shy-cos(alpha)*y0*shx+cos(alpha)*x0+sin(alpha)*y0)/sx,
        -(cos(alpha)*shy+sin(alpha))/sy, (cos(alpha)*shx*shy+sin(alpha)*shx+cos(alpha))/sy, -((cos(alpha)*shx*shy+sin(alpha)*shx+cos(alpha))*ty+(-cos(alpha)*shy-sin(alpha))*tx-y0*sy+(cos(alpha)*y0*shx-cos(alpha)*x0)*shy+sin(alpha)*y0*shx-sin(alpha)*x0+cos(alpha)*y0)/sy,
        0.0, 0.0, 1.0
    };

    transformationMatrix = QGenericMatrix<3, 3, double>(matrixTab);

}
