#include "MyWidget.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    bSplineCurve = new BSplineCurve();
}

MyWidget::~MyWidget() {
	delete img;
    delete myPoint;
    delete bSplineCurve;

	img = NULL;
    myPoint = NULL;
    bSplineCurve = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    myPoint->setXY(event->pos().x(), event->pos().y());
    int position = bSplineCurve->pointInSet(*myPoint, 4);

    if(position == -1) { // if we don't have that point, add it
        myPoint->enlarge(img, 4);

        bSplineCurve->addPoint(*myPoint);

        if(bSplineCurve->getBSplinePoints().size() > 3) {
            bSplineCurve->draw(img);
        }
        repaint();
    } else {
        if(event->button() == Qt::LeftButton) {
            pointIsChecked = true;
        } else { // remove point

            myPoint->setXY(bSplineCurve->getBSplinePoints()[position].getX(),
                           bSplineCurve->getBSplinePoints()[position].getY());
            img->fill(Qt::black);

            bSplineCurve->removePoint(*myPoint);
            for(int i = 0; i < bSplineCurve->getBSplinePoints().size(); i++) {
                bSplineCurve->getBSplinePoints()[i].enlarge(img, 4);
            }
            if(bSplineCurve->getBSplinePoints().size() > 3) {
                bSplineCurve->draw(img);
            }
            repaint();
        }
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    int position = bSplineCurve->pointInSet(*myPoint, 4);

    if(pointIsChecked) {
        // clear image
        img->fill(Qt::black);
        myPoint->setXY(event->pos().x(),
                       event->pos().y());
        bSplineCurve->setBSplinePoint(*myPoint, position);

        // paint again
        for(int i = 0; i < bSplineCurve->getBSplinePoints().size(); i++) {
            bSplineCurve->getBSplinePoints()[i].enlarge(img, 4);
        }
        bSplineCurve->draw(img);

        repaint();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(pointIsChecked) pointIsChecked = false;
}
