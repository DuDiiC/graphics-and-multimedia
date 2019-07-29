#include "Layer.h"

Layer::Layer(int width, int height) {
    img = QImage(width, height, QImage::Format_RGB32);
    alpha = 100;
    blendMode = NORMAL;
}

Layer::~Layer() {
}
