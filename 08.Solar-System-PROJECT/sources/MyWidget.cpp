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

    transformationMatrix = new TransformationMatrix4x4(0, 0, 0,
                                                        0, 0, 0,
                                                        1.0, 1.0, 1.0,
                                                        0.0, 0.0, 0.0, img);
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

    planets.push_back(new Sphere(80, 25, 25, 1000, QImage(SUN_TEXTURE.c_str())));
    planets.push_back(new Sphere(10, 15, 15, 1000, QImage(MERCURY_TEXTURE.c_str()), 90, 12));
    planets.push_back(new Sphere(13, 15, 15, 1000, QImage(VENUS_TEXTURE.c_str()), 120, 15));
    planets.push_back(new Sphere(25, 25, 25, 1000, QImage(EARTH_TEXTURE.c_str()), 175, -12));
    planets.push_back(new Sphere(22, 15, 15, 1000, QImage(MARS_TEXTURE.c_str()), 240, 13));
    planets.push_back(new Sphere(45, 20, 20, 1000, QImage(JUPITER_TEXTURE.c_str()), 320, -14));
    planets.push_back(new Sphere(42, 20, 20, 1000, QImage(SATURN_TEXTURE.c_str()), 440, 11));
    planets.push_back(new Sphere(33, 15, 15, 1000, QImage(URANUS_TEXTURE.c_str()), 535, -12));
    planets.push_back(new Sphere(30, 15, 15, 1000, QImage(NEPTUNE_TEXTURE.c_str()), 630, 15));
}

void MyWidget::setConstPlanets() {
    constPlanets.push_back(new Sphere(80, 25, 25, 1000, QImage(SUN_TEXTURE.c_str())));
    constPlanets.push_back(new Sphere(10, 15, 15, 1000, QImage(MERCURY_TEXTURE.c_str()), 90, 12));
    constPlanets.push_back(new Sphere(13, 15, 15, 1000, QImage(VENUS_TEXTURE.c_str()), 120, 15));
    constPlanets.push_back(new Sphere(25, 25, 25, 1000, QImage(EARTH_TEXTURE.c_str()), 175, -12));
    constPlanets.push_back(new Sphere(22, 15, 15, 1000, QImage(MARS_TEXTURE.c_str()), 240, 13));
    constPlanets.push_back(new Sphere(45, 20, 20, 1000, QImage(JUPITER_TEXTURE.c_str()), 320, -14));
    constPlanets.push_back(new Sphere(42, 20, 20, 1000, QImage(SATURN_TEXTURE.c_str()), 440, 11));
    constPlanets.push_back(new Sphere(33, 15, 15, 1000, QImage(URANUS_TEXTURE.c_str()), 535, -12));
    constPlanets.push_back(new Sphere(30, 15, 15, 1000, QImage(NEPTUNE_TEXTURE.c_str()), 630, 15));
}

void MyWidget::setXRotation(int value) {
    transformationMatrix->setAlphaXFromDegrees(value);
    planets[6]->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setYRotation(int value) {
    transformationMatrix->setAlphaYFromDegrees(value);
    planets[6]->updateValues(transformationMatrix);
    updateImg();
}

void MyWidget::setZRotation(int value) {
    transformationMatrix->setAlphaZFromDegrees(value);
    planets[6]->updateValues(transformationMatrix);
    updateImg();
}