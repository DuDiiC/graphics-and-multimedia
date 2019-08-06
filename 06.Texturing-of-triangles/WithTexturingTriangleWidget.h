#ifndef WITHTEXTURINGTRIANGLEWIDGET_H
#define WITHTEXTURINGTRIANGLEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>

#include "MyPoint2D.h"
#include "Triangle.h"
#include "OriginalImageWidget.h"
#include "TriangleTexturing.h"

class OriginalImageWidget;

class WithTexturingTriangleWidget : public QWidget {

    Q_OBJECT

public:

    WithTexturingTriangleWidget(int width = 800, int height = 600);

    ~WithTexturingTriangleWidget();

    QImage* getImg() { return img; }

    Triangle* getTriangle() { return triangle; }

    void setOriginalImageWidget(OriginalImageWidget* originalImageWidget) {
        this->originalImageWidget = originalImageWidget;
    }

public slots:

    void reset();

protected:

    /**
     * This is event handler, which can repaint all or part of widget, when you invoke update() or repaint() methods
     * or when the widget was obscured and has now been uncovered.
     */
    void paintEvent(QPaintEvent*);

    /**
      * This is event handler, which is called, when you press mouse button.
      */
    void mousePressEvent(QMouseEvent* event);

    /**
     * This is event handler, which receive mouse move event for the widget. Mouse tracking is switched off, so this
     * handler is active, only when mouse button is pressed.
     *
     */
    void mouseMoveEvent(QMouseEvent* event);

    /**
      * This is event handler, which is called, when you release mouse button.
      */
    void mouseReleaseEvent(QMouseEvent* event);

private:

    QImage *img;

    MyPoint2D *myPoint;
    Triangle *triangle;

    OriginalImageWidget *originalImageWidget;

    bool pointIsChecked = false;
    int numberOfPoints = 0;
};

#endif // WITHTEXTURINGTRIANGLEWIDGET_H
