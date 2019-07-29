#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QString>
#include <vector>
#include <cmath>
#include <algorithm>

#include "MyPoint2D.h"
#include "BlendMode.h"
#include "Layer.h"

class MyWidget : public QWidget {

    Q_OBJECT

    static std::string IMAGE_PATHS[10];

    QImage *img;
    QColor color;

    std::vector < Layer > layers;

    // blend modes
    QImage* alphaBlending(QImage *image1, QImage *image2, int alpha);
    QImage* normalMode(QImage *image1, QImage *image2);
    QImage* multiplyMode(QImage *image1, QImage *image2);
    QImage* screenMode(QImage *image1, QImage *image2);
    QImage* overlayMode(QImage *image1, QImage *image2);
    QImage* darkenMode(QImage *image1, QImage *image2);
    QImage* lightenMode(QImage *image1, QImage *image2);
    QImage* differenceMode(QImage *image1, QImage *image2);
    QImage* additiveMode(QImage *image1, QImage *image2);
    QImage* subtractiveMode(QImage *image1, QImage *image2);

public:

    MyWidget(int width = 800, int height = 600);

    ~MyWidget();

    void mixLayers();

    Layer getLayer(int index);

    void addLayer(Layer layer);

    void removeLayer(int index);


protected:

    /**
     * This is event handler, which can repaint all or part of widget, when you invoke update() or repaint() methods
     * or when the widget was obscured and has now been uncovered.
     */
    void paintEvent(QPaintEvent*);

signals:

public slots:
    // add more
};

#endif // MYWIDGET_H
