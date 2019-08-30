#include "includes/MyWidget.h"

#include <utility>

std::string PLANET_TEXTURE_PATHS[] = {
        "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/earth.jpg"
};

MyWidget::MyWidget(int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    //img = new QImage(PLANET_TEXTURE_PATHS[0].c_str());
    imgConst = new QImage(width, height, QImage::Format_RGB32);

    *imgConst = *img;

    transformationMatrix = new TransformationMatrix4x4(0, 0, 0,
                                                        0, 0, 0,
                                                        1.0, 1.0, 1.0,
                                                        M_PI/2, 0.0, 0.0, img);
    transformationMatrix->updateMatrix();

//    cube = new Cube(50, 250, 150, 120, 10);
//    cubeConst = new Cube(50, 250, 150, 120, 10);
//    cube->updateValues(transformationMatrix);
//    cube->draw(img);

    sphereEarth = new Sphere(100, 10, 10, 250, QImage(PLANET_TEXTURE_PATHS[0].c_str())/*, 200, 200, 0*/);
    sphereEarthConst = new Sphere(100, 10, 10, 250, QImage(PLANET_TEXTURE_PATHS[0].c_str())/*, 200, 200, 0*/);
    sphereEarth->updateValues(transformationMatrix);
    //sphereSun = new Sphere(100, 10, 10, 250);
    sphereEarth->draw(img);
    //sphereSun->draw(img);
    repaint();
}

MyWidget::~MyWidget() {
    delete img;
    delete imgConst;
    delete transformationMatrix;
//    delete cube;
//    delete cubeConst;
    delete sphereEarth;
    delete sphereEarthConst;

    img = nullptr;
    imgConst = nullptr;
    transformationMatrix = nullptr;
//    cube = nullptr;
//    cubeConst = nullptr;
    sphereEarth = nullptr;
    sphereEarthConst = nullptr;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::updateImg() {
//    cube->draw(img);
//    *cube = *cubeConst;
    img->fill(Qt::black);
    sphereEarth->draw(img);
    *sphereEarth = *sphereEarthConst;
    //sphereSun->draw(img);
    repaint();
}


void MyWidget::setXRotation(int value) {
    transformationMatrix->setAlphaXFromDegrees(value);
    sphereEarth->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYRotation(int value) {
    transformationMatrix->setAlphaYFromDegrees(value);
    sphereEarth->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZRotation(int value) {
    transformationMatrix->setAlphaZFromDegrees(value);
    sphereEarth->updateValues(transformationMatrix);
    updateImg();
}