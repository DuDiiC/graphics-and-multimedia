#include <qapplication.h>
#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "MyWidget.h"

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    widget->setMinimumWidth(700);
    widget->setMinimumHeight(500);


    MyWidget *myWidget = new MyWidget(640, 480);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(myWidget, 800);

    /* show app layout */
    widget->setLayout(layout);
    widget->show();

    /* connecting signals and slots for sliders */
    // ...
    // ...

    return app.exec();
}
