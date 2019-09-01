#include <qapplication.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSlider>
#include <QCheckBox>
#include <QLabel>

#include "includes/MyWidget.h"

int main(int argc, char **argv ) {

    QApplication app( argc, argv );

    // main app widget
    auto *widget = new QWidget();
    widget->setMinimumWidth(1650);
    widget->setMinimumHeight(850);

    /// ---SUN ROTATION---
    auto *sunRotationLabel = new QLabel("SUN ROTATION");

    auto *sunRotationXLabel = new QLabel("x");
    auto *sunRotationXSlider = new QSlider(Qt::Horizontal);
    sunRotationXSlider->setRange(-180, 180);
    sunRotationXSlider->setValue(0);

    auto *sunRotationXLayout = new QHBoxLayout();
    sunRotationXLayout->addWidget(sunRotationXLabel);
    sunRotationXLayout->addWidget(sunRotationXSlider);

    auto *sunRotationYLabel = new QLabel("y");
    auto *sunRotationYSlider = new QSlider(Qt::Horizontal);
    sunRotationYSlider->setRange(-180, 180);
    sunRotationYSlider->setValue(0);

    auto *sunRotationYLayout = new QHBoxLayout();
    sunRotationYLayout->addWidget(sunRotationYLabel);
    sunRotationYLayout->addWidget(sunRotationYSlider);


    auto *sunRotationZLabel = new QLabel("z");
    auto *sunRotationZSlider = new QSlider(Qt::Horizontal);
    sunRotationZSlider->setRange(-180, 180);
    sunRotationZSlider->setValue(0);

    auto *sunRotationZLayout = new QHBoxLayout();
    sunRotationZLayout->addWidget(sunRotationZLabel);
    sunRotationZLayout->addWidget(sunRotationZSlider);

    auto *sunRotationLayout = new QVBoxLayout();
    sunRotationLayout->addWidget(sunRotationLabel);
    sunRotationLayout->addLayout(sunRotationXLayout);
    sunRotationLayout->addLayout(sunRotationYLayout);
    sunRotationLayout->addLayout(sunRotationZLayout);

    /// ---PLANETS ORBITAL ROTATIONS---
    auto *planetsRotationLabel = new QLabel("PLANETS ORBITAL ROTATIONS");

    auto *mercuryRotationLabel = new QLabel("MERCURY");
    auto *mercuryRotationSlider = new QSlider(Qt::Horizontal);
    mercuryRotationSlider->setRange(-180, 180);
    mercuryRotationSlider->setValue(0);

    auto *mercuryRotationLayout = new QHBoxLayout();
    mercuryRotationLayout->addWidget(mercuryRotationLabel);
    mercuryRotationLayout->addWidget(mercuryRotationSlider);

    auto *venusRotationLabel = new QLabel("VENUS");
    auto *venusRotationSlider = new QSlider(Qt::Horizontal);
    venusRotationSlider->setRange(-180, 180);
    venusRotationSlider->setValue(0);

    auto *venusRotationLayout = new QHBoxLayout();
    venusRotationLayout->addWidget(venusRotationLabel);
    venusRotationLayout->addWidget(venusRotationSlider);

    auto *earthRotationLabel = new QLabel("EARTH");
    auto *earthRotationSlider = new QSlider(Qt::Horizontal);
    earthRotationSlider->setRange(-180, 180);
    earthRotationSlider->setValue(0);

    auto *earthRotationLayout = new QHBoxLayout();
    earthRotationLayout->addWidget(earthRotationLabel);
    earthRotationLayout->addWidget(earthRotationSlider);

    auto *marsRotationLabel = new QLabel("MARS");
    auto *marsRotationSlider = new QSlider(Qt::Horizontal);
    marsRotationSlider->setRange(-180, 180);
    marsRotationSlider->setValue(0);

    auto *marsRotationLayout = new QHBoxLayout();
    marsRotationLayout->addWidget(marsRotationLabel);
    marsRotationLayout->addWidget(marsRotationSlider);

    auto *jupiterRotationLabel = new QLabel("JUPITER");
    auto *jupiterRotationSlider = new QSlider(Qt::Horizontal);
    jupiterRotationSlider->setRange(-180, 180);
    jupiterRotationSlider->setValue(0);

    auto *jupiterRotationLayout = new QHBoxLayout();
    jupiterRotationLayout->addWidget(jupiterRotationLabel);
    jupiterRotationLayout->addWidget(jupiterRotationSlider);

    auto *saturnRotationLabel = new QLabel("SATURN");
    auto *saturnRotationSlider = new QSlider(Qt::Horizontal);
    saturnRotationSlider->setRange(-180, 180);
    saturnRotationSlider->setValue(0);

    auto *saturnRotationLayout = new QHBoxLayout();
    saturnRotationLayout->addWidget(saturnRotationLabel);
    saturnRotationLayout->addWidget(saturnRotationSlider);

    auto *uranusRotationLabel = new QLabel("URANUS");
    auto *uranusRotationSlider = new QSlider(Qt::Horizontal);
    uranusRotationSlider->setRange(-180, 180);
    uranusRotationSlider->setValue(0);

    auto *uranusRotationLayout = new QHBoxLayout();
    uranusRotationLayout->addWidget(uranusRotationLabel);
    uranusRotationLayout->addWidget(uranusRotationSlider);

    auto *neptuneRotationLabel = new QLabel("NEPTUNE");
    auto *neptuneRotationSlider = new QSlider(Qt::Horizontal);
    neptuneRotationSlider->setRange(-180, 180);
    neptuneRotationSlider->setValue(0);

    auto *neptuneRotationLayout = new QHBoxLayout();
    neptuneRotationLayout->addWidget(neptuneRotationLabel);
    neptuneRotationLayout->addWidget(neptuneRotationSlider);

    auto *planetsRotationLayout = new QVBoxLayout();
    planetsRotationLayout->addWidget(planetsRotationLabel);
    planetsRotationLayout->addLayout(mercuryRotationLayout);
    planetsRotationLayout->addLayout(venusRotationLayout);
    planetsRotationLayout->addLayout(earthRotationLayout);
    planetsRotationLayout->addLayout(marsRotationLayout);
    planetsRotationLayout->addLayout(jupiterRotationLayout);
    planetsRotationLayout->addLayout(saturnRotationLayout);
    planetsRotationLayout->addLayout(uranusRotationLayout);
    planetsRotationLayout->addLayout(neptuneRotationLayout);

    // ---ROTATION---
//    auto *rotationLabel = new QLabel("ROTATION");
//
//    auto *rotationXLabel = new QLabel("x");
//    auto *rotationXSlider = new QSlider(Qt::Horizontal);
//    rotationXSlider->setRange(-180, 180);
//    rotationXSlider->setValue(90);
//
//    auto *rotationXLayout = new QHBoxLayout();
//    rotationXLayout->addWidget(rotationXLabel);
//    rotationXLayout->addWidget(rotationXSlider);
//
//    auto rotationYLabel = new QLabel("y");
//    auto *rotationYSlider = new QSlider(Qt::Horizontal);
//    rotationYSlider->setRange(-180, 180);
//    rotationYSlider->setValue(0);
//
//    auto *rotationYLayout = new QHBoxLayout();
//    rotationYLayout->addWidget(rotationYLabel);
//    rotationYLayout->addWidget(rotationYSlider);
//
//    auto *rotationZLabel = new QLabel("z");
//    auto *rotationZSlider = new QSlider(Qt::Horizontal);
//    rotationZSlider->setRange(-180, 180);
//    rotationZSlider->setValue(0);
//
//    auto *rotationZLayout = new QHBoxLayout();
//    rotationZLayout->addWidget(rotationZLabel);
//    rotationZLayout->addWidget(rotationZSlider);
//
//    auto *rotationLayout = new QVBoxLayout();
//    rotationLayout->addWidget(rotationLabel);
//    rotationLayout->addLayout(rotationXLayout);
//    rotationLayout->addLayout(rotationYLayout);
//    rotationLayout->addLayout(rotationZLayout);

    // --- MY WIDGET --
    auto *myWidget = new MyWidget(1400, 800);

    // --- SET ALL IN LAYOUT ---
    auto *guiLayout = new QVBoxLayout();

    guiLayout->addLayout(sunRotationLayout);
    guiLayout->addLayout(planetsRotationLayout);
//    guiLayout->addLayout(rotationLayout);

    auto *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(myWidget, 1);
    mainLayout->addLayout(guiLayout);

    widget->setLayout(mainLayout);

    widget->show();

    // --- CONNECTING SIGNALS AND SLOTS --
//    QApplication::connect(rotationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXRotation(int)));
//    QApplication::connect(rotationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYRotation(int)));
//    QApplication::connect(rotationZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setZRotation(int)));
    QApplication::connect(sunRotationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setSunRotationX(int)));
    QApplication::connect(sunRotationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setSunRotationY(int)));
    QApplication::connect(sunRotationZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setSunRotationZ(int)));
    QApplication::connect(mercuryRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setMercuryRotation(int)));
    QApplication::connect(venusRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setVenusRotation(int)));
    QApplication::connect(earthRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setEarthRotation(int)));
    QApplication::connect(marsRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setMarsRotation(int)));
    QApplication::connect(jupiterRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setJupiterRotation(int)));
    QApplication::connect(saturnRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setSaturnRotation(int)));
    QApplication::connect(uranusRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setUranusRotation(int)));
    QApplication::connect(neptuneRotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setNeptuneRotation(int)));

    return QApplication::exec();
}
