#ifndef SPHERE_H
#define SPHERE_H

#include <QImage>

#include "MyPoint3D.h"
#include "Triangle3D.h"
#include "includes/2D/Triangle.h"
#include "Vector3D.h"
#include "includes/TriangleTexturing.h"
#include "includes/Matrices/TransformationMatrix4x4.h"
#include "includes/Matrices/SunTransformationMatrix.h"
#include "includes/Matrices/PlanetTransformationMatrix.h"

#include <vector>
#include <cmath>
#include <utility>

class Sphere {

public:
    Sphere(int R, int stacksCount, int sectorsCount, int d, QImage texture, int x0 = 0, int y0 = 0, int z0 = 0);

    const std::vector<MyPoint3D> &getPoints() const {return points;}

    const std::vector<Triangle3D> &getTriangles() const {return triangles;}

    int getX0() const { return x0; }

    int getY0() const { return y0; }

    int getZ0() const { return z0; }

    int getD() const { return d; }

    void draw(QImage* img, double* observer = nullptr, int RGBColor = 0xFFFFFF);

    /**
     * funkcje zmieniajace pozycje punktow sfery, w zaleznosci od podanej jako parametr macierzy
     */
    void updateValues(TransformationMatrix4x4 *matrix);
    void updateValues(PlanetTransformationMatrix *matrix);
    void updateValues(SunTransformationMatrix *matrix);

private:

    /**
     * obraz z tekstura, ktora bedzie zastosowana na sferze
     */
    QImage texture;

    /**
     * promien
     */
    int R;
    /**
     * ilosc podzialow pionowych
     */
    int stacksCount;
    /**
     * ilosc podzialow poziomych
     */
    int sectorsCount;
    /**
     * punkt obserwatora na osi z
     */
    int d;
    /**
     * punkt srodka kuli
     */
    int x0, y0, z0;

    /**
     * punkty kuli
     */
    std::vector < MyPoint3D > points;
    /**
     * trojkaty kuli
     */
    std::vector < Triangle3D > triangles;
    /**
     * wartosci przypisane do poszczegolnych punktow, dotyczace tekstur
     */
    std::vector < std::pair < double, double > > textureValues;
    /**
     * trojkaty, ktore uzywaja textureValues, przypisane w odpowiedni sposob
     */
    std::vector < Triangle > texturesPoints;

    /**
     * na podstawie wspolrzednych ustala wartosci punktow i trojkatow
     */
    void setValues();

    /**
     * ustawia punkty
     */
    void setPoints();

    /**
     * ustawia trojkaty na podstawie punktow
     */
    void setTriangles();

    /**
     * sprawdza czy dany trojkat bedzie widoczny dla obserwatora,
     * algortym https://en.wikipedia.org/wiki/Back-face_culling
     */
    static bool isVisible(Triangle3D *triangle3D);
};


#endif //SPHERE_H
