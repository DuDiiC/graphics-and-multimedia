#include <qwidget.h>
#include <qimage.h>
#include <qpainter.h>
#include <QMouseEvent>
#include "MyPoint2D.h"
#include "BezierCurve.h"

class MyWidget : public QWidget {

    Q_OBJECT

    QImage *img;

    bool pointIsChecked = false;

    MyPoint2D *myPoint;
    BezierCurve *bezierCurve;

public:

    MyWidget();

    ~MyWidget();

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
};
