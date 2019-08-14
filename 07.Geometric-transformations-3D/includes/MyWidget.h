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

#include "MyPoint2D.h"
#include "Triangle.h"
#include "TriangleTexturing.h"
#include "TransformationMatrix4x4.h"
#include "includes/Cube.h"

class MyWidget : public QWidget {

    Q_OBJECT

    /**
     * img is a image after transformations
     */
    QImage *img;

    /**
     * img2 is a const image created after program launch
     */
    QImage *img2;

    Cube *cube;
    Cube *cubeConst;

    std::vector < QSlider* > scalingSliders;

    bool homogeneousScaling = false;

    TransformationMatrix4x4 *transformationMatrix;

public:
    MyWidget(std::vector < QSlider* > scalingSliders, int width = 800, int height = 600);

    ~MyWidget();

public slots:

    void setXRotation(int value);
    void setYRotation(int value);
    void setZRotation(int value);

    void setXTranslation(int value);
    void setYTranslation(int value);
    void setZTranslation(int value);

    void setHomogeneousScaling(bool value);

    void setXScaling(int value);
    void setYScaling(int value);
    void setZScaling(int value);

protected:

    /**
     * This is event handler, which can repaint all or part of widget, when you invoke update() or repaint() methods
     * or when the widget was obscured and has now been uncovered.
     */
    void paintEvent(QPaintEvent*);

private:

    /**
     * updateImg draws new image after transformations
     */
    void updateImg();
};

#endif // MYWIDGET_H
