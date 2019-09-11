#include "MyWidget.h"

MyWidget::MyWidget(QSlider* scalingXS, QSlider* scalingYS, int width, int height) {

    img = new QImage("/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/05.Geometric-transformations-2D/resources/image.jpg");
    img2 = new QImage(width, height, QImage::Format_RGB32);

    *img2 = *img;

    scalingXSlider = scalingXS;
    scalingYSlider = scalingYS;

    transformationMartrix = new TransformationMatrix3x3(0, 0, 1.0, 1.0, 0.0, 0.0, 0.0, img);

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

void MyWidget::updateImg() {
    img->fill(Qt::black);
    for(int x = 0; x < img->width(); x++) {
        for(int y = 0; y < img->height(); y++) {

                MyPoint2D tempPoint(x, y);

                double tempPointTab[] = { x, y, 1 };

                QGenericMatrix<1, 3, double> tempPointM(tempPointTab);

                tempPointM = transformationMartrix->getTransformationMatrix() * tempPointM;

                QColor color(0, 0, 0);

                if(tempPointM.data()[0] >= 0 && tempPointM.data()[0] < img->width() && tempPointM.data()[1] >= 0 && tempPointM.data()[1] < img->height()-1) {
                    if(interpolationMode == NEAREST_NEIGHBOR) {
                        tempPoint.setXY(round(tempPointM.data()[0]), round(tempPointM.data()[1]));
                        color = tempPoint.getPixelRGBColor(img2);
                    } else if(interpolationMode == DOUBLE_LINE_INTERPOLATION) {
                        color = doubleLineInterpolation(img2, tempPointM.data()[0], tempPointM.data()[1]);
                    }

                }

                tempPoint.setXY(x, y);

                if(color.value() != 0x000000) {
                    tempPoint.setPixel(img, color);
                }
        }
    }
    repaint();
}

void MyWidget::setInterpolationMode(int index) {
    interpolationMode = (InterpolationMode)index;
    updateImg();
}

void MyWidget::setRotation(int value) {

    double alf = (double)value * M_PI/180.0;

    transformationMartrix->setAlpha(alf);

    updateImg();

}

void MyWidget::setXTranslation(int value) {
    transformationMartrix->setTX(value);
    updateImg();
}

void MyWidget::setYTranslation(int value) {
    transformationMartrix->setTY(value);
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
    updateImg();
}

void MyWidget::setYScaling(int value) {
    transformationMartrix->setSY((double)value/100.0);
    if(homogeneousScaling) {
        transformationMartrix->setSX((double)value/100.0);
        scalingXSlider->setValue(value);
    }
    updateImg();
}

void MyWidget::setXShearing(int value) {
    transformationMartrix->setSHX((double)value/100.0);
    updateImg();
}

void MyWidget::setYShearing(int value) {
    transformationMartrix->setSHY((double)value/100.0);
    updateImg();
}

QColor MyWidget::doubleLineInterpolation(QImage *img, double x, double y) {

    if(floor(x) >= 0 && ceil(x) < img->width() && floor(y) >= 0 && ceil(y) < img->height()) {

        QColor point1Color = img->pixel(floor(x), ceil(y)),
               point2Color = img->pixel(ceil(x), ceil(y)),
               point3Color = img->pixel(ceil(x), floor(y)),
               point4Color = img->pixel(floor(x), floor(y));

        int red, green, blue;

        double a = x - floor(x);
        double b = y - floor(y);

        red = b * ((1.0 - a) * (double)point1Color.red() + a * (double)point2Color.red())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.red() + a * (double)point3Color.red());
        green = b * ((1.0 - a) * (double)point1Color.green() + a * (double)point2Color.green())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.green() + a * (double)point3Color.green());
        blue = b * ((1.0 - a) * (double)point1Color.blue() + a * (double)point2Color.blue())
                    + (1.0 - b) * ((1.0 - a) * (double)point4Color.blue() + a * (double)point3Color.blue());

        return QColor(red, green, blue);
    } else {
        return QColor(0, 0, 0);
    }
}
