#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QString>
#include <QSlider>
#include <QComboBox>
#include <QButtonGroup>

#include <vector>
#include <cmath>
#include <algorithm>

#include "MyPoint2D.h"
#include "BlendMode.h"
#include "Layer.h"

class MyWidget : public QWidget {

    Q_OBJECT

    /**
     * IMAGE_PATHS - array with strings with paths to images for blending (default resolution 640 x 480 px)
     */
    static std::string IMAGE_PATHS[10];

    QImage *img;

    QButtonGroup *qLayers;
    QComboBox *qMode;
    QSlider *qAlpha;

    std::vector < Layer > layers;

    int selectedLayer;

    BlendMode selectedMode;

    /** -- BLEND MODES -- */
    /**
     * alphaBlending -  function to blend given images
     * @param image1 -  first (background layer) to blend
     * @param image2 -  second (foreground layer) to blend
     * @param alpha -   alpha value of image2
     * @return new image after alpha blending
     */
    QImage* alphaBlending(QImage *image1, QImage *image2, int alpha);

    /**
     * normalMode -     blend mode, in which the second image overwrites the first one
     */
    QImage* normalMode(QImage *image1, QImage *image2);

    /**
     * multiplyMode -   blend mode, in which a darker image is usually obtained
     */
    QImage* multiplyMode(QImage *image1, QImage *image2);

    /**
     * screenMode -     blend mode, in which a lighter image is usually obtained
     */
    QImage* screenMode(QImage *image1, QImage *image2);

    /**
     * overlayMode -    combination of multiply and screen modes, in which light fragments are lighter,
     *                  but dark ones are darker
     */
    QImage* overlayMode(QImage *image1, QImage *image2);

    /**
     * darkenMode -     using a darker of two colors
     */
    QImage* darkenMode(QImage *image1, QImage *image2);

    /**
     * lightenMode -    using a ligher of two colors
     */
    QImage* lightenMode(QImage *image1, QImage *image2);

    /**
     * differenceMode - using absolute value of difference between colors
     */
    QImage* differenceMode(QImage *image1, QImage *image2);

    /**
     * additiveMode -   using white or sum of two colors
     */
    QImage* additiveMode(QImage *image1, QImage *image2);

    /**
     * subtractiveMode - using diffrence between sum of colors and white or black
     */
    QImage* subtractiveMode(QImage *image1, QImage *image2);

public:

    MyWidget(QButtonGroup *qLayers, QComboBox *mode, QSlider *alpha, int width = 800, int height = 600);

    ~MyWidget();

    /**
     * mixLayers - function mixing all layers with layer's parameters
     */
    void mixLayers();

    void setSelectedLayer(int selectedLayer) { this->selectedLayer = selectedLayer; }
    int getSelectedLayer() { return this->selectedLayer; }

    void setSelectedMode(BlendMode selectedMode) { this->selectedMode = selectedMode; }
    BlendMode getselectedMode() { return this->selectedMode; }

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

    void setAlpha(int value);
    void setLayer(int layer);
    void changeSelectedMode(int mode);

};

#endif // MYWIDGET_H
