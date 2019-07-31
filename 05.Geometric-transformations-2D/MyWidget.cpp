#include "MyWidget.h"

#include <iostream>

MyWidget::MyWidget(int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);

    drawFigure();
}

MyWidget::~MyWidget() {

    delete img;

    img = NULL;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::drawFigure() {

    std::vector < MyPoint2D* > points;

    LineSegment *tempLine = new LineSegment();

    MyPoint2D *tempPoint = new MyPoint2D(100, 90);
    points.push_back(tempPoint);

    tempPoint = new MyPoint2D(400, 90);
    points.push_back(tempPoint);

    tempPoint = new MyPoint2D(400, 390);
    points.push_back(tempPoint);

    tempPoint = new MyPoint2D(100, 390);
    points.push_back(tempPoint);

    for(int i = 0; i < points.size()-1; i++) {
        tempLine->setStartPoint(*(points[i]));
        tempLine->setEndPoint(*(points[i+1]));
        tempLine->draw(img);
    }

    tempLine->setStartPoint(*(points[points.size()-1]));
    tempLine->setEndPoint(*(points[0]));
    tempLine->draw(img);

    for(int i = 0; i < points.size(); i++) {
        delete points[i];
        points[i] = NULL;
    }
    delete tempLine;
    tempLine = NULL;

    repaint();


}
