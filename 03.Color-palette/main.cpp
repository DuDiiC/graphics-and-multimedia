#include <qapplication.h>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "MyWidget.h"

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    widget->setMinimumWidth(475);
    widget->setMinimumHeight(275);

    MyWidget *myWidget = new MyWidget(256, 256);

    /* RGB labels and sliders */
    // R
    QLabel *rLabel = new QLabel("R");
    rLabel->setMaximumWidth(20);
    rLabel->setMaximumHeight(20);

    QSlider *rSlider = new QSlider(Qt::Horizontal);
    rSlider->setRange(0, 255);

    // G
    QLabel *gLabel = new QLabel("G");
    gLabel->setMaximumWidth(20);
    gLabel->setMaximumHeight(20);

    QSlider *gSlider = new QSlider(Qt::Horizontal);
    gSlider->setRange(0, 255);

    // B
    QLabel *bLabel = new QLabel("B");
    bLabel->setMaximumWidth(20);
    bLabel->setMaximumHeight(20);

    QSlider *bSlider = new QSlider(Qt::Horizontal);
    bSlider->setRange(0, 255);

    /* HSV labels and sliders */
    // H
    QLabel *hLabel = new QLabel("H");
    hLabel->setMaximumWidth(20);
    hLabel->setMaximumHeight(20);

    QSlider *hSlider = new QSlider(Qt::Horizontal);
    hSlider->setRange(0, 255);

    // S
    QLabel *sLabel = new QLabel("S");
    sLabel->setMaximumWidth(20);
    sLabel->setMaximumHeight(20);

    QSlider *sSlider = new QSlider(Qt::Horizontal);
    sSlider->setRange(0, 255);

    // V
    QLabel *vLabel = new QLabel("V");
    vLabel->setMaximumWidth(20);
    vLabel->setMaximumHeight(20);

    QSlider *vSlider = new QSlider(Qt::Horizontal);
    vSlider->setRange(0, 255);

    /* container for sliders */
    QVBoxLayout *sliders = new QVBoxLayout();
    QHBoxLayout *rHBox = new QHBoxLayout();
    rHBox->addWidget(rLabel);
    rHBox->addWidget(rSlider);
    sliders->addLayout(rHBox);

    QHBoxLayout *gHBox = new QHBoxLayout();
    gHBox->addWidget(gLabel);
    gHBox->addWidget(gSlider);
    sliders->addLayout(gHBox);

    QHBoxLayout *bHBox = new QHBoxLayout();
    bHBox->addWidget(bLabel);
    bHBox->addWidget(bSlider);
    sliders->addLayout(bHBox);

    QHBoxLayout *hHBox = new QHBoxLayout();
    hHBox->addWidget(hLabel);
    hHBox->addWidget(hSlider);
    sliders->addLayout(hHBox);

    QHBoxLayout *sHBox = new QHBoxLayout();
    sHBox->addWidget(sLabel);
    sHBox->addWidget(sSlider);
    sliders->addLayout(sHBox);

    QHBoxLayout *vHBox = new QHBoxLayout();
    vHBox->addWidget(vLabel);
    vHBox->addWidget(vSlider);
    sliders->addLayout(vHBox);

    /* container for everything */
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(myWidget, 800);
    layout->addLayout(sliders, 400);

    /* show app layout */
    widget->setLayout(layout);
    widget->show();

    /* connecting signals and slots for sliders */
    app.connect(rSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setR(int)));
    app.connect(gSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setG(int)));
    app.connect(bSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setB(int)));
    app.connect(hSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setH(int)));
    app.connect(sSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setS(int)));
    app.connect(vSlider, SIGNAL(valueChanged(int)), myWidget, SLOT(setV(int)));

    return app.exec();
}
