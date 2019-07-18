#include "MyWidget.h"

MyWidget::MyWidget() {
    img = new QImage(800, 600, QImage::Format_RGB32);
    img2 = new QImage(800, 600, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    lineSegment = new LineSegment();
    circle = new Circle();

    drawLine = false;
    drawCircle = false;
}

MyWidget::~MyWidget() {
	delete img;
    delete img2;
    delete myPoint;
    delete lineSegment;
    delete circle;

	img = NULL;
    img2 = NULL;
    myPoint = NULL;
    lineSegment = NULL;
    circle = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    myPoint->setXY(event->pos().x(), event->pos().y());

    if(event->button() == Qt::LeftButton) {
        drawLine = true;
        lineSegment->setStartPoint(event->pos());
    } else if(event->button() == Qt::MidButton) {
        drawCircle = true;
        circle->setCenterPoint(event->pos());
    } else if(event->button() == Qt::RightButton) {
        FloodFill::floodFill(img, event->pos());
        repaint();
        *img2 = *img;
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

    if(drawLine) {
        lineSegment->setEndPoint(event->pos());
        *img = *img2;
        lineSegment->draw(img);
        repaint();
    } else if(drawCircle) {
        circle->setPointOnCircle(event->pos());
        *img = *img2;
        circle->draw(img);
        repaint();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(drawLine) {
        lineSegment->setEndPoint(event->pos());
        lineSegment->draw(img2);
        repaint();
    } else if(drawCircle) {
        circle->setPointOnCircle(event->pos());
        circle->draw(img2);
    }
    drawLine = false;
    drawCircle = false;
}
