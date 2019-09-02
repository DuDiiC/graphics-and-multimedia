#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
//#include <QSlider>
#include <QColor>
#include <QGenericMatrix>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>

#include <cmath>
#include <vector>

#include "includes/2D/MyPoint2D.h"
#include "includes/2D/Triangle.h"
#include "includes/3D/Vector3D.h"
#include "TriangleTexturing.h"
#include "includes/3D/Sphere.h"
#include <includes/Matrices/PlanetTransformationMatrix.h>
#include "includes/Matrices/TransformationMatrix4x4.h"
#include "includes/Matrices/SunTransformationMatrix.h"
#include "MilkyWay.h"

class MyWidget : public QWidget {

    Q_OBJECT

    /**
     * img is a image after transformations
     */
    QImage *img;

    /**
     * img2 is a const image created after program launch
     */
    QImage *imgConst;

    double observer[3] = { 0.0, 0.0, 0.0 };

    std::vector < Sphere* > planets;
    std::vector < Sphere* > constPlanets;

    TransformationMatrix4x4 *transformationMatrix;
    SunTransformationMatrix *sunMatrix;
    std::vector < PlanetTransformationMatrix* > planetsMatrices;

public:
    MyWidget(int width = 800, int height = 600);

    ~MyWidget();

public slots:

    /**
     * start animation
     */
    void animation();

    /**
     *
     * those slots set rotation parameters for each planet's matrix
     */
    void setSunRotationX(int value);
    void setSunRotationY(int value);
    void setSunRotationZ(int value);
    void setMercuryRotation(int value);
    void setVenusRotation(int value);
    void setEarthRotation(int value);
    void setMarsRotation(int value);
    void setJupiterRotation(int value);
    void setSaturnRotation(int value);
    void setUranusRotation(int value);
    void setNeptuneRotation(int value);

protected:

    /**
     * This is event handler, which can repaint all or part of widget, when you invoke update() or repaint() methods
     * or when the widget was obscured and has now been uncovered.
     */
    void paintEvent(QPaintEvent*) override;

private:

    /**
     * updateImg draws new image after transformations
     */
    void updateImg();

    inline static bool sortingPlanets(const std::pair < int, int > &a, const std::pair < int, int > &b) {
        return (a.second < b.second);
    }

    /**
     * ustawia wartosci poczatkowe dla obiektow odpowiadajacych planetom
     */
    void setPlanets();

    /**
     * ustawia wartosci poczatkowe dla stalych obiektow, odpowiadajacych planetom
     */
    void setConstPlanets();

    /**
     * aktualizuje pozycje planet na podstawie macierzy transformacji
     * @param planetsTemp
     */
    void updatePlanets(std::vector < Sphere* > planetsTemp);

    /**
     * ustawia wartosci macierzy transformacji poszczegolnych planet
     */
    void setMatrices();

    /**
     * aktualizuje wartosci macierzy transformacji poszczegolnych planet
     */
    void updateMatrices();
};

#endif // MYWIDGET_H
