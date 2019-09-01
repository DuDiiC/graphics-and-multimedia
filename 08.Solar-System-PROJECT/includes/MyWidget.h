#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QSlider>
#include <QColor>
#include <QGenericMatrix>

#include <cmath>
#include <vector>
// FOR TESTS
#include <iostream>
#include <includes/Matrices/PlanetTransformationMatrix.h>

#include "MyPoint2D.h"
#include "Triangle.h"
#include "TriangleTexturing.h"
#include "includes/Matrices/TransformationMatrix4x4.h"
#include "Sphere.h"
#include "includes/Matrices/SunTransformationMatrix.h"

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

    void setXRotation(int value);
    void setYRotation(int value);
    void setZRotation(int value);

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

    void setPlanets();

    void setConstPlanets();

    void setMatrices();
};

#endif // MYWIDGET_H
