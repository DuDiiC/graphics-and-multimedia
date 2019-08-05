#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QSlider>
#include <QColor>
#include <QGenericMatrix>

#include <cmath>

#include "TransformationMatrix3x3.h"
#include "MyPoint2D.h"
#include "InterpolationMode.h"

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

    QSlider *scalingXSlider, *scalingYSlider;

    bool homogeneousScaling = false;

    InterpolationMode interpolationMode = NEAREST_NEIGHBOR;

    TransformationMatrix3x3 *transformationMartrix;


public:

    MyWidget(QSlider* scalingXS, QSlider* scalingYS, int width = 800, int height = 600);

    ~MyWidget();

signals:

public slots:

    void setInterpolationMode(int index);

    void setRotation(int value);

    void setXTranslation(int value);

    void setYTranslation(int value);

    void setHomogeneousScaling(bool value);

    void setXScaling(int value);

    void setYScaling(int value);

    void setXShearing(int value);

    void setYShearing(int value);

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

    /**
     * function to calculate correct coordinates, when point doesn't have integer coordinates
     */
    QColor doubleLineInterpolation(QImage *img, double x, double y);
};

#endif // MYWIDGET_H
