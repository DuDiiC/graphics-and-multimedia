#include <qapplication.h>
#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>

#include "MyWidget.h"

void addBlendModes(QComboBox *comboBox);

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    widget->setMinimumWidth(800);
    widget->setMinimumHeight(500);

    // widget with image
    MyWidget *myWidget = new MyWidget(640, 480);

    // buttons to choose a layer
    QRadioButton *layer1 = new QRadioButton("Layer 1");
    layer1->setMaximumSize(80, 30);
    layer1->setChecked(true);

    QRadioButton *layer2 = new QRadioButton("Layer 2");
    layer2->setMaximumSize(80, 30);

    QRadioButton *layer3 = new QRadioButton("Layer 3");
    layer3->setMaximumSize(80, 30);

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

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(myWidget, 800);
    layout->addLayout(gui);

    /* show app layout */
    widget->setLayout(layout);
    widget->show();

    /* connecting signals and slots for sliders */
    // ...
    // ...

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
