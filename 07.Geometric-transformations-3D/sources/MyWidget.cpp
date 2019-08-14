#include "includes/MyWidget.h"

MyWidget::MyWidget(std::vector < QSlider* > scalingSliders, int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    img2 = new QImage(width, height, QImage::Format_RGB32);

    *img2 = *img;

    // SET CORRECT VALUES
    transformationMatrix = new TransformationMatrix4x4(0, 0, 0, 1, 1, 1, 0.0, 0.0, 0.0, img);
    transformationMatrix->updateMatrix();

    cube = new Cube(50, 250);
    cubeConst = new Cube(50, 250);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    repaint();

    this->scalingSliders = scalingSliders;

}

MyWidget::~MyWidget() {

    delete img;
    delete img2;
    //delete transformationMatrix;
    delete cube;
    delete cubeConst;

    img = NULL;
    img2 = NULL;
    transformationMatrix = NULL;
    cube = NULL;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::updateImg() {
    // TODO:
    // ADD IMPLEMENTATION
}

void MyWidget::setXRotation(int value) {
    transformationMatrix->setAlphaXFromDegrees(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setYRotation(int value) {
    transformationMatrix->setAlphaYFromDegrees(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setZRotation(int value) {
    transformationMatrix->setAlphaZFromDegrees(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setXTranslation(int value) {
    transformationMatrix->setTX(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setYTranslation(int value) {
    transformationMatrix->setTY(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setZTranslation(int value) {
    transformationMatrix->setTZ(value);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setHomogeneousScaling(bool value) {

}

void MyWidget::setXScaling(int value) {
    transformationMatrix->setSX((double)value/100.0);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setYScaling(int value) {
    transformationMatrix->setSY((double)value/100.0);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}

void MyWidget::setZScaling(int value) {
    transformationMatrix->setSZ((double)value/100.0);
    cube->updateValues(transformationMatrix);
    cube->draw(img);
    *cube = *cubeConst;
    repaint();
}
