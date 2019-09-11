#include <iostream>
#include "includes/3D/Sphere.h"

Sphere::Sphere(int R, int stacksCount, int sectorsCount, int d, QImage texture, int x0, int y0, int z0) {
    this->R = R;
    this->stacksCount = stacksCount;
    this->sectorsCount = sectorsCount;
    this->d = d;
    this->texture = std::move(texture);
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;

    setValues();
}

void Sphere::draw(QImage *img, double* observer, int RGBColor) {

    //img->fill(Qt::black);

    // drawing textures
    int colors[6] = {
            0x550000, //red
            0x005500, //green
            0x000055, //blue
            0x555500, //yellow
            0x555555, //white
            0x550055 // pink
    };

    // vector odpowiedzialny za oswietlenie
    double lightVector[3];
    double sphereCenter[3] {
        static_cast<double>(x0), static_cast<double>(y0), static_cast<double>(z0)
    };
    Vector3D::normalize(sphereCenter, sphereCenter);
    if(observer != nullptr) { // jesli bedzie cieniowanie
        Vector3D::createVector(observer, sphereCenter, lightVector);
        Vector3D::normalize(lightVector, lightVector);
    }
    for(int i = 0; i < triangles.size(); i++) { // dla kazdego trojkata
        if(isVisible(&triangles[i])) { // jesli trojkat jest widoczny
            //kontury
            //triangles[i].changeInto2D()->draw(img, RGBColor);
            if(observer == nullptr) { // wersja bez cieniowania
                // tekstura
                TriangleTexturing::texturing(&texture, &texturesPoints[i], img, triangles[i].changeInto2D());
                //jednolite
                //TriangleTexturing::texturing(colors[0], img, triangles[i].changeInto2D());
            } else { // wersja z cieniowaniem
                TriangleTexturing::texturingWithFlatShading(&texture, &texturesPoints[i], img, &triangles[i], sphereCenter);
            }
        }
    }
}

