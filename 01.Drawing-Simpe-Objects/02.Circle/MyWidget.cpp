#include "MyWidget.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    img2 = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    circle = new Circle();
}

MyWidget::~MyWidget() {
	delete img;
    delete img2;
    delete myPoint;
    delete circle;

	img = NULL;
    img2 = NULL;
    myPoint = NULL;
    circle = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    circle->setCenterPoint(event->pos());
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    circle->setPointOnCircle(event->pos());
    *img = *img2;
    circle->draw(img);
    repaint();
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    circle->setPointOnCircle(event->pos());
    circle->draw(img2);
    repaint();
}
