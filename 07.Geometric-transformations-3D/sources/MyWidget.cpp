#include "includes/MyWidget.h"

#include <utility>

MyWidget::MyWidget(std::vector < QSlider* > scalingSliders, int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    imgConst = new QImage(width, height, QImage::Format_RGB32);

    *imgConst = *img;

    transformationMatrix = new TransformationMatrix4x4(0, 0, 0,
                                                        0, 0, 0,
                                                        1.0, 1.0, 1.0,
                                                        0.0, 0.0, 0.0, img);
    transformationMatrix->updateMatrix();

    cube = new Cube(50, 250, 0, 0, 0);
    cubeConst = new Cube(50, 250, 0, 0, 0);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    repaint();

    this->scalingSliders = std::move(scalingSliders);
}

MyWidget::~MyWidget() {
    delete img;
    delete imgConst;
    delete transformationMatrix;
    delete cube;
    delete cubeConst;

    img = nullptr;
    imgConst = nullptr;
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

void MyWidget::testVectors() const {/// test vectors
    MyPoint3D A(2,4,2,2);
    MyPoint3D B(3,1,2,1);
    MyPoint3D C(4, 1, 1, 4);
    double v1[3];
    double v2[3];
    double v3[3];
    double v4[3];
    Vector3D::createVector(A, B, v1);
    Vector3D::createVector(A, C, v2);
    Vector3D::crossProduct(v1, v2, v3);
    Vector3D::normalize(v3, v4);

    std::cout << "v1 = [" << v1[0] << ", " << v1[1] << ", " << v1[2] << "]" << std::endl;
    std::cout << "v2 = [" << v2[0] << ", " << v2[1] << ", " << v2[2] << "]" << std::endl;
    std::cout << "v1 x v2 = [" << v3[0] << ", " << v3[1] << ", " << v3[2] << "]" << std::endl;
    std::cout << "v1 * v2 = v3 = " << Vector3D::dotProduct(v1, v3) << std::endl;
    std::cout << "length(v3) = " << Vector3D::length(v3) << std::endl;
    std::cout << "normalize(v3) = v4 = [" << v4[0] << ", " << v4[1] << ", " << v4[2] << "]" << std::endl;
    std::cout << "length(v4) = " << Vector3D::length(v4) << std::endl;
}