#ifndef SPHERE_H
#define SPHERE_H

#include <QImage>

#include "MyPoint3D.h"
#include "Triangle3D.h"
#include "Triangle.h"
#include "TransformationMatrix4x4.h"

#include <vector>
#include <cmath>

class Sphere {

public:
    Sphere(int R, int stacksCount, int sectorsCount, int d, QImage texture, int x0 = 0, int y0 = 0, int z0 = 0);

    const std::vector<MyPoint3D> &getPoints() const {return points;}

    const std::vector<Triangle3D> &getTriangles() const {return triangles;}

    void draw(QImage* img, int RGBColor = 0xFFFFFF);

    void updateValues(TransformationMatrix4x4 *matrix);

private:

    QImage texture;

    int R; // promien
    int stacksCount; // ilosc podzialow pionowych
    int sectorsCount; // ilosc podzialow poziomych
    int d; // punkt obserwatora na osi z
    int x0, y0, z0; // punkt srodka kuli

    int TEX_WIDTH;
    int TEX_HEIGTH;

    std::vector < MyPoint3D > points; // punkty kuli
    std::vector < Triangle3D > triangles; // trojkaty kuli
    std::vector < std::pair < double, double > > textureValues; // wartosci przypisane do poszczegolnych punktow, dotyczace tekstur
    std::vector < Triangle > texturesPoints;

    // na podstawie wspolrzednych ustala wartosci punktow i trojkatow
    void setValues();

    // ustawia same punkty
    void setPoints();

    // ustawia same trojkaty na podstawie punktow
    void setTriangles();

    // teksturowanie trojkatow kuli
    void texturingWalls(QImage* img, bool uniformColor = false, const int *colors = nullptr);

    static bool isVisible(Triangle3D *triangle3D);
};


#endif //SPHERE_H
