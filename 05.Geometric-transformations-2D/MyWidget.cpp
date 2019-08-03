#include "MyWidget.h"

MyWidget::MyWidget(QSlider* scalingXS, QSlider* scalingYS, int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    img2 = new QImage(width, height, QImage::Format_RGB32);

    *img2 = *img;

    scalingXSlider = scalingXS;
    scalingYSlider = scalingYS;

    transformationMartrix = new TransformationMatrix3x3(0, 0, 1.0, 1.0, 0.0, 0.0, 0.0, img);

    drawFigure();
}

MyWidget::~MyWidget() {

    delete img;
    delete img2;
    delete transformationMartrix;

    img = NULL;
    img2 = NULL;
    transformationMartrix = NULL;
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
        tempLine->draw(img2);
    }

    tempLine->setStartPoint(*(points[points.size()-1]));
    tempLine->setEndPoint(*(points[0]));
    tempLine->draw(img2);

    for(int i = 0; i < points.size(); i++) {
        delete points[i];
        points[i] = NULL;
    }
    delete tempLine;
    tempLine = NULL;

    *img = *img2;

    repaint();


}

void MyWidget::updateImg() {
    img->fill(Qt::black);
    for(int x = 0; x < img->width(); x++) {
        for(int y = 0; y < img->height(); y++) {

            MyPoint2D tempPoint(x, y);

            if(tempPoint.getPixelRGBColor(img2) == 0xFFFFFF) {

                double tempPointTab[] = { x, y, 1 };

                QGenericMatrix<1, 3, double> tempPointM(tempPointTab);

                tempPointM = transformationMartrix->getTransformationMatrix() * tempPointM;

                if(interpolationMode == NEAREST_NEIGHBOR) {
                    tempPoint.setXY(round(tempPointM.data()[0]), round(tempPointM.data()[1]));
                } else if(interpolationMode == DOUBLE_LINE_INTERPOLATION) {
                    tempPoint.setXY(doubleLineInterpolation(tempPointM.data()[0]), doubleLineInterpolation(tempPointM.data()[1]));
                }

                tempPoint.setXY((int)tempPointM.data()[0], (int)tempPointM.data()[1]);

                tempPoint.setPixel(img);
            }
        }
    }
    repaint();
}

void MyWidget::setInterpolationMode(int index) {
    interpolationMode = (InterpolationMode)index;
}

void MyWidget::setRotation(int value) {

    double alf = (double)value * M_PI/180.0;

    transformationMartrix->setAlpha(alf);

    updateImg();

}

void MyWidget::setXTranslation(int value) {
    transformationMartrix->setTX(value);
    // multiply and repaint
    updateImg();
}

void MyWidget::setYTranslation(int value) {
    transformationMartrix->setTY(value);
    // multiply and repaint
    updateImg();
}

void MyWidget::setHomogeneousScaling(bool value) {
    homogeneousScaling = value;
}

void MyWidget::setXScaling(int value) {
    transformationMartrix->setSX((double)value/100.0);
    if(homogeneousScaling) {
        transformationMartrix->setSY((double)value/100.0);
        scalingYSlider->setValue(value);
    }
    // multiply and repaint
    updateImg();
}

void MyWidget::setYScaling(int value) {
    transformationMartrix->setSY((double)value/100.0);
    if(homogeneousScaling) {
        transformationMartrix->setSX((double)value/100.0);
        scalingXSlider->setValue(value);
    }
    // multiply and repaint
    updateImg();
}

// nie dziala wcale, nie wiem czemu
void MyWidget::setXShearing(int value) {
    transformationMartrix->setSHX((double)value/100.0);
    // multiply and repaint
    updateImg();
}

void MyWidget::setYShearing(int value) {
    transformationMartrix->setSHY((double)value/100.0);
    // multiply and repaint
    updateImg();
}

// TODO: ADD IMPLEMENTATION
double MyWidget::doubleLineInterpolation(double value) {
    return value;
}
