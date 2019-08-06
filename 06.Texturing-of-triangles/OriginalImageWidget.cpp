#include "OriginalImageWidget.h"

OriginalImageWidget::OriginalImageWidget(char* path) {

    img = new QImage(path);
    originalImage = new QImage(path);

    myPoint = new MyPoint2D();
    triangle = new Triangle();

    PATH = path;
}

OriginalImageWidget::~OriginalImageWidget() {

    delete img;
    delete myPoint;
    delete triangle;

    img = NULL;
    myPoint = NULL;
    triangle = NULL;
}

void OriginalImageWidget::reset() {

    img = new QImage(PATH);
    std::vector < MyPoint2D > newPoints;
    triangle->setPoints(newPoints);
    numberOfPoints = 0;
    pointIsChecked = false;
    TriangleTexturing::resetSourceTrianglePoints();
    repaint();
}

void OriginalImageWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void OriginalImageWidget::mousePressEvent(QMouseEvent *event) {

    myPoint->setXY(event->pos().x(), event->pos().y());
    int position = triangle->pointInSet(*myPoint, 4);

    if(position == -1) { // if we don't have that point, add it
        if(numberOfPoints != 3) { // if we need more points

            myPoint->enlarge(img, 4);

            triangle->addPoint(*myPoint);

            numberOfPoints++;
            TriangleTexturing::addSourceTrianglePoint();

            if(numberOfPoints == 3) {
                //triangle->draw(img);
                TriangleTexturing::texturing(img, *triangle, withTexturingTriangleWidget->getImg(), *(withTexturingTriangleWidget->getTriangle()));
            }
            repaint();
            withTexturingTriangleWidget->repaint();
        } else {
            pointIsChecked = true;
        }
    }
}

void OriginalImageWidget::mouseMoveEvent(QMouseEvent *event) {

    int position = triangle->pointInSet(*myPoint, 4);

    if(!pointIsChecked) {
        // clear image
        img = new QImage(PATH);

        myPoint->setXY(event->pos().x(),
                       event->pos().y());
        triangle->setPoint(position, *myPoint);

        // paint again
        for(int i = 0; i < triangle->getPoints().size(); i++) {
            triangle->getPoint(i).enlarge(img, 4);
        }
        if(numberOfPoints == 3) {
            //triangle->draw(img);
            TriangleTexturing::texturing(img, *triangle, withTexturingTriangleWidget->getImg(), *(withTexturingTriangleWidget->getTriangle()));
        }

        repaint();
        withTexturingTriangleWidget->repaint();
    }
}

void OriginalImageWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(pointIsChecked) pointIsChecked = false;
}
