#include "includes/MyWidget.h"

#include <includes/MilkyWay.h>
#include <includes/Vector3D.h>

const std::string SUN_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/sun.jpg";
const std::string MERCURY_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/mercury.jpg";
const std::string VENUS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/venus.jpg";
const std::string EARTH_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/earth.jpg";
const std::string MARS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/mars.png";
const std::string JUPITER_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/jupiter.jpg";
const std::string SATURN_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/saturn.jpg";
const std::string URANUS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/uranus.jpg";
const std::string NEPTUNE_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/neptune.jpg";

MyWidget::MyWidget(int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    imgConst = new QImage(width, height, QImage::Format_RGB32);

    MilkyWay::draw(img, 1000);

    *imgConst = *img;

    transformationMatrix = new TransformationMatrix4x4(80, -80, 259,
                                                        0, 0, 0,
                                                        1.0, 1.0, 1.0,
                                                        M_PI/2, 0.0, 0.0, img);
    transformationMatrix->updateMatrix();

    setPlanets();
    setConstPlanets();
    observer[0] = planets[0]->getX0(); observer[1] = planets[0]->getY0(); observer[2] = planets[0]->getZ0();
//    Vector3D::normalize(observer, observer);

    planets[0]->draw(img);
    for(int i = 1; i < planets.size(); i++) {
        planets[i]->draw(img, observer);
        *planets[i] = *constPlanets[i];
    }

    repaint();
}

MyWidget::~MyWidget() {
    delete img;
    delete imgConst;
    delete transformationMatrix;
    for(auto & planet : planets) { delete planet; }

    img = nullptr;
    imgConst = nullptr;
    transformationMatrix = nullptr;
    for(auto & planet : planets) { planet = nullptr; }
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::updateImg() {

    *img = *imgConst;
    //MilkyWay::draw(img, 1000);
    planets[0]->draw(img);
    for(int i = 1; i < planets.size(); i++) {
        planets[i]->draw(img, observer);
        *planets[i] = *constPlanets[i];
    }
    repaint();
}

void MyWidget::setPlanets() {

    planets.push_back(new Sphere(80, 25, 25, 250, QImage(SUN_TEXTURE.c_str())));
    planets.push_back(new Sphere(10, 15, 15, 250, QImage(MERCURY_TEXTURE.c_str()), 50, 50));
    planets.push_back(new Sphere(13, 15, 15, 250, QImage(VENUS_TEXTURE.c_str()), 80, -80));
    planets.push_back(new Sphere(25, 15, 15, 250, QImage(EARTH_TEXTURE.c_str()), -135, -135));
    planets.push_back(new Sphere(20, 15, 15, 250, QImage(MARS_TEXTURE.c_str()), 175, 175));
    planets.push_back(new Sphere(45, 20, 20, 250, QImage(JUPITER_TEXTURE.c_str()), 215, 215));
    planets.push_back(new Sphere(42, 20, 20, 250, QImage(SATURN_TEXTURE.c_str()), -250, 250));
    planets.push_back(new Sphere(33, 15, 15, 250, QImage(URANUS_TEXTURE.c_str()), -280, -280));
    planets.push_back(new Sphere(30, 15, 15, 250, QImage(NEPTUNE_TEXTURE.c_str()), 320, -320));
}

void MyWidget::setConstPlanets() {
    constPlanets.push_back(new Sphere(80, 25, 25, 250, QImage(SUN_TEXTURE.c_str())));
    constPlanets.push_back(new Sphere(10, 15, 15, 250, QImage(MERCURY_TEXTURE.c_str()), 50, 50));
    constPlanets.push_back(new Sphere(13, 15, 15, 250, QImage(VENUS_TEXTURE.c_str()), 80, -80));
    constPlanets.push_back(new Sphere(25, 15, 15, 250, QImage(EARTH_TEXTURE.c_str()), -135, -135));
    constPlanets.push_back(new Sphere(20, 15, 15, 250, QImage(MARS_TEXTURE.c_str()), 175, 175));
    constPlanets.push_back(new Sphere(45, 20, 20, 250, QImage(JUPITER_TEXTURE.c_str()), 215, 215));
    constPlanets.push_back(new Sphere(42, 20, 20, 250, QImage(SATURN_TEXTURE.c_str()), -250, 250));
    constPlanets.push_back(new Sphere(33, 15, 15, 250, QImage(URANUS_TEXTURE.c_str()), -280, -280));
    constPlanets.push_back(new Sphere(30, 15, 15, 250, QImage(NEPTUNE_TEXTURE.c_str()), 320, -320));
}

void MyWidget::setXRotation(int value) {
    transformationMatrix->setAlphaXFromDegrees(value);
    planets[3]->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYRotation(int value) {
    transformationMatrix->setAlphaYFromDegrees(value);
    planets[3]->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZRotation(int value) {
    transformationMatrix->setAlphaZFromDegrees(value);
    planets[3]->updateValues(transformationMatrix);
    updateImg();
}