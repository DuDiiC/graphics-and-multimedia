#include <qapplication.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSlider>
#include <QCheckBox>
#include <QLabel>

#include "MyWidget.h"

int main(int argc, char **argv ) {

    QApplication app( argc, argv );

    // main app widget
    QWidget *widget = new QWidget();
    widget->setMinimumWidth(700);
    widget->setMinimumHeight(500);

    MyWidget *myWidget = new MyWidget(500, 480);

    // ---INTERPOLATION---
    // buttons to choose a interpolation mode
    QLabel *interpolationLabel = new QLabel("INTERPOLATION MODE");

    QRadioButton *nearestNeighborButton = new QRadioButton("nearest neighbor");
    nearestNeighborButton->setMaximumSize(200, 30);
    nearestNeighborButton->setChecked(true);

    QRadioButton *doubleLineInterpolationButton = new QRadioButton("double-line interpolation");
    doubleLineInterpolationButton->setMaximumSize(200, 30);

    QButtonGroup *interpolationButtonGroup = new QButtonGroup();
    interpolationButtonGroup->addButton(nearestNeighborButton);
    interpolationButtonGroup->setId(nearestNeighborButton, 0);
    interpolationButtonGroup->addButton(doubleLineInterpolationButton);
    interpolationButtonGroup->setId(doubleLineInterpolationButton, 1);

    QVBoxLayout *interpolationLayout = new QVBoxLayout();
    interpolationLayout->addWidget(interpolationLabel);
    interpolationLayout->addWidget(nearestNeighborButton);
    interpolationLayout->addWidget(doubleLineInterpolationButton);

    // ---ROTATION---
    QLabel *rotationLabel = new QLabel("ROTATION");

    QSlider *rotationSlider = new QSlider(Qt::Horizontal);
    rotationSlider->setRange(-360, 360); // TODO: set range

    // ---TRANSLATION---
    QLabel *translationLabel = new QLabel("TRANSLATION");

    QLabel *translationXLabel = new QLabel("x");
    QSlider *translationXSlider = new QSlider(Qt::Horizontal);
    //translationXSlider->setRange(); // TODO: set range

    QHBoxLayout *translationXLayout = new QHBoxLayout();
    translationXLayout->addWidget(translationXLabel);
    translationXLayout->addWidget(translationXSlider);

    QLabel *translationYLabel = new QLabel("y");
    QSlider *translationYSlider = new QSlider(Qt::Horizontal);
    //translationYSlider->setRange(); // TODO: set range

    QHBoxLayout *translationYLayout = new QHBoxLayout();
    translationYLayout->addWidget(translationYLabel);
    translationYLayout->addWidget(translationYSlider);

    // ---SCALING---
    QLabel *scalingLabel = new QLabel("SCALING");
    QCheckBox *homogeneousScalingCheckBox = new QCheckBox("homogeneous scaling");

    QLabel *scalingXLabel = new QLabel("x");
    QSlider *scalingXSlider = new QSlider(Qt::Horizontal);
    //scalingXSlider->setRange(); // TODO: set range

    QHBoxLayout *scalingXLayout = new QHBoxLayout();
    scalingXLayout->addWidget(scalingXLabel);
    scalingXLayout->addWidget(scalingXSlider);

    QLabel *scalingYLabel = new QLabel("y");
    QSlider *scalingYSlider = new QSlider(Qt::Horizontal);
    //scalingYSlider->setRange(); // TODO: set range

    QHBoxLayout *scalingYLayout = new QHBoxLayout();
    scalingYLayout->addWidget(scalingYLabel);
    scalingYLayout->addWidget(scalingYSlider);

    // ---SHEARING---
    QLabel *shearingLabel = new QLabel("SHEARING");

    QLabel *shearingXLabel = new QLabel("x");
    QSlider *shearingXSlider = new QSlider(Qt::Horizontal);
    //shearingXSlider->setRange(); // TODO: set range

    QHBoxLayout *shearingXLayout = new QHBoxLayout();
    shearingXLayout->addWidget(shearingXLabel);
    shearingXLayout->addWidget(shearingXSlider);

    QLabel *shearingYLabel = new QLabel("y");
    QSlider *shearingYSlider = new QSlider(Qt::Horizontal);
    //shearingYSlider->setRange(); // TODO: set range

    QHBoxLayout *shearingYLayout = new QHBoxLayout();
    shearingYLayout->addWidget(shearingYLabel);
    shearingYLayout->addWidget(shearingYSlider);

    // --- SET ALL IN LAYOUT ---
    QVBoxLayout *guiLayout = new QVBoxLayout();

    guiLayout->addLayout(interpolationLayout);

    guiLayout->addWidget(rotationLabel);
    guiLayout->addWidget(rotationSlider);

    guiLayout->addWidget(translationLabel);
    guiLayout->addLayout(translationXLayout);
    guiLayout->addLayout(translationYLayout);

    guiLayout->addWidget(scalingLabel);
    guiLayout->addWidget(homogeneousScalingCheckBox);
    guiLayout->addLayout(scalingXLayout);
    guiLayout->addLayout(scalingYLayout);

    guiLayout->addWidget(shearingLabel);
    guiLayout->addLayout(shearingXLayout);
    guiLayout->addLayout(shearingYLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(myWidget, 800);
    mainLayout->addLayout(guiLayout);

    widget->setLayout(mainLayout);

    widget->show();

    // --- CONNECTING SIGNALS AND SLOTS --
    app.connect(interpolationButtonGroup, SIGNAL(buttonClicked(int)), myWidget, SLOT(setInterpolationMode(int)));
    app.connect(rotationSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setRotation(int)));
    app.connect(translationXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXTranslation(int)));
    app.connect(translationYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYTranslation(int)));
    app.connect(homogeneousScalingCheckBox, SIGNAL(clicked(bool)), myWidget, SLOT(setHomogeneousScaling(bool)));
    app.connect(scalingXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXScaling(int)));
    app.connect(scalingYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYScaling(int)));
    app.connect(shearingXSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setXShearing(int)));
    app.connect(shearingYSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setYShearing(int)));

    return app.exec();
}
