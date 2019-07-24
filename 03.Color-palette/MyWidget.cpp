#include "MyWidget.h"
#include <iostream>

MyWidget::MyWidget(int width, int height) {
    img = new QImage(width, height, QImage::Format_RGB32);
    myPoint = new MyPoint2D();
    color = QColor(0, 0, 0);
}

MyWidget::~MyWidget() {
    delete img;
    delete myPoint;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::setR(int value) {
    ColorPallete::setPallete(img, RGB_R, value);
    repaint();
}

void MyWidget::setG(int value) {
    ColorPallete::setPallete(img, RGB_G, value);
    repaint();
}

void MyWidget::setB(int value) {
    ColorPallete::setPallete(img, RGB_B, value);
    repaint();
}

void MyWidget::setH(int value) {
    ColorPallete::setPallete(img, HSV_H, value);
    repaint();
}

void MyWidget::setS(int value) {
    ColorPallete::setPallete(img, HSV_S, value);
    repaint();
}

void MyWidget::setV(int value) {
    ColorPallete::setPallete(img, HSV_V, value);
    repaint();
}
