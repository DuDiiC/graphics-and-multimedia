#ifndef ORIGINALIMAGEWIDGET_H
#define ORIGINALIMAGEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>

#include "MyPoint2D.h"
#include "Triangle.h"
#include "WithTexturingTriangleWidget.h"
#include "TriangleTexturing.h"

class WithTexturingTriangleWidget;

class OriginalImageWidget : public QWidget {

    Q_OBJECT

public:

    char* PATH;

    OriginalImageWidget(char* path);

    ~OriginalImageWidget();

    QImage* getImg() { return img; }
    QImage* getOriginalImage() { return originalImage; }

    Triangle* getTriangle() { return triangle; }

    void setWithTexturingTriangleWidget(WithTexturingTriangleWidget* withTexturingTriangleWidget) {
        this->withTexturingTriangleWidget = withTexturingTriangleWidget;
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
    QImage *originalImage;

    MyPoint2D *myPoint;
    Triangle *triangle;

    WithTexturingTriangleWidget *withTexturingTriangleWidget;

    bool pointIsChecked = false;
    int numberOfPoints = 0;
};

#endif // ORIGINALIMAGEWIDGET_H
