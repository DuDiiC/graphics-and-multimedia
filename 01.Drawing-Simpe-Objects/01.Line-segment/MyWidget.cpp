#include "MyWidget.h"
#include "MyPoint2D.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    img2 = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    lineSegment = new LineSegment();
}

MyWidget::~MyWidget() {
	delete img;
    delete img2;
    delete myPoint;
    delete lineSegment;

	img = NULL;
    img2 = NULL;
    myPoint = NULL;
    lineSegment = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    lineSegment->setStartPoint(event->pos());
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    lineSegment->setEndPoint(event->pos());

    *img = *img2;
    lineSegment->draw(img);
    repaint();
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    lineSegment->setEndPoint(event->pos());
    lineSegment->draw(img2);
    repaint();
}
