#include "MyWidget.h"
#include "MyPoint2D.h"

MyWidget::MyWidget() {
    img = new QImage(800,600,QImage::Format_RGB32);
    myPoint = new MyPoint2D();
}

MyWidget::~MyWidget() {
	delete img;
	img = NULL;
}

void MyWidget::paintEvent(QPaintEvent*) {

	QPainter p(this);
	p.drawImage(0, 0, *img);
}

void MyWidget::mouseMoveEvent(QMouseEvent* event) {

	QPoint P = event->pos();
	int x=P.x();
	int y=P.y();
    myPoint->setX(x);
    myPoint->setY(y);

	if (myPoint->isOnWidget(img))
        myPoint->setPixel(img, 0xFFFFFF);

	repaint();
}
