#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>

#include "MyPoint2D.h"
#include "ColorPallete.h"
#include "ColorPalleteVal.h"

class MyWidget : public QWidget {
    Q_OBJECT

    QImage *img;

    MyPoint2D *myPoint;
    QColor color;

public:

    MyWidget(int width = 800, int height = 600);

    ~MyWidget();

protected:

    /**
     * This is event handler, which can repaint all or part of widget, when you invoke update() or repaint() methods
     * or when the widget was obscured and has now been uncovered.
     */
    void paintEvent(QPaintEvent*);

public slots:

    /**
     * Slots used with sliders, in each case, value is a value of slider for RBG or HSV parameter.
     */
    void setR(int value);
    void setG(int value);
    void setB(int value);
    void setH(int value);
    void setS(int value);
    void setV(int value);

};

#endif // MYWIDGET_H
