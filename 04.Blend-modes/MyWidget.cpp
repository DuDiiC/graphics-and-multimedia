#include "MyWidget.h"

std::string MyWidget::IMAGE_PATHS[] = {
    "/home/maciejdudek/Pulpit/LGM koncowe/Fourth-Semester-Graphics/04.Blend-modes/resources/first.jpg",
    "/home/maciejdudek/Pulpit/LGM koncowe/Fourth-Semester-Graphics/04.Blend-modes/resources/second.jpg",
    "/home/maciejdudek/Pulpit/LGM koncowe/Fourth-Semester-Graphics/04.Blend-modes/resources/third.jpg"
};

MyWidget::MyWidget(int width, int height) {
    img = new QImage(width, height, QImage::Format_RGB32);

    selectedLayer = 0;
    selectedMode = NORMAL;

    for(int i = 0; i < 3; i++) {
        Layer layer(640, 480);
        layer.setImage(QImage(IMAGE_PATHS[i].c_str()));
        this->addLayer(layer);
    }

    layers[0].setBlendMode(NORMAL);
    layers[0].setAlpha(100);
    layers[1].setBlendMode(NORMAL);
    layers[1].setAlpha(50);
    layers[2].setBlendMode(NORMAL);
    layers[2].setAlpha(80);
    mixLayers();
}

MyWidget::~MyWidget() {
    delete img;
    img = NULL;
}

QImage* MyWidget::alphaBlending(QImage *image1, QImage *image2, int alpha) {

    int r, g, b;
    MyPoint2D tempPoint;

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    QColor colorImg1, colorImg2, colorImgResult;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = (int)((colorImg1.red() * (1-alpha/100.0)) + ((alpha/100.0) * colorImg2.red()));
            g = (int)((colorImg1.green() * (1-alpha/100.0)) + ((alpha/100.0) * colorImg2.green()));
            b = (int)((colorImg1.blue() * (1-alpha/100.0)) + ((alpha/100.0) * colorImg2.blue()));
            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::normalMode(QImage *image1, QImage *image2) {

    QImage *result = image2; /*new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);
            tempPoint.setPixel(result, tempPoint.getPixelRGBColor(image2));
        }
    }*/

    return result;
}

QImage* MyWidget::multiplyMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = ((colorImg1.red() * colorImg2.red()) >> 8);
            g = ((colorImg1.green() * colorImg2.green()) >> 8);
            b = ((colorImg1.blue() * colorImg2.blue()) >> 8);

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::screenMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = 255 - ((255 - colorImg1.red()) * (255 - colorImg2.red()) >> 8);
            g = 255 - ((255 - colorImg1.green()) * (255 - colorImg2.green()) >> 8);;
            b = 255 - ((255 - colorImg1.blue()) * (255 - colorImg2.blue()) >> 8);;

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::overlayMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = (colorImg1.red() < 128) ? ((colorImg1.red() * colorImg2.red()) >> 8) : (255 - ((255 - colorImg1.red()) * (255 - colorImg2.red()) >> 8));
            g = (colorImg1.green() < 128) ? ((colorImg1.green() * colorImg2.green()) >> 8) : (255 - ((255 - colorImg1.green()) * (255 - colorImg2.green()) >> 8));;
            b = (colorImg1.blue() < 128) ? ((colorImg1.blue() * colorImg2.blue()) >> 8) : (255 - ((255 - colorImg1.blue()) * (255 - colorImg2.blue()) >> 8));;

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::darkenMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = (colorImg1.red() < colorImg2.red()) ? colorImg1.red() : colorImg2.red();
            g = (colorImg1.green() < colorImg2.green()) ? colorImg1.green() : colorImg2.green();
            b = (colorImg1.blue() < colorImg2.blue()) ? colorImg1.blue() : colorImg2.blue();

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::lightenMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = (colorImg1.red() > colorImg2.red()) ? colorImg1.red() : colorImg2.red();
            g = (colorImg1.green() > colorImg2.green()) ? colorImg1.green() : colorImg2.green();
            b = (colorImg1.blue() > colorImg2.blue()) ? colorImg1.blue() : colorImg2.blue();

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::differenceMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = abs(colorImg1.red() - colorImg2.red());
            g = abs(colorImg1.green() - colorImg2.green());;
            b = abs(colorImg1.blue() - colorImg2.blue());;

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::additiveMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = std::min(colorImg1.red() + colorImg2.red(), 255);
            g = std::min(colorImg1.green() + colorImg2.green(), 255);;
            b = std::min(colorImg1.blue() + colorImg2.blue(), 255);;

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

QImage* MyWidget::subtractiveMode(QImage *image1, QImage *image2) {

    QImage *result = new QImage(image1->width(), image1->height(), QImage::Format_RGB32);
    MyPoint2D tempPoint;
    QColor colorImg1, colorImg2, colorImgResult;
    int r, g, b;

    for(int x = 0; x < result->width(); x++) {
        tempPoint.setX(x);
        for(int y = 0; y < result->height(); y++) {
            tempPoint.setY(y);

            colorImg1.setRgb(image1->pixel(x, y));
            colorImg2.setRgb(image2->pixel(x, y));

            r = std::max(colorImg1.red() + colorImg2.red() - 255, 0);
            g = std::max(colorImg1.green() + colorImg2.green() - 255, 0);;
            b = std::max(colorImg1.blue() + colorImg2.blue() - 255, 0);;

            colorImgResult.setRgb(r, g, b);

            tempPoint.setPixel(result, colorImgResult);
        }
    }

    return result;
}

void MyWidget::mixLayers() {

    QImage* temp = new QImage(img->width(), img->height(), QImage::Format_RGB32);

    img->fill(Qt::black);

    for(int i = 0; i < layers.size(); i++) {
        if(layers[i].getBlendMode() == NORMAL) {
            temp = normalMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == MULTIPLY) {
            temp = multiplyMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == SCREEN) {
            temp = screenMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == OVERLAY) {
            temp = overlayMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == DARKEN) {
            temp = darkenMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == LIGHTEN) {
            temp = lightenMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == DIFFERENCE) {
            temp = differenceMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == ADDITIVE) {
            temp = additiveMode(img, layers[i].getImage());
        } else if(layers[i].getBlendMode() == SUBTRACTIVE) {
            temp = subtractiveMode(img, layers[i].getImage());
        }

        img = alphaBlending(img, temp, layers[i].getAlpha());
    }
    repaint();
}

Layer MyWidget::getLayer(int index) {
    return this->layers[index];
}

void MyWidget::addLayer(Layer layer) {
    this->layers.push_back(layer);
}

void MyWidget::removeLayer(int index) {
    this->layers.erase(layers.begin()+index);
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::setAlpha(int value) {
    layers[selectedLayer].setAlpha(value);
    mixLayers();
}

void MyWidget::changeSelectedMode(int mode) {
    selectedMode = (BlendMode)mode;
    layers[selectedLayer].setBlendMode(selectedMode);
    mixLayers();
}
