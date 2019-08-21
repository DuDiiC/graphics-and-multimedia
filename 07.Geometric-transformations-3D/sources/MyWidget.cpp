#include "includes/MyWidget.h"

#include <utility>

MyWidget::MyWidget(std::vector < QSlider* > scalingSliders, int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    img2 = new QImage(width, height, QImage::Format_RGB32);

    *img2 = *img;

    transformationMatrix = new TransformationMatrix4x4(0, 0, 0,
                                                        0, 0, 0,
                                                        1.0, 1.0, 1.0,
                                                        0.0, 0.0, 0.0, img);
    transformationMatrix->updateMatrix();

    cube = new Cube(50, 250);
    cubeConst = new Cube(50, 250);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    repaint();

    this->scalingSliders = std::move(scalingSliders);
}

MyWidget::~MyWidget() {
    delete img;
    delete img2;
    delete transformationMatrix;
    delete cube;
    delete cubeConst;

    img = nullptr;
    img2 = nullptr;
    transformationMatrix = nullptr;
    cube = nullptr;
    cubeConst = nullptr;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::updateImg() {
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setXRotation(int value) {
    transformationMatrix->setAlphaXFromDegrees(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYRotation(int value) {
    transformationMatrix->setAlphaYFromDegrees(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZRotation(int value) {
    transformationMatrix->setAlphaZFromDegrees(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setXTranslation(int value) {
    transformationMatrix->setTX(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYTranslation(int value) {
    transformationMatrix->setTY(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZTranslation(int value) {
    transformationMatrix->setTZ(value);
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setHomogeneousScaling(bool value) {
    homogeneousScaling = value;
}

void MyWidget::setXScaling(int value) {
    transformationMatrix->setSX((double)value/100.0);
    if(homogeneousScaling) {
        transformationMatrix->setSY((double)value/100.0);
        scalingSliders[1]->setValue(value);
        transformationMatrix->setSZ((double)value/100.0);
        scalingSliders[2]->setValue(value);
    }
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYScaling(int value) {
    transformationMatrix->setSY((double)value/100.0);
    if(homogeneousScaling) {
        transformationMatrix->setSX((double)value/100.0);
        scalingSliders[0]->setValue(value);
        transformationMatrix->setSZ((double)value/100.0);
        scalingSliders[2]->setValue(value);
    }
    cube->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZScaling(int value) {
    transformationMatrix->setSZ((double)value/100.0);
    if(homogeneousScaling) {
        transformationMatrix->setSX((double)value/100.0);
        scalingSliders[0]->setValue(value);
        transformationMatrix->setSY((double)value/100.0);
        scalingSliders[1]->setValue(value);
    }
    cube->updateValues(transformationMatrix);
    updateImg();
}
