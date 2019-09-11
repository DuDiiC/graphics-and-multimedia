#include "includes/MyWidget.h"

const std::string SUN_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/sun.jpg";
const std::string MERCURY_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/mercury.jpg";
//const std::string MERCURY_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_mercury.jpg";
const std::string VENUS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/venus.jpg";
//const std::string VENUS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_venus.jpg";
const std::string EARTH_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/earth.jpg";
//const std::string EARTH_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_earth.jpg";
const std::string MARS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/mars.png";
//const std::string MARS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_mars.png";
const std::string JUPITER_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/jupiter.jpg";
//const std::string JUPITER_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_jupiter.jpg";
const std::string SATURN_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/saturn.jpg";
//const std::string SATURN_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_saturn.jpg";
const std::string URANUS_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/uranus.jpg";
const std::string NEPTUNE_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources/neptune.jpg";
//const std::string NEPTUNE_TEXTURE = "/home/maciejdudek/Pulpit/Fourth-Semester-Graphics/08.Solar-System-PROJECT/resources2/2k_neptune.jpg";

MyWidget::MyWidget(int width, int height) {

    img = new QImage(width, height, QImage::Format_RGB32);
    imgConst = new QImage(width, height, QImage::Format_RGB32);

    MilkyWay::draw(img, 1000);

    *imgConst = *img;

//    transformationMatrix = new TransformationMatrix4x4(0, 0, 0,
//                                                        0, 0, 0,
//                                                        1.0, 1.0, 1.0,
//                                                        0.0, 0.0, 0.0, img);
//    transformationMatrix->updateMatrix();

    setMatrices();
    setPlanets();
    setConstPlanets();

//    planets[0]->draw(img);
//    for(int i = 1; i < planets.size(); i++) {
//        planets[i]->draw(img, observer);
//        *planets[i] = *constPlanets[i];
//    }
//
//    repaint();
    updateImg();
}

MyWidget::~MyWidget() {
    delete img;
    delete imgConst;
//    delete transformationMatrix;
    for(auto & planet : planets) { delete planet; }
    for(auto & matrix : planetsMatrices) { delete matrix; }

    img = nullptr;
    imgConst = nullptr;
//    transformationMatrix = nullptr;
    for(auto & planet : planets) { planet = nullptr; }
    for(auto & matrix : planetsMatrices) { matrix = nullptr; }
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawImage(0, 0, *img);
}

void MyWidget::updateImg() {

    // sortowanie planet wedlug wspolrzednej z
    std::vector < std::pair < int, int > > planetsZ;
    for(int i = 0; i < planets.size(); i++) {
        planetsZ.emplace_back(i, planets[i]->getZ0());
    }
    std::sort(planetsZ.begin(), planetsZ.end(), sortingPlanets);

    *img = *imgConst;
//    planets[0]->draw(img);
//    *planets[0] = *constPlanets[0];
//    for(int i = 1; i < planets.size(); i++) {
//        planets[i]->draw(img, observer);
//        std::cout << planets[i]->getZ0() << std::endl;
//        *planets[i] = *constPlanets[i];
//    }
    // rysowanie planet
    for(int i = 0; i < planetsZ.size(); i++) {
        if(planetsZ[i].first == 0) {
            planets[planetsZ[i].first]->draw(img);
        } else {
            planets[planetsZ[i].first]->draw(img, observer);
        }
        *planets[planetsZ[i].first] = *constPlanets[planetsZ[i].first];
    }
    repaint();
}

