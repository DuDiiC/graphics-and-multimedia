#ifndef TRIANGLETEXTURING_H
#define TRIANGLETEXTURING_H

#include <QImage>
#include <QColor>

#include "includes/2D/MyPoint2D.h"
#include "includes/2D/Triangle.h"
#include "includes/3D/Triangle3D.h"
#include "includes/3D/Vector3D.h"

class TriangleTexturing  {

public:

    /**
     * metoda teksturujaca trojkaty
     * @param sourceImg - obrazek, z ktorego bedzie brana tekstura
     * @param sourceTriangle - trojkat wyznaczony na sourceImg
     * @param texturedImg - obrazek na ktorym bedzie nalozona tekstura
     * @param texturedTriangle - trojkat na texturedImg gdzie nalozona zostanie tekstura
     */
    static void texturing(QImage *sourceImg, Triangle *sourceTriangle, QImage *texturedImg, Triangle *texturedTriangle);

    /**
     * metoda teksturujaca trojkaty z uzyciem oswietlenia plaskiego
     * @param sourceImg - obrazek, z ktorego bedzie brana tekstura
     * @param sourceTriangle - trojkat wyznaczony na sourceImg
     * @param texturedImg - obrazek na ktorym bedzie nalozona tekstura
     * @param texturedTriangle - trojkat na texturedImg gdzie nalozona zostanie tekstura
     * @param lightVector - wektor swiatla punktowego
     */
    static void texturingWithFlatShading(QImage *sourceImg, Triangle *sourceTriangle,
                                        QImage *texturedImg, Triangle3D *texturedTriangle,
                                        double *lightVector);

    /**
     * metoda teksturujaca trojkaty z uzyciem oswietlenia Phonga
     * @param sourceImg - obrazek, z ktorego bedzie brana tekstura
     * @param sourceTriangle - trojkat wyznaczony na sourceImg
     * @param texturedImg - obrazek na ktorym bedzie nalozona tekstura
     * @param texturedTriangle - trojkat na texturedImg gdzie nalozona zostanie tekstura
     * @param lightVector - wektor swiatla punktowego
     */
    static void texturingWithPhongShading(QImage *sourceImg, Triangle *sourceTriangle,
                                        QImage *texturedImg, Triangle3D *texturedTriangle3D,
                                        double *lightVector);

    /**
     * metoda wypelniajaca trojkat kolorem podanym jako argument sourceColor
     */
    static void texturing(int sourceColor, QImage *texturedImg, Triangle *texturedTriangle);


//    static void texturingWithLighting(int sourceColor, QImage *texturedImg, Triangle3D *texturedTriangle,
//            double *observer, Lighting lighting, );

private:

    static double calDenominatorVW(Triangle triangle, const MyPoint2D& point);
    static double calNumeratorV(Triangle triangle, MyPoint2D point);
    static double calNumeratorW(Triangle triangle, MyPoint2D point);
    static double calU(double v, double w);
    /**
     * sprawdza czy punkt lezy wewnatrz trojkata
     */
    static bool pointIsInTriangle(double u, double v, double w);
    /**
     * interpolacja dwuliniowa koloru
     */
    static QColor doubleLineInterpolation(QImage *img, double x, double y);
};

#endif // TRIANGLETEXTURING_H
