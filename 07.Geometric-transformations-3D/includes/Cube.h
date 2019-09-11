#ifndef CUBE_H
#define CUBE_H

#include <QGenericMatrix>

#include "MyPoint3D.h"
#include "Vector3D.h"
#include "Triangle3D.h"
#include "TransformationMatrix4x4.h"

#include <vector>

class Cube {

public:
    Cube(int a, int d, int x0, int y0, int z0);
    Cube(int x, int y, int z, int d, int x0, int y0, int z0);
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
    int x0, y0, z0;

    std::vector < MyPoint3D > points;
    std::vector < Triangle3D > triangles;

    double normalWallVectors[6][3];
    double normalTriangleVectors[12][3];
    double avgNormalVertexVectors[8][3];

    double observer[3];
    double lightSource[3];
    double lightSaturation[3]; // red, green, blue between [-1, 0]

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
     * ustawia wektory normalne dla kazdej sciany
     */
    void setWallVectors();

    void setTriangleVectors();

    /**
     * ustawia srednie wektory normalne dla kazdego wierzcholka
     */
    void setAvgVertexVectors();

    /**
     * metoda teksturujaca wszystkie sciany kostki
     */
    void texturingWalls(QImage* img, bool uniformColor = false, const int *colors = nullptr);

    /**
     * metoda sprawdzajaca, czy dany trojkat zrzutowany na 2D jest widoczny dla obserwatora
     * @return prawda jesli widoczny, falsz w przeciwnym wypadku
     */
    static bool isVisible(Triangle& triangle/*, int iWall, int iTriangle*/);


};

#endif // CUBE_H