void MyWidget::setPlanets() {
    planets.push_back(new Sphere(80, 25, 25, -1000, QImage(SUN_TEXTURE.c_str())));
    planets.push_back(new Sphere(10, 15, 15, -1000, QImage(MERCURY_TEXTURE.c_str()), 90, 12));
    planets.push_back(new Sphere(13, 15, 15, -1000, QImage(VENUS_TEXTURE.c_str()), 120, 15));
    planets.push_back(new Sphere(25, 25, 25, -1000, QImage(EARTH_TEXTURE.c_str()), 175, -12));
    planets.push_back(new Sphere(22, 15, 15, -1000, QImage(MARS_TEXTURE.c_str()), 240, 13));
    planets.push_back(new Sphere(45, 20, 20, -1000, QImage(JUPITER_TEXTURE.c_str()), 320, -14));
    planets.push_back(new Sphere(42, 20, 20, -1000, QImage(SATURN_TEXTURE.c_str()), 440, 11));
    planets.push_back(new Sphere(33, 15, 15, -1000, QImage(URANUS_TEXTURE.c_str()), 535, -12));
    planets.push_back(new Sphere(30, 15, 15, -1000, QImage(NEPTUNE_TEXTURE.c_str()), 630, 15));

    updatePlanets(planets);
}

void MyWidget::setConstPlanets() {
    constPlanets.push_back(new Sphere(80, 25, 25, -1000, QImage(SUN_TEXTURE.c_str())));
    constPlanets.push_back(new Sphere(10, 15, 15, -1000, QImage(MERCURY_TEXTURE.c_str()), 90, 12));
    constPlanets.push_back(new Sphere(13, 15, 15, -1000, QImage(VENUS_TEXTURE.c_str()), 120, 15));
    constPlanets.push_back(new Sphere(25, 25, 25, -1000, QImage(EARTH_TEXTURE.c_str()), 175, -12));
    constPlanets.push_back(new Sphere(22, 15, 15, -1000, QImage(MARS_TEXTURE.c_str()), 240, 13));
    constPlanets.push_back(new Sphere(45, 20, 20, -1000, QImage(JUPITER_TEXTURE.c_str()), 320, -14));
    constPlanets.push_back(new Sphere(42, 20, 20, -1000, QImage(SATURN_TEXTURE.c_str()), 440, 11));
    constPlanets.push_back(new Sphere(33, 15, 15, -1000, QImage(URANUS_TEXTURE.c_str()), 535, -12));
    constPlanets.push_back(new Sphere(30, 15, 15, -1000, QImage(NEPTUNE_TEXTURE.c_str()), 630, 15));

//    updatePlanets(constPlanets);
}

void MyWidget::updatePlanets(std::vector < Sphere* > planetsTemp) {
    planetsTemp[0]->updateValues(sunMatrix);
    for(int i = 1; i < planetsTemp.size(); i++) {
        planetsTemp[i]->updateValues(planetsMatrices[i - 1]);
    }
}

