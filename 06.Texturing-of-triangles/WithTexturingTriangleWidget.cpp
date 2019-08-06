#include "WithTexturingTriangleWidget.h"

WithTexturingTriangleWidget::WithTexturingTriangleWidget(int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);

    myPoint = new MyPoint2D();
    triangle = new Triangle();
}

WithTexturingTriangleWidget::~WithTexturingTriangleWidget() {

    delete img;
    delete myPoint;
    delete triangle;

    img = NULL;
    myPoint = NULL;
    triangle = NULL;
}

void WithTexturingTriangleWidget::reset() {

    img->fill(Qt::black);
    std::vector < MyPoint2D > newPoints;
    triangle->setPoints(newPoints);
    numberOfPoints = 0;
    pointIsChecked = false;
    TriangleTexturing::resetTexturedTrianglePoint();
    repaint();
}

void WithTexturingTriangleWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void WithTexturingTriangleWidget::mousePressEvent(QMouseEvent *event) {

    myPoint->setXY(event->pos().x(), event->pos().y());
    int position = triangle->pointInSet(*myPoint, 4);

    if(position == -1) { // if we don't have that point, add it
        if(numberOfPoints != 3) { // if we need more points

            myPoint->enlarge(img, 4);

            triangle->addPoint(*myPoint);

            numberOfPoints++;
            TriangleTexturing::addTexturedTrianglePoint();

            if(numberOfPoints == 3) {
                //triangle->draw(img);
                TriangleTexturing::texturing(originalImageWidget->getOriginalImage(), *(originalImageWidget->getTriangle()), img, *triangle);
            }
            repaint();
        } else {
            pointIsChecked = true;
        }
    }
}

void WithTexturingTriangleWidget::mouseMoveEvent(QMouseEvent *event) {

    int position = triangle->pointInSet(*myPoint, 4);

    if(!pointIsChecked) {
        // clear image
        img->fill(Qt::black);

        myPoint->setXY(event->pos().x(),
                       event->pos().y());
        triangle->setPoint(position, *myPoint);

        // paint again
        for(int i = 0; i < triangle->getPoints().size(); i++) {
            triangle->getPoint(i).enlarge(img, 4);
        }
        if(numberOfPoints == 3) {
            //triangle->draw(img);
            TriangleTexturing::texturing(originalImageWidget->getOriginalImage(), *(originalImageWidget->getTriangle()), img, *triangle);
        }
        repaint();
    }
}

void WithTexturingTriangleWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(pointIsChecked) pointIsChecked = false;
}
