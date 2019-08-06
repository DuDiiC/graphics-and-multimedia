#include <qapplication.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "OriginalImageWidget.h"
#include "WithTexturingTriangleWidget.h"

int main(int argc, char **argv ) {

    QApplication app( argc, argv );

    // main app widget
    QWidget *widget = new QWidget();
    widget->setMinimumWidth(1050);
    widget->setMinimumHeight(550);

    // --- WIDGETS WITH IMAGES ---
    OriginalImageWidget *originalImageWidget = new OriginalImageWidget("/home/maciejdudek/Pulpit/LGM koncowe/Fourth-Semester-Graphics/06.Texturing-of-triangles/resources/image2.jpg");
    originalImageWidget->setMinimumSize(500, 480);
    WithTexturingTriangleWidget *withTexturingTriangleWidget = new WithTexturingTriangleWidget(500, 480);
    withTexturingTriangleWidget->setMinimumSize(500, 480);

    originalImageWidget->setWithTexturingTriangleWidget(withTexturingTriangleWidget);
    withTexturingTriangleWidget->setOriginalImageWidget(originalImageWidget);

    // --- LAYOYUT FOR IMAGES ---
    QHBoxLayout *layoutForImages = new QHBoxLayout();

    layoutForImages->addWidget(originalImageWidget);
    layoutForImages->addWidget(withTexturingTriangleWidget);
    layoutForImages->setAlignment(Qt::AlignCenter);

    // --- RESET BUTTON ---
    QPushButton *resetButton = new QPushButton("RESET");
    resetButton->setMaximumWidth(100);

    // -- LAYOUT FOR RESET BUTTON
    QHBoxLayout *resetButtonLayout = new QHBoxLayout();
    resetButtonLayout->addWidget(resetButton);
    resetButtonLayout->setAlignment(Qt::AlignHCenter);

    // SET ALL IN LAYOUT
    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addLayout(layoutForImages);
    mainLayout->addLayout(resetButtonLayout);

    widget->setLayout(mainLayout);
    widget->show();

    // --- CONNECTING SIGNALS AND SLOTS ---
    app.connect(resetButton, SIGNAL(pressed()), originalImageWidget, SLOT(reset()));
    app.connect(resetButton, SIGNAL(pressed()), withTexturingTriangleWidget, SLOT(reset()));

    return app.exec();
}
