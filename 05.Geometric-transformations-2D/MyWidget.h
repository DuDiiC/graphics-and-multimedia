#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>

#include <cmath>
#include <vector>

#include "MyPoint2D.h"
#include "LineSegment.h"


class MyWidget : public QWidget {

    Q_OBJECT

    QImage *img;

public:

    MyWidget(int width = 800, int height = 600);

    ~MyWidget();

signals:

public slots:

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
