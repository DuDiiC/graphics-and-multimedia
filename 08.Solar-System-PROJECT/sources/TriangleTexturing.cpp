#include "includes/TriangleTexturing.h"

void TriangleTexturing::texturing(QImage *sourceImg, Triangle *sourceTriangle, QImage *texturedImg, Triangle *texturedTriangle) {
    double u, v, w;

    for (int x = texturedTriangle->minimumX(); x <= texturedTriangle->maximumX(); x++) {
        for (int y = texturedTriangle->minimumY(); y < texturedTriangle->maximumY(); y++) {

            auto *tempPoint = new MyPoint2D(x, y);
            v = calNumeratorV(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            w = calNumeratorW(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            u = calU(v, w);

            if (pointIsInTriangle(u, v, w)) {
                double xt = u * (double) sourceTriangle->getPoint(0).getX() +
                            v * (double) sourceTriangle->getPoint(1).getX() +
                            w * (double) sourceTriangle->getPoint(2).getX();
                double yt = u * (double) sourceTriangle->getPoint(0).getY() +
                            v * (double) sourceTriangle->getPoint(1).getY() +
                            w * (double) sourceTriangle->getPoint(2).getY();

                auto *tempPoint2 = new MyPoint2D(xt, yt);

                tempPoint->setPixel(texturedImg,
                                    doubleLineInterpolation(sourceImg, tempPoint2->getX(), tempPoint2->getY()));

                delete tempPoint2;
            }

            delete tempPoint;
        }
    }
}

void TriangleTexturing::texturingWithFlatShading(QImage *sourceImg, Triangle *sourceTriangle,
                                     QImage *texturedImg, Triangle3D *texturedTriangle3D,
                                     double *lightVector) {
    Triangle* texturedTriangle = texturedTriangle3D->changeInto2D();
    double BC[3];
    Vector3D::createVector(texturedTriangle3D->getPoint(1), texturedTriangle3D->getPoint(2), BC);
    double BA[3];
    Vector3D::createVector(texturedTriangle3D->getPoint(1), texturedTriangle3D->getPoint(0), BA);
    double wallVector[3];
    Vector3D::crossProduct(BC, BA, wallVector);
    Vector3D::normalize(wallVector, wallVector);

    double val = Vector3D::dotProduct(wallVector, lightVector);
    if(val < 0.0) val = 0;
    val += 0.111;
    if(val > 1.0) val = 1.0;

    double u, v, w;

    for (int x = texturedTriangle->minimumX(); x <= texturedTriangle->maximumX(); x++) {
        for (int y = texturedTriangle->minimumY(); y < texturedTriangle->maximumY(); y++) {

            auto *tempPoint = new MyPoint2D(x, y);
            v = calNumeratorV(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            w = calNumeratorW(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            u = calU(v, w);

            if (pointIsInTriangle(u, v, w)) {
                double xt = u * (double) sourceTriangle->getPoint(0).getX() +
                            v * (double) sourceTriangle->getPoint(1).getX() +
                            w * (double) sourceTriangle->getPoint(2).getX();
                double yt = u * (double) sourceTriangle->getPoint(0).getY() +
                            v * (double) sourceTriangle->getPoint(1).getY() +
                            w * (double) sourceTriangle->getPoint(2).getY();

                auto *tempPoint2 = new MyPoint2D(xt, yt);

                QColor colorTemp = doubleLineInterpolation(sourceImg, tempPoint2->getX(), tempPoint2->getY());
                colorTemp.setRed(colorTemp.red() * val);
                colorTemp.setGreen(colorTemp.green() * val);
                colorTemp.setBlue(colorTemp.blue() * val);

                tempPoint->setPixel(texturedImg, colorTemp);

                delete tempPoint2;
            }

            delete tempPoint;
        }
    }
}

void TriangleTexturing::texturing(int sourceColor, QImage *texturedImg, Triangle *texturedTriangle) {
    double u, v, w;
    MyPoint2D *tempPoint, *tempPoint2;

    for (int x = texturedTriangle->minimumX(); x <= texturedTriangle->maximumX(); x++) {
        for (int y = texturedTriangle->minimumY(); y < texturedTriangle->maximumY(); y++) {

            tempPoint = new MyPoint2D(x, y);
            v = calNumeratorV(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            w = calNumeratorW(*texturedTriangle, *tempPoint) / calDenominatorVW(*texturedTriangle, *tempPoint);
            u = calU(v, w);

            if (pointIsInTriangle(u, v, w)) {
                tempPoint2 = new MyPoint2D(x, y);
                tempPoint->setPixel(texturedImg, sourceColor);
                delete tempPoint2;
            }

            delete tempPoint;
        }
    }
}


double TriangleTexturing::calDenominatorVW(Triangle triangle, const MyPoint2D& point) {
    return (double)(((triangle.getPoint(1).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(2).getY() - triangle.getPoint(0).getY())) -
                    ((triangle.getPoint(2).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(1).getY() - triangle.getPoint(0).getY())));
}

double TriangleTexturing::calNumeratorV(Triangle triangle, MyPoint2D point) {
    return (double)(((point.getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(2).getY() - triangle.getPoint(0).getY())) -
                    ((triangle.getPoint(2).getX() - triangle.getPoint(0).getX()) * (point.getY() - triangle.getPoint(0).getY())));
}

double TriangleTexturing::calNumeratorW(Triangle triangle, MyPoint2D point) {
    return (double)(((triangle.getPoint(1).getX() - triangle.getPoint(0).getX()) * (point.getY() - triangle.getPoint(0).getY())) -
                    ((point.getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(1).getY() - triangle.getPoint(0).getY())));
}

double TriangleTexturing::calU(double v, double w) {
    return 1.0 - v - w;
}

bool TriangleTexturing::pointIsInTriangle(double u, double v, double w) {
    return (u >= 0.0 && u <= 1 && v >= 0.0 && v <= 1 && w >= 0.0 && w <= 1);
}


QColor TriangleTexturing::doubleLineInterpolation(QImage *img, double x, double y) {

    if(floor(x) >= 0 && ceil(x) < img->width() && floor(y) >= 0 && ceil(y) < img->height()) {

        QColor point1Color = img->pixel(floor(x), ceil(y)),
               point2Color = img->pixel(ceil(x), ceil(y)),
               point3Color = img->pixel(ceil(x), floor(y)),
               point4Color = img->pixel(floor(x), floor(y));

        int red, green, blue;

        double a = x - floor(x);
        double b = y - floor(y);

        red = b * ((1.0 - a) * (double)point1Color.red() + a * (double)point2Color.red())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.red() + a * (double)point3Color.red());
        green = b * ((1.0 - a) * (double)point1Color.green() + a * (double)point2Color.green())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.green() + a * (double)point3Color.green());
        blue = b * ((1.0 - a) * (double)point1Color.blue() + a * (double)point2Color.blue())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.blue() + a * (double)point3Color.blue());

        return {red, green, blue};
    } else {
        return {0, 0, 0};
    }
}
