#ifndef COLORPALLETE_H
#define COLORPALLETE_H

#include <QImage>
#include <QColor>

#include "ColorPalleteVal.h"
#include "MyPoint2D.h"

class ColorPallete {

public:

    /**
     * setPallete is a function, in whick you can draw color pallete for specified values.
     * @param image -
     * @param colorType - enum type with number of parameter (R, G, B, H, S or V)
     * @param colorVal - constant value between [0; 255] for colorType parameter
     */
    static void setPallete(QImage *image, ColorPalleteVal colorType, int colorVal);
};

#endif // COLORPALLETE_H