void Sphere::updateValues(TransformationMatrix4x4 *matrix) {

    for(auto & point : points) { // dla kazdego punktu
        MyPoint3D newPoint;

        // zamiana na klase macierzy
        double tempPointTab[] = { (double)point.getX(), (double)point.getY(), (double)point.getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        // przemnozenie przez macierz transformacji
        tempPointM = *(matrix->getTransformationMatrix()) * tempPointM;

        // ustawienie nowych wartosci
        newPoint.setXYZ(tempPointM.data()[0], tempPointM.data()[1], tempPointM.data()[2]);
        newPoint.setD(d);

        point = newPoint;
    }
    // aktualizacja trojkatow
    setTriangles();

    // zamiana centrum sfery
    double center[] = {static_cast<double>(x0),  static_cast<double>(y0),  static_cast<double>(z0), 1.0};
    QGenericMatrix<1, 4, double> centerM(center);

    centerM = *(matrix->getTransformationMatrix()) * centerM;
    x0 = centerM.data()[0]; y0 = centerM.data()[1]; z0 = centerM.data()[2];
}

void Sphere::updateValues(PlanetTransformationMatrix *matrix) {
    for(auto & point : points) {
        MyPoint3D newPoint;

        double tempPointTab[] = { (double)point.getX(), (double)point.getY(), (double)point.getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        tempPointM = *(matrix->getPlanetTransformationMatrix()) * tempPointM;

        newPoint.setXYZ(tempPointM.data()[0], tempPointM.data()[1], tempPointM.data()[2]);
        newPoint.setD(d);

        point = newPoint;
    }
    setTriangles();

    double center[] = {static_cast<double>(x0),  static_cast<double>(y0),  static_cast<double>(z0), 1.0};
    QGenericMatrix<1, 4, double> centerM(center);

    centerM = *(matrix->getPlanetTransformationMatrix()) * centerM;
    x0 = centerM.data()[0]; y0 = centerM.data()[1]; z0 = centerM.data()[2];
}

void Sphere::updateValues(SunTransformationMatrix *matrix) {
    for(auto & point : points) {
        MyPoint3D newPoint;

        double tempPointTab[] = { (double)point.getX(), (double)point.getY(), (double)point.getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        tempPointM = *(matrix->getSunTransformationMatrix()) * tempPointM;

        newPoint.setXYZ(tempPointM.data()[0], tempPointM.data()[1], tempPointM.data()[2]);
        newPoint.setD(d);

        point = newPoint;
    }
    setTriangles();
}

void Sphere::setValues() {
    setPoints();
    setTriangles();
}

void Sphere::setPoints() {

    points.clear();
    normals.clear();
    textureValues.clear();

    double x, y, xy, z, s, t;
    double sectorStep = 2 * M_PI / sectorsCount;
    double stackStep = M_PI / stacksCount;
    double sectorAngle, stackAngle;

    for(int i = 0; i <= stacksCount; i++) {

        stackAngle = M_PI / 2.0 - i * stackStep; // dla wartosci w przedziale [-PI/2 ; PI/2]
        xy = R * cos(stackAngle);
        z = R * sin(stackAngle);

        for(int j = 0; j <= sectorsCount; j++) {

            sectorAngle = j * sectorStep; // dla wartosci w przedziale [0 ; 2*PI]

            // ustawianie poszczegolnych punktow bryly
            x = xy * cos(sectorAngle);
            y = xy * sin(sectorAngle);
            MyPoint3D tempPoint(x + x0, y + y0, z + z0, d);
            points.push_back(tempPoint);

            // ustawienie tym punktom wektorow normalnych
            double tempNormals[3] = { x, y, z };
            Vector3D::normalize(tempNormals, tempNormals);
            normals.push_back(tempNormals);


            // wyliczenie odpowiednich mnoznikow dla x oraz y tekstury, ktore
            // odpowiadaja danym punktom na sferze
            s = (double) j / sectorsCount;
            t = (double) i / stacksCount;
            std::pair < double, double > temp(s, t);
            textureValues.push_back(temp);
        }
    }
}

void Sphere::setTriangles() {

    triangles.clear();
    texturesPoints.clear();

    int k1, k2; // zmienne pomocnicze

    for(int i = 0; i < stacksCount; i++) {

        k1 = i * (sectorsCount + 1); // zaczynamy od aktualnego stosu
        k2 = k1 + sectorsCount + 1; // zaczynamy od jednego dalej

        for(int j = 0; j < sectorsCount; j++, k1++, k2++) {
            // nie liczac pierwszego i ostatniego stosu, mamy dwa trojkaty na sektor
            if(i != 0) { // kolejnosc k1 -> k2 -> k1+1
                // wrzucamy punkty i wektory normalne do vectorow
                std::vector < MyPoint3D > tempPoints;
                tempPoints.push_back(points[k2]); tempPoints.push_back(points[k1]); tempPoints.push_back(points[k1+1]);
                std::vector < double* > tempNormals;
                tempNormals.push_back(normals[k2]); tempNormals.push_back(normals[k1]); tempNormals.push_back(normals[k1+1]);
                Triangle3D tempTriangle(tempPoints, tempNormals);
                triangles.push_back(tempTriangle);

                // wyznaczenie trojkatow z tekstury odpowiadajacych tym na kuli
                MyPoint2D p1(textureValues[k2].first * texture.width(), textureValues[k2].second * texture.height());
                MyPoint2D p2(textureValues[k1].first * texture.width(), textureValues[k1].second * texture.height());
                MyPoint2D p3(textureValues[k1+1].first * texture.width(), textureValues[k1+1].second * texture.height());
                Triangle tempTexTriangle(p1, p2, p3);

                texturesPoints.push_back(tempTexTriangle);
            }
            if(i != (stacksCount -1)) { // kolejnosc k1+1 -> k2 -> k2+1
                // wrzucamy punkty i wektory normalne do vectorow
                std::vector < MyPoint3D > tempPoints;
                tempPoints.push_back(points[k2+1]); tempPoints.push_back(points[k2]); tempPoints.push_back(points[k1+1]);
                std::vector < double* > tempNormals;
                tempNormals.push_back(normals[k2+1]); tempNormals.push_back(normals[k2]); tempNormals.push_back(normals[k1+1]);
                Triangle3D tempTriangle(tempPoints, tempNormals);
                triangles.push_back(tempTriangle);

                // wyznaczenie punktow z tekstury odpowiadajacych tym na kuli
                MyPoint2D p1(textureValues[k2+1].first * texture.width(), textureValues[k2+1].second * texture.height());
                MyPoint2D p2(textureValues[k2].first * texture.width(), textureValues[k2].second * texture.height());
                MyPoint2D p3(textureValues[k1+1].first * texture.width(), textureValues[k1+1].second * texture.height());
                Triangle tempTexTriangle(p1, p2, p3);

                texturesPoints.push_back(tempTexTriangle);
            }
        }
    }
}

bool Sphere::isVisible(Triangle3D *triangle3D) {

    Triangle *triangle = triangle3D->changeInto2D();

    // wyliczenie jako wyznacznik macierzy z linku
    double result2 = ((triangle->getPoint(1).getX() - triangle->getPoint(0).getX()) * (triangle->getPoint(2).getY() - triangle->getPoint(0).getY()))
                     - ((triangle->getPoint(2).getX() - triangle->getPoint(0).getX()) * (triangle->getPoint(1).getY() - triangle->getPoint(0).getY()));
    return result2 < 0.0;
}
