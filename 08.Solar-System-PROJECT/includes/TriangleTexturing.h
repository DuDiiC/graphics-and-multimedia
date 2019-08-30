#ifndef TRIANGLETEXTURING_H
#define TRIANGLETEXTURING_H

#include <QImage>
#include <QColor>

#include "MyPoint2D.h"
#include "Triangle.h"
#include "Triangle3D.h"

class TriangleTexturing  {

public:

    static int sourceTrianglePoints, texturedTrianglePoints;

    static void addSourceTrianglePoint();
    static void addTexturedTrianglePoint();

    static void resetSourceTrianglePoints();
    static void resetTexturedTrianglePoint();

    static void texturing(QImage *sourceImg, Triangle *sourceTriangle, QImage *texturedImg, Triangle *texturedTriangle);
    static void texturing(int sourceColor, QImage *texturedImg, Triangle *texturedTriangle);


//    static void texturingWithLighting(int sourceColor, QImage *texturedImg, Triangle3D *texturedTriangle,
//            double *observer, Lighting lighting, );

private:

    static double calDenominatorVW(Triangle triangle, const MyPoint2D& point);
    static double calNumeratorV(Triangle triangle, MyPoint2D point);
    static double calNumeratorW(Triangle triangle, MyPoint2D point);
    static double calU(double v, double w);
    static bool pointIsInTriangle(double u, double v, double w);
    static QColor doubleLineInterpolation(QImage *img, double x, double y);
};

#endif // TRIANGLETEXTURING_H
