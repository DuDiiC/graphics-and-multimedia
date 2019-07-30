#include <qapplication.h>
#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>

#include "MyWidget.h"

void addBlendModes(QComboBox *comboBox);

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    widget->setMinimumWidth(800);
    widget->setMinimumHeight(500);

    // buttons to choose a layer
    QButtonGroup *layersGroup = new QButtonGroup();

    QRadioButton *layer1 = new QRadioButton("Layer 1");
    layer1->setMaximumSize(80, 30);
    layer1->setChecked(true);

    QRadioButton *layer2 = new QRadioButton("Layer 2");
    layer2->setMaximumSize(80, 30);

    QRadioButton *layer3 = new QRadioButton("Layer 3");
    layer3->setMaximumSize(80, 30);

    layersGroup->addButton(layer1);
    layersGroup->setId(layer1, 0);
    layersGroup->addButton(layer2);
    layersGroup->setId(layer2, 1);
    layersGroup->addButton(layer3);
    layersGroup->setId(layer3, 2);

    // container for buttons
    QHBoxLayout *radioButtons = new QHBoxLayout();
    radioButtons->addWidget(layer1);
    radioButtons->addWidget(layer2);
    radioButtons->addWidget(layer3);

    // comboBox to choose blend mode
    QComboBox *blendMode =new QComboBox();
    addBlendModes(blendMode);

    // slider for alpha value
    QHBoxLayout *alpha = new QHBoxLayout();
    QLabel *alphaText = new QLabel("alpha value");
    QSlider *alphaSlider = new QSlider(Qt::Horizontal);
    alphaSlider->setRange(0, 100);
    alphaSlider->setValue(100);
    alpha->addWidget(alphaText);
    alpha->addWidget(alphaSlider);

    // container for user interface elements
    QVBoxLayout *gui = new QVBoxLayout();
    gui->addLayout(radioButtons);
    gui->addWidget(blendMode);
    gui->addLayout(alpha);

    // widget with image
    MyWidget *myWidget = new MyWidget(layersGroup, blendMode, alphaSlider, 640, 480);

    // layout for all elements
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(myWidget, 800);
    layout->addLayout(gui);

    /* show app layout */
    widget->setLayout(layout);
    widget->show();

    /* connecting signals and slots for sliders */
    app.connect(alphaSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setAlpha(int)));
    app.connect(layersGroup, SIGNAL(buttonClicked(int)), myWidget, SLOT(setLayer(int)));
    app.connect(blendMode, SIGNAL(currentIndexChanged(int)), myWidget, SLOT(changeSelectedMode(int)));


    return app.exec();
}

void addBlendModes(QComboBox *comboBox) {
    comboBox->addItem("normal");
    comboBox->addItem("multiply");
    comboBox->addItem("screen");
    comboBox->addItem("overlay");
    comboBox->addItem("darken");
    comboBox->addItem("lighten");
    comboBox->addItem("difference");
    comboBox->addItem("additive");
    comboBox->addItem("subtractive");
}
