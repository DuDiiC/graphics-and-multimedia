#ifndef MYPOINT_H
#define MYPOINT_H

#include <QImage>
#include <QColor>

/**
 * My own class for points in Qt library.
 */
class MyPoint2D {

private:
    /**
     * x coordinate
     */
    int x;

    /**
     * y coordinate
     */
    int y;

public:

    MyPoint2D() {}

    MyPoint2D(QPoint qP) : x(qP.x()), y(qP.y()) {}

    MyPoint2D(int xP, int yP) : x(xP), y(yP) {}

    ~MyPoint2D() {}

    int getX() { return this->x; }
    void setX(int x) { this->x = x; }

    int getY() { return this->y; }
    void setY(int y) { this->y = y; }

    void setXY(int x, int y) { this->x = x; this->y = y; }

    /**
     * Checks if the point is on QImage by coordinates.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @return true if point is on image or false in other case.
     */
    bool isOnWidget(QImage *image);

    /**
     * Compares points by coordinates.
     */
    friend bool operator==(const MyPoint2D& p1, const MyPoint2D& p2);

    /**
     * Changes color of the point.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param RGBcolor - the color to use
     */
    void setPixel(QImage *image, int RGBColor = 0xFFFFFF);

    /**
     * The same function as above, but using QColor class instead of hex int value for color.
     */
    void setPixel(QImage *image, QColor RGBColor);

    /**
     * Gives the pixel color.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @return integer value of color in RGB notation.
     */
    int getPixelRGBColor(QImage *image);

    /**
     * Creates a square around the point with given dimensions and color.
     * @param image - bits it's array of pixels on the screen in format providing access into single color in pixel
     * @param scale - distance from the center of the point to the edge of the new square
     * @param RGBColor - the color to use
     */
    void enlarge(QImage *image, int scale, int RGBColor = 0xFFFFFF);

    /**
     * Checks if the point is in the area on the widget.
     * @param point - center of the area to check
     * @param scale - distance from the center of the point, defining the space to be checked
     * @return true if the point is in the area, false in other case
     */
    bool isInArea(MyPoint2D point, int scale = 4);
};

#endif // MYPOINT_H
