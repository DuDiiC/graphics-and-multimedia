#include "ScanLine.h"

void ScanLine::scanLine(QImage *image, int fillRGBColor) {

    MyPoint2D tempPoint, tempPoint2;

    for(int y = 0; y < image->height(); y++) { // dla kazdego wiersza
        bool drawing = false;
        bool finish = false;
        int xStart; int xEnd;
        for(int x = 0; x < image->width(); x++) { // dla kazdego punktu
            tempPoint.setXY(x, y);
            int color = tempPoint.getPixelRGBColor(image); // pobieramy informacje o kolorze
            if(color == fillRGBColor) { // jesli jest ten sam co kolor wypelnienia
                // jesli to nie pierwsza linia
                if(drawing) { // jesli juz byla krawedz startowa, ale nie bylo koncowej, to konczymy
                    drawing = false;
                    xEnd = x;
                    // rysujemy wszystkim punktom pomiedzy linie
                    for(int t = xStart; t <= xEnd; t++) {
                        if(y == 0) {
                            tempPoint.setX(t);
                            tempPoint.setPixel(image, fillRGBColor);
                        } else {
                            tempPoint2.setXY(t, y-1);
                            int upperColor = tempPoint2.getPixelRGBColor(image);
                            if(upperColor == fillRGBColor) {
                                tempPoint.setX(t);
                                tempPoint.setPixel(image, fillRGBColor);
                            }
                        }
                    }
                    while(tempPoint.getPixelRGBColor(image) == fillRGBColor && x < image->width()) {
                        x++;
                        tempPoint.setX(x);
                    }
                } else { // jesli jeszcze nie bylo krawedzi startowej, to ja zaczynamy
                    drawing = true;
                    // petla dopoki jest krawedz startowa
                    while(tempPoint.getPixelRGBColor(image) == fillRGBColor &&  x < image->width()) {
                        x++;
                        tempPoint.setX(x);
                    }
                    // jesli to nie koniec obrazka, to ustawiamy tu punkt startowy
                    if(x - 1 != image->width()) {
                        xStart = x;
                    }
                }
            }
        }
    }
}