void MyWidget::setMatrices() {
    sunMatrix = new SunTransformationMatrix(M_PI/2.5, 0.0, 0.0);

    planetsMatrices.push_back(new PlanetTransformationMatrix(90, 12, 0, M_PI/3, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(120, 15, 0, M_PI/1.5, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(175, -12, 0, M_PI/2.5, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(240, 13, 0, M_PI/1.75, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(320, -14, 0, M_PI/3, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(440, 11, 0, M_PI/2.25, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(535, -12, 0, M_PI/1.75, 0.0, 0.0, 0.0));
    planetsMatrices.push_back(new PlanetTransformationMatrix(630, 15, 0, M_PI/2.5, 0.0, 0.0, 0.0));

    updateMatrices();
}

void MyWidget::updateMatrices() {
    sunMatrix->updateMatrix();
    for(auto & planetMatrix : planetsMatrices) {
        planetMatrix->updateMatrix();
    }
}

void MyWidget::animation() {

    long long val = 0;

    double EARTH_INTERVAL = 1.0;
    double alphaSun = 0.0;
    double alphaMercury = 0.0;
    double alphaVenus = 0.0;
    double alphaEarth = 0.0;
    double alphaMars = 0.0;
    double alphaJupiter = 0.0;
    double alphaSaturn = 0.0;
    double alphaUranus = 0.0;
    double alphaNeptune = 0.0;

    while(val < 25L) {
        QTime pause = QTime::currentTime().addMSecs(1);
        while(QTime::currentTime() < pause) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
        }
        val++;
        alphaSun += 0.5;
        alphaMercury += (EARTH_INTERVAL * 5.16);
        alphaVenus += (EARTH_INTERVAL * 3.623);
        alphaEarth += (EARTH_INTERVAL);
        alphaMars += (EARTH_INTERVAL * 0.831);
        alphaJupiter += (EARTH_INTERVAL * 0.683);
        alphaSaturn += (EARTH_INTERVAL * 0.584);
        alphaUranus += (EARTH_INTERVAL * 0.362);
        alphaNeptune += (EARTH_INTERVAL * 0.244);
        setSunRotationZ((int)alphaSun);
        setMercuryRotation((int)alphaMercury);
        setVenusRotation((int)alphaVenus);
        setEarthRotation((int)alphaEarth);
        setMarsRotation((int)alphaMars);
        setJupiterRotation((int)alphaJupiter);
        setSaturnRotation((int)alphaSaturn);
        setUranusRotation((int)alphaUranus);
        setNeptuneRotation((int)alphaNeptune);
//        updateMatrices();
        updateImg();
    }
}

void MyWidget::setSunRotationX(int value) {
    sunMatrix->setAlphaXFromDegrees(value);
    planets[0]->updateValues(sunMatrix);
//    constPlanets[0]->updateValues(sunMatrix);
//    updateImg();
}

void MyWidget::setSunRotationY(int value) {
    sunMatrix->setAlphaYFromDegrees(value);
    planets[0]->updateValues(sunMatrix);
//    constPlanets[0]->updateValues(sunMatrix);
//    updateImg();
}

void MyWidget::setSunRotationZ(int value) {
    sunMatrix->setAlphaZFromDegrees(value);
    planets[0]->updateValues(sunMatrix);
//    constPlanets[0]->updateValues(sunMatrix);
//    updateImg();
}

void MyWidget::setMercuryRotation(int value) {
    planetsMatrices[0]->setAlphaOFromDegrees(value);
    planetsMatrices[0]->setAlphaZFromDegrees(value);
    planets[1]->updateValues(planetsMatrices[0]);
//    transformationMatrix->setAlphaYFromDegrees(value);
//    planets[1]->updateValues(transformationMatrix);
//    constPlanets[1]->updateValues(planetsMatrices[0]);
//    updateImg();
}

void MyWidget::setVenusRotation(int value) {
    planetsMatrices[1]->setAlphaOFromDegrees(value);
    planetsMatrices[1]->setAlphaZFromDegrees(value);
    planets[2]->updateValues(planetsMatrices[1]);
//    updateImg();
}

void MyWidget::setEarthRotation(int value) {
    planetsMatrices[2]->setAlphaOFromDegrees(value);
    planetsMatrices[2]->setAlphaZFromDegrees(value);
    planets[3]->updateValues(planetsMatrices[2]);
//    updateImg();
}

void MyWidget::setMarsRotation(int value) {
    planetsMatrices[3]->setAlphaOFromDegrees(value);
    planetsMatrices[3]->setAlphaZFromDegrees(value);
    planets[4]->updateValues(planetsMatrices[3]);
//    updateImg();
}

void MyWidget::setJupiterRotation(int value) {
    planetsMatrices[4]->setAlphaOFromDegrees(value);
    planetsMatrices[4]->setAlphaZFromDegrees(value);
    planets[5]->updateValues(planetsMatrices[4]);
//    updateImg();
}

void MyWidget::setSaturnRotation(int value) {
    planetsMatrices[5]->setAlphaOFromDegrees(value);
    planetsMatrices[5]->setAlphaZFromDegrees(value);
    planets[6]->updateValues(planetsMatrices[5]);
//    updateImg();
}

void MyWidget::setUranusRotation(int value) {
    planetsMatrices[6]->setAlphaOFromDegrees(value);
    planetsMatrices[6]->setAlphaZFromDegrees(value);
    planets[7]->updateValues(planetsMatrices[6]);
//    updateImg();
}

void MyWidget::setNeptuneRotation(int value) {
    planetsMatrices[7]->setAlphaOFromDegrees(value);
    planetsMatrices[7]->setAlphaZFromDegrees(value);
    planets[8]->updateValues(planetsMatrices[7]);
//    updateImg();
}

