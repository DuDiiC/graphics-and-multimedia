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
    QWidget *widget = new QWidget();
    widget->setMinimumWidth(1000);
    widget->setMinimumHeight(625);

    // ---ROTATION---
    QLabel *rotationLabel = new QLabel("ROTATION");

    QLabel *rotationXLabel = new QLabel("x");
    QSlider *rotationXSlider = new QSlider(Qt::Horizontal);
    rotationXSlider->setRange(-180, 180);
    rotationXSlider->setValue(0);

    QHBoxLayout *rotationXLayout = new QHBoxLayout();
    rotationXLayout->addWidget(rotationXLabel);
    rotationXLayout->addWidget(rotationXSlider);

    QLabel *rotationYLabel = new QLabel("y");
    QSlider *rotationYSlider = new QSlider(Qt::Horizontal);
    rotationYSlider->setRange(-180, 180);
    rotationYSlider->setValue(0);

    QHBoxLayout *rotationYLayout = new QHBoxLayout();
    rotationYLayout->addWidget(rotationYLabel);
    rotationYLayout->addWidget(rotationYSlider);

    QLabel *rotationZLabel = new QLabel("z");
    QSlider *rotationZSlider = new QSlider(Qt::Horizontal);
    rotationZSlider->setRange(-180, 180);
    rotationZSlider->setValue(0);

    QHBoxLayout *rotationZLayout = new QHBoxLayout();
    rotationZLayout->addWidget(rotationZLabel);
    rotationZLayout->addWidget(rotationZSlider);

    QVBoxLayout *rotationLayout = new QVBoxLayout();
    rotationLayout->addWidget(rotationLabel);
    rotationLayout->addLayout(rotationXLayout);
    rotationLayout->addLayout(rotationYLayout);
    rotationLayout->addLayout(rotationZLayout);

    // ---TRANSLATION---
    QLabel *translationLabel = new QLabel("TRANSLATION");

    QLabel *translationXLabel = new QLabel("x");
    QSlider *translationXSlider = new QSlider(Qt::Horizontal);
    translationXSlider->setRange(-300, 300);
    translationXSlider->setValue(0);

    QHBoxLayout *translationXLayout = new QHBoxLayout();
    translationXLayout->addWidget(translationXLabel);
    translationXLayout->addWidget(translationXSlider);

    QLabel *translationYLabel = new QLabel("y");
    QSlider *translationYSlider = new QSlider(Qt::Horizontal);
    translationYSlider->setRange(-300, 300);
    translationYSlider->setValue(0);

    QHBoxLayout *translationYLayout = new QHBoxLayout();
    translationYLayout->addWidget(translationYLabel);
    translationYLayout->addWidget(translationYSlider);

    QLabel *translationZLabel = new QLabel("z");
    QSlider *translationZSlider = new QSlider(Qt::Horizontal);
    translationZSlider->setRange(-300, 300);
    translationZSlider->setValue(0);

    QHBoxLayout *translationZLayout = new QHBoxLayout();
    translationZLayout->addWidget(translationZLabel);
    translationZLayout->addWidget(translationZSlider);

    QVBoxLayout *translationLayout = new QVBoxLayout();
    translationLayout->addWidget(translationLabel);
    translationLayout->addLayout(translationXLayout);
    translationLayout->addLayout(translationYLayout);
    translationLayout->addLayout(translationZLayout);

    // ---SCALING---
    QLabel *scalingLabel = new QLabel("SCALING");
    QCheckBox *homogeneousScalingCheckBox = new QCheckBox("homogeneous scaling");

    QLabel *scalingXLabel = new QLabel("x");
    QSlider *scalingXSlider = new QSlider(Qt::Horizontal);
    scalingXSlider->setRange(0, 250);
    scalingXSlider->setValue(100);

    QHBoxLayout *scalingXLayout = new QHBoxLayout();
    scalingXLayout->addWidget(scalingXLabel);
    scalingXLayout->addWidget(scalingXSlider);

    QLabel *scalingYLabel = new QLabel("y");
    QSlider *scalingYSlider = new QSlider(Qt::Horizontal);
    scalingYSlider->setRange(0, 250);
    scalingYSlider->setValue(100);

    QHBoxLayout *scalingYLayout = new QHBoxLayout();
    scalingYLayout->addWidget(scalingYLabel);
    scalingYLayout->addWidget(scalingYSlider);

    QLabel *scalingZLabel = new QLabel("z");
    QSlider *scalingZSlider = new QSlider(Qt::Horizontal);
    scalingZSlider->setRange(0, 250);
    scalingZSlider->setValue(100);

    QHBoxLayout *scalingZLayout = new QHBoxLayout();
    scalingZLayout->addWidget(scalingZLabel);
    scalingZLayout->addWidget(scalingZSlider);

    QVBoxLayout *scalingLayout = new QVBoxLayout();
    scalingLayout->addWidget(scalingLabel);
    scalingLayout->addWidget(homogeneousScalingCheckBox);
    scalingLayout->addLayout(scalingXLayout);
    scalingLayout->addLayout(scalingYLayout);
    scalingLayout->addLayout(scalingZLayout);

    // --- MY WIDGET --
    std::vector < QSlider* > scalingSliders;
    scalingSliders.push_back(scalingXSlider);
    scalingSliders.push_back(scalingYSlider);
    scalingSliders.push_back(scalingZSlider);

    MyWidget *myWidget = new MyWidget(scalingSliders);

    // --- SET ALL IN LAYOUT ---
    QVBoxLayout *guiLayout = new QVBoxLayout();    

    guiLayout->addLayout(rotationLayout);
    guiLayout->addLayout(translationLayout);
    guiLayout->addLayout(scalingLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(myWidget, 1);
    mainLayout->addLayout(guiLayout);

    widget->setLayout(mainLayout);

    widget->show();

    // --- CONNECTING SIGNALS AND SLOTS --

    app.connect(rotationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXRotation(int)));
    app.connect(rotationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYRotation(int)));
    app.connect(rotationZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setZRotation(int)));
    app.connect(translationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXTranslation(int)));
    app.connect(translationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYTranslation(int)));
    app.connect(translationZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setZTranslation(int)));
    app.connect(scalingXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXScaling(int)));
    app.connect(scalingYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYScaling(int)));
    app.connect(scalingZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setZScaling(int)));


    return app.exec();
}
