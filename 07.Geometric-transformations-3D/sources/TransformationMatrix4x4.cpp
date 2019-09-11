#include "includes/TransformationMatrix4x4.h"

void TransformationMatrix4x4::updateMatrix() {

    double matrixTab[] = {
//        sx * cos(alphay) * cos(alphaz), -sx * cos(alphay) * sin(alphaz), sx * sin(alphay), sx * y0 * cos(alphay) * sin(alphaz) - sx * x0 * cos(alphay) * cos(alphaz) - sx * z0 * sin(alphay) + x0 + tx,
//        sy * cos(alphax) * sin(alphaz) + sy * sin(alphax) * sin(alphay) * cos(alphaz), sy * cos(alphax) * cos(alphaz) - sy * sin(alphax) * sin(alphay) * sin(alphaz), -sy * sin(alphax) * cos(alphay), (sy * y0 * sin(alphax) * sin(alphay) - sy * x0 * cos(alphax)) * sin(alphaz) + (- sy * x0 * sin(alphax) * sin(alphay) - sy * y0 * cos(alphax)) * cos(alphaz) + sy * z0 * sin(alphax) * cos(alphay) + y0 + ty,
//        sz * sin(alphax) * sin(alphaz) - sz * cos(alphax) * sin(alphay) * cos(alphaz), sz * cos(alphax) * sin(alphay) * sin(alphaz) + sz * sin(alphax) * cos(alphaz), sz * cos(alphax) * cos(alphay), (- sz * y0 * cos(alphax) * sin(alphay) - sz * x0 * sin(alphax)) * sin(alphaz) + (sz * x0 * cos(alphax) * sin(alphay) - sz * y0 * sin(alphax)) * cos(alphaz) - sz * z0 * cos(alphax) * cos(alphay) + z0 + tz,
//        0.0, 0.0, 0.0, 1.0
        cos(alphay)*cos(alphaz)*sx, -cos(alphay)*sin(alphaz)*sy, sin(alphay)*sz,	tx-sin(alphay)*z0*sz+cos(alphay)*sin(alphaz)*y0*sy-cos(alphay)*cos(alphaz)*x0*sx+x0,
        (cos(alphax)*sin(alphaz)+sin(alphax)*sin(alphay)*cos(alphaz))*sx, (cos(alphax)*cos(alphaz)-sin(alphax)*sin(alphay)*sin(alphaz))*sy, -sin(alphax)*cos(alphay)*sz, ty+sin(alphax)*cos(alphay)*z0*sz+(sin(alphax)*sin(alphay)*sin(alphaz)-cos(alphax)*cos(alphaz))*y0*sy+(-cos(alphax)*sin(alphaz)-sin(alphax)*sin(alphay)*cos(alphaz))*x0*sx+y0,
        (sin(alphax)*sin(alphaz)-cos(alphax)*sin(alphay)*cos(alphaz))*sx,	(cos(alphax)*sin(alphay)*sin(alphaz)+sin(alphax)*cos(alphaz))*sy,	cos(alphax)*cos(alphay)*sz,	tz-cos(alphax)*cos(alphay)*z0*sz+(-cos(alphax)*sin(alphay)*sin(alphaz)-sin(alphax)*cos(alphaz))*y0*sy+(cos(alphax)*sin(alphay)*cos(alphaz)-sin(alphax)*sin(alphaz))*x0*sx+z0,
        0.0, 0.0, 0.0, 1.0
    };

    transformationMatrix = new QGenericMatrix<4, 4, double>(matrixTab);
}
