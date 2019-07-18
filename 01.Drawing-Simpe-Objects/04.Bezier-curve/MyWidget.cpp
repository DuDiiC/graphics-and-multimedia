#include "MyWidget.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    bezierCurve = new BezierCurve();
}

MyWidget::~MyWidget() {
	delete img;
    delete myPoint;
    delete bezierCurve;

	img = NULL;
    myPoint = NULL;
    bezierCurve = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    myPoint->setXY(event->pos().x(), event->pos().y());
    int position = bezierCurve->pointInSet(*myPoint, 4);

    if(position == -1) { // if we don't have that point, add it
        myPoint->enlarge(img, 4);

        bezierCurve->addPoint(*myPoint);

        if(bezierCurve->getBezierPoints().size()%3 == 1 && bezierCurve->getBezierPoints().size() != 1) {
            bezierCurve->draw(img);
        }
        repaint();
    } else {
        if(event->button() == Qt::LeftButton) {
            pointIsChecked = true;
        } else { // remove point

            myPoint->setXY(bezierCurve->getBezierPoints()[position].getX(),
                           bezierCurve->getBezierPoints()[position].getY());
            img->fill(Qt::black);

            bezierCurve->removePoint(*myPoint);
            for(int i = 0; i < bezierCurve->getBezierPoints().size(); i++) {
                bezierCurve->getBezierPoints()[i].enlarge(img, 4);
            }
            if(bezierCurve->getBezierPoints().size() > 3) {
                bezierCurve->draw(img);
            }
            repaint();
        }
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    int position = bezierCurve->pointInSet(*myPoint, 4);

    if(pointIsChecked) {
        // clear image
        img->fill(Qt::black);
        myPoint->setXY(event->pos().x(),
                       event->pos().y());
        bezierCurve->setBezierPoint(*myPoint, position);

        // paint again
        for(int i = 0; i < bezierCurve->getBezierPoints().size(); i++) {
            bezierCurve->getBezierPoints()[i].enlarge(img, 4);
        }
        bezierCurve->draw(img);

        repaint();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(pointIsChecked) pointIsChecked = false;
}
