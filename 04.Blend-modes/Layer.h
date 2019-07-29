#ifndef LAYER_H
#define LAYER_H

#include <QImage>

#include "BlendMode.h"

class Layer {

    /**
     * color transparency factor (between [0; 100]
     */
    int alpha;

    BlendMode blendMode;

public:

    QImage img;

    Layer(int width = 800, int height = 600);

    ~Layer();

    QImage* getImage() { return &img; }
    void setImage(const QImage &image) { img = image; }

    int getAlpha() { return alpha; }
    void setAlpha(int alpha) { this->alpha = alpha; }

    BlendMode getBlendMode() { return blendMode; }
    void setBlendMode(BlendMode blendMode) { this->blendMode = blendMode; }

};

#endif // LAYER_H
