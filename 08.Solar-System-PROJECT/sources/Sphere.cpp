#include "includes/Sphere.h"

#include <iostream>

#include <utility>
#include <includes/TriangleTexturing.h>
#include <includes/Vector3D.h>

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

    //texturingWalls(img, true, colors);

    double lightVector[3];
    double sphereCenter[3] {
        static_cast<double>(x0), static_cast<double>(y0), static_cast<double>(z0)
    };
    Vector3D::normalize(sphereCenter, sphereCenter);
    if(observer != nullptr) {
        Vector3D::createVector(observer, sphereCenter, lightVector);
        Vector3D::normalize(lightVector, lightVector);
        std::cout << lightVector[0] << " " << lightVector[1] << " " << lightVector[2] << std::endl;
    }
    for(int i = 0; i < triangles.size(); i++) {
        if(isVisible(&triangles[i])) {
            //triangles[i].changeInto2D()->draw(img, RGBColor);
            if(observer == nullptr) {
                TriangleTexturing::texturing(&texture, &texturesPoints[i], img, triangles[i].changeInto2D());
                //TriangleTexturing::texturing(colors[0], img, triangles[i].changeInto2D());
            } else {
                TriangleTexturing::texturingWithFlatShading(&texture, &texturesPoints[i], img, &triangles[i], sphereCenter);
            }
        }
    }
    //TriangleTexturing::texturing(&texture, &texturesPoints[0], img, triangles[0].changeInto2D());
}

void Sphere::updateValues(TransformationMatrix4x4 *matrix) {
    for(auto & point : points) {
        MyPoint3D newPoint;

        double tempPointTab[] = { (double)point.getX(), (double)point.getY(), (double)point.getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        tempPointM = *(matrix->getTransformationMatrix()) * tempPointM;

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
    textureValues.clear();

    double x, y, xy, z, s, t;
    double sectorStep = 2 * M_PI / sectorsCount;
    double stackStep = M_PI / stacksCount;
    double sectorAngle, stackAngle;

    for(int i = 0; i <= stacksCount; i++) {

        stackAngle = M_PI / 2.0 - i * stackStep;
        xy = R * cos(stackAngle);
        z = R * sin(stackAngle);

        for(int j = 0; j <= sectorsCount; j++) {

            sectorAngle = j * sectorStep;

            x = xy * cos(sectorAngle);
            y = xy * sin(sectorAngle);
            MyPoint3D tempPoint(x + x0, y + y0, z + z0, d);
            points.push_back(tempPoint);

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

    int k1, k2;

    for(int i = 0; i < stacksCount; i++) {

        k1 = i * (sectorsCount + 1);
        k2 = k1 + sectorsCount + 1;

        for(int j = 0; j < sectorsCount; j++, k1++, k2++) {
            if(i != 0) {
                Triangle3D tempTriangle(points[k2], points[k1], points[k1+1]);
                triangles.push_back(tempTriangle);

                MyPoint2D p1(textureValues[k2].first * texture.width(), textureValues[k2].second * texture.height());
                MyPoint2D p2(textureValues[k1].first * texture.width(), textureValues[k1].second * texture.height());
                MyPoint2D p3(textureValues[k1+1].first * texture.width(), textureValues[k1+1].second * texture.height());
                Triangle tempTexTriangle(p1, p2, p3);

                texturesPoints.push_back(tempTexTriangle);
            }
            if(i != (stacksCount -1)) {
                Triangle3D tempTriangle(points[k2+1], points[k2], points[k1+1]);
                triangles.push_back(tempTriangle);

                MyPoint2D p1(textureValues[k2+1].first * texture.width(), textureValues[k2+1].second * texture.height());
                MyPoint2D p2(textureValues[k2].first * texture.width(), textureValues[k2].second * texture.height());
                MyPoint2D p3(textureValues[k1+1].first * texture.width(), textureValues[k1+1].second * texture.height());
                Triangle tempTexTriangle(p1, p2, p3);

                texturesPoints.push_back(tempTexTriangle);
            }
        }
    }
}

void Sphere::texturingWalls(QImage *img, bool uniformColor, const int *colors) {
    return;
}

bool Sphere::isVisible(Triangle3D *triangle3D) {

    Triangle *triangle = triangle3D->changeInto2D();

//    MyPoint3D observer(0, 0, d, d);
//
//    double observerB[3];
//    Vector3D::createVector(triangles[iTriangle].getPoint(1), observer, observerB);
//
//    double observerBNormal[3];
//    Vector3D::normalize(observerB, observerBNormal);
//
//    double result = Vector3D::dotProduct(normalTriangleVectors[iTriangle], observerBNormal);

    // dziala
    double result2 = ((triangle->getPoint(1).getX() - triangle->getPoint(0).getX()) * (triangle->getPoint(2).getY() - triangle->getPoint(0).getY()))
                     - ((triangle->getPoint(2).getX() - triangle->getPoint(0).getX()) * (triangle->getPoint(1).getY() - triangle->getPoint(0).getY()));
    return result2 < 0.0;

//    std::cout << iTriangle << " " << result << " " << result2 << " " << " [" <<
//        normalTriangleVectors[iTriangle][0] << " " << normalTriangleVectors[iTriangle][1] << " " << normalTriangleVectors[iTriangle][2] << "], [" <<
//        observerBNormal[0] << " " << observerBNormal[1] << " " << observerBNormal[2] << "]" << std::endl;

    return result2 < 0.0;

//    return normalTriangleVectors[iTriangle][2] < 0.0;


}
