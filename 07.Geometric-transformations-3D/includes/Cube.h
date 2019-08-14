#ifndef CUBE_H
#define CUBE_H

#include <QGenericMatrix>

#include "MyPoint3D.h"
#include "Triangle3D.h"
#include "TransformationMatrix4x4.h"

#include <vector>

class Cube {

public:
    Cube(int a, int d);
    Cube(int x, int y, int z, int d);
//    Cube(std::vector <MyPoint3D > pointsTemp) : points(pointsTemp);

    std::vector < Triangle3D > getTriangles() { return triangles; }
    std::vector < MyPoint3D > getPoints() { return points; }

    void draw(QImage* img, int RGBColor = 0xFFFFFF);

    void updateValues(TransformationMatrix4x4 *matrix);

private:

    static std::string IMAGE_PATHS[6];

    int x;
    int y;
    int z;
    int d;

    std::vector < MyPoint3D > points;
    std::vector < Triangle3D > triangles;

    /**
     * na podstawie wspolrzednych ustala wektor punktow i wektor trojkatow
     */
    void setValues();

    /**
     * deklaracja na sztywno wszystkich osmiu punktow budujacych kostke
     */
    void setPoints();

    /**
     * deklaracja na sztywno wszystkich dwunastu trojkatow budujacych kostke
     */
    void setTriangles();

    /**
     * metoda teksturujaca wszystkie sciany kostki
     */
    void texturingWalls(QImage* img);

    /**
     * metoda sprawdzajaca, czy dany trojkat zrzutowany na 2D jest widoczny dla obserwatora
     * @return prawda jesli widoczny, falsz w przeciwnym wypadku
     */
    bool isVisible(Triangle triangle);
};

#endif // CUBE_H
