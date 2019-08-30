#include "includes/TriangleTexturing.h"
#include <iostream>

int TriangleTexturing::sourceTrianglePoints = 0;

int TriangleTexturing::texturedTrianglePoints = 0;

void TriangleTexturing::addSourceTrianglePoint() {
    sourceTrianglePoints++;
}

void TriangleTexturing::addTexturedTrianglePoint() {
    texturedTrianglePoints++;
}

void TriangleTexturing::resetSourceTrianglePoints() {
    sourceTrianglePoints = 0;
}
void TriangleTexturing::resetTexturedTrianglePoint() {
    texturedTrianglePoints = 0;
}

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
