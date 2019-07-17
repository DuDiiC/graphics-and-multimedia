#include <qwidget.h>
#include <qimage.h>
#include <qpainter.h>
#include <QMouseEvent>
#include "MyPoint2D.h"

class MyWidget : public QWidget {

    Q_OBJECT

	QImage *img;

    MyPoint2D *myPoint;
	
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
     * This is event handler, which receive mouse move event for the widget. Mouse tracking is switched off default,
     * so this handler is active, only when mouse button is pressed.
     *
     */
    void mouseMoveEvent(QMouseEvent* event);
};
