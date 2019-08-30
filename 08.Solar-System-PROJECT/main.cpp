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
    widget->setMinimumWidth(1200);
    widget->setMinimumHeight(850);

    // ---ROTATION---
    QLabel *rotationLabel = new QLabel("ROTATION");

    QLabel *rotationXLabel = new QLabel("x");
    QSlider *rotationXSlider = new QSlider(Qt::Horizontal);
    rotationXSlider->setRange(-180, 180);
    rotationXSlider->setValue(90);

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

    // --- MY WIDGET --
    MyWidget *myWidget = new MyWidget(1000, 800);

    // --- SET ALL IN LAYOUT ---
    QVBoxLayout *guiLayout = new QVBoxLayout();

    guiLayout->addLayout(rotationLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(myWidget, 1);
    mainLayout->addLayout(guiLayout);

    widget->setLayout(mainLayout);

    widget->show();

    // --- CONNECTING SIGNALS AND SLOTS --
    app.connect(rotationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXRotation(int)));
    app.connect(rotationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYRotation(int)));
    app.connect(rotationZSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setZRotation(int)));

    return app.exec();
}
