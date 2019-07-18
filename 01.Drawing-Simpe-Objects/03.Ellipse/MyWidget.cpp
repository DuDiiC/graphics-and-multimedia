#include "MyWidget.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    img2 = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    ellipse = new Ellipse();
}

MyWidget::~MyWidget() {
	delete img;
    delete img2;
    delete myPoint;
    delete ellipse;

	img = NULL;
    img2 = NULL;
    myPoint = NULL;
    ellipse = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    ellipse->setCenterPoint(event->pos());
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    ellipse->setPointOnEllipse(event->pos());
    *img = *img2;
    ellipse->draw(img);
    repaint();
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    ellipse->setPointOnEllipse(event->pos());
    ellipse->draw(img2);
    repaint();
}
