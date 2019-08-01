#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>

#include <QGenericMatrix>

#include <cmath>
#include <vector>

#include "MyPoint2D.h"
#include "LineSegment.h"
#include "InterpolationMode.h"

class MyWidget : public QWidget {

    Q_OBJECT

    QImage *img;

    bool homogeneousScaling = false;

    InterpolationMode interpolationMode = NEAREST_NEIGHBOR;

    QGenericMatrix<3, 1, float> point;
    QGenericMatrix<3, 3, float> matrix;


public:

    MyWidget(int width = 800, int height = 600);

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
     * drawFigure draws simple figure (actual it is a square) on the image
     */
    void drawFigure();
};

#endif // MYWIDGET_H
