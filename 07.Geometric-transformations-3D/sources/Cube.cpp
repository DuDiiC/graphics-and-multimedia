#include "includes/Cube.h"
#include <iostream>
#include <includes/TriangleTexturing.h>

std::string Cube::IMAGE_PATHS[] = {
        "resources/red.png",
        "resources/green.jpg",
        "resources/blue.jpg",
        "resources/yellow.jpg",
        "resources/white.jpg",
        "resources/purple.jpg"
};

Cube::Cube(int a, int d, int x0, int y0, int z0) {
    x = a;
    y = a;
    z = a;
    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->d = d;
    setValues();
}

Cube::Cube(int x, int y, int z, int d, int x0, int y0, int z0) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->x0 = x0; this->y0 = y0; this->z0 = z0;
    this->d = d;
    setValues();
}

void Cube::draw(QImage *img, int RGBColor) {

    img->fill(Qt::black);

    // drawing textures
    int colors[6] = {
            0x550000, //red
            0x005500, //green
            0x000055, //blue
            0x555500, //yellow
            0x555555, //white
            0x550055 // pink
    };
    texturingWalls(img, true, colors);
    // texturingWalls(img);

    // drawing cube's edges
    for(auto & triangle : triangles) {
        triangle.changeInto2D()->draw(img, RGBColor);
    }
}

void Cube::updateValues(TransformationMatrix4x4 *matrix) {
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
    setTriangleVectors();
    setWallVectors();
    setAvgVertexVectors();
//    for(int i = 0; i < 8; i++) {
//        double dot[3];// = { static_cast<double>(points[i].getX()), static_cast<double>(points[i].getY()), static_cast<double>(points[i].getZ()) };
//        Vector3D::convertToVector(points[i], dot);
//        double normalDot[3];
//        Vector3D::normalize(dot, normalDot);
//
//        std::cout << Vector3D::dotProduct(avgNormalVertexVectors[i], normalDot) << std::endl;
//    }
}

void Cube::setValues() {
    setPoints();
    setTriangles();
    setTriangleVectors();
    setWallVectors();
//    for(auto & normalWallVector : normalWallVectors) { std::cout << normalWallVector[0] << " " << normalWallVector[1] << " " << normalWallVector[2] << std::endl; }
    setAvgVertexVectors();
//    for(int i = 0; i < 8; i++) {
//        double dot[3];// = { static_cast<double>(points[i].getX()), static_cast<double>(points[i].getY()), static_cast<double>(points[i].getZ()) };
//        Vector3D::convertToVector(points[i], dot);
//        double normalDot[3];
//        Vector3D::normalize(dot, normalDot);
//
//        std::cout << Vector3D::dotProduct(avgNormalVertexVectors[i], normalDot) << std::endl;
//    }
}

void Cube::setPoints() {

//    for(auto &i : points) { delete &i; }
    points.clear();

    MyPoint3D tempPoint(50);

    // (wall, width, height)
    // 0 (front, left, up)
    tempPoint.setXYZD(-x+x0, -y+y0, -z+z0, d);
    points.push_back(tempPoint);
    // 1 (front, left, down)
    tempPoint.setXYZD(-x+x0, y+y0, -z+z0, d);
    points.push_back(tempPoint);
    // 2 (front, right, down)
    tempPoint.setXYZD(x+x0, y+y0, -z+z0, d);
    points.push_back(tempPoint);
    // 3 (front, right, up)
    tempPoint.setXYZD(x+x0, -y+y0, -z+z0, d);
    points.push_back(tempPoint);
    // 4 (back, left, up)
    tempPoint.setXYZD(-x+x0, -y+y0, z+z0, d);
    points.push_back(tempPoint);
    // 5 (back, left, down)
    tempPoint.setXYZD(-x+x0, y+y0, z+z0, d);
    points.push_back(tempPoint);
    // 6 (back, right, down)
    tempPoint.setXYZD(x+x0, y+y0, z+z0, d);
    points.push_back(tempPoint);
    // 7 (back, right, up)
    tempPoint.setXYZD(x+x0, -y+y0, z+z0, d);
    points.push_back(tempPoint);
}

void Cube::setTriangles() {

//    for(auto &i : triangles) { delete &i; }
    triangles.clear();

    Triangle3D tempTriangle;
    // (wall, triangle)
    // front-down
    tempTriangle.setPoints(points[0], points[1], points[2]);
    triangles.push_back(tempTriangle);
    // front, up
    tempTriangle.setPoints(points[2], points[3], points[0]);
    triangles.push_back(tempTriangle);
    // back, down
    tempTriangle.setPoints(points[7], points[6], points[5]);
    triangles.push_back(tempTriangle);
    // back, up
    tempTriangle.setPoints(points[5], points[4], points[7]);
    triangles.push_back(tempTriangle);
    // left, down
    tempTriangle.setPoints(points[4], points[5], points[1]);
    triangles.push_back(tempTriangle);
    // left, up
    tempTriangle.setPoints(points[1], points[0], points[4]);
    triangles.push_back(tempTriangle);
    // right, down
    tempTriangle.setPoints(points[3], points[2], points[6]);
    triangles.push_back(tempTriangle);
    // right, up
    tempTriangle.setPoints(points[6], points[7], points[3]);
    triangles.push_back(tempTriangle);
    // up, down
    tempTriangle.setPoints(points[4], points[0], points[3]);
    triangles.push_back(tempTriangle);
    // up, up
    tempTriangle.setPoints(points[3], points[7], points[4]);
    triangles.push_back(tempTriangle);
    // down, down
    tempTriangle.setPoints(points[1], points[5], points[6]);
    triangles.push_back(tempTriangle);
    tempTriangle.setPoints(points[6], points[2], points[1]);
    triangles.push_back(tempTriangle);
}

void Cube::setWallVectors() {
    // dla kazdej sciany, tworzymy wektor normalny przy uzyciu punktow 'dolnego' trojkata:
    double wallVectors[6][3];
    double tempV1[3], tempV2[3];

    for(auto i = 0; i < 6; i++) {

        Vector3D::createVector(triangles[2*i].getPoint(1), triangles[2*i].getPoint(2), tempV1);
        Vector3D::createVector(triangles[2*i].getPoint(1), triangles[2*i].getPoint(0), tempV2);

        Vector3D::crossProduct(tempV1, tempV2, wallVectors[i]);

        Vector3D::normalize(wallVectors[i], normalWallVectors[i]);
    }
}

void Cube::setTriangleVectors() {
    // dla kazdego trojkata, tworzymy wektor normalny przy uzyciu punktow:
    double triangleVectors[12][3];
    double tempV1[3], tempV2[3];

    for(auto i = 0; i < 12; i++) {

        Vector3D::createVector(triangles[i].getPoint(1), triangles[i].getPoint(2), tempV1);
        Vector3D::createVector(triangles[i].getPoint(1), triangles[i].getPoint(0), tempV2);
//        Vector3D::createVector(triangles[i].getPoint(0), triangles[i].getPoint(1), tempV1);
//        Vector3D::createVector(triangles[i].getPoint(0), triangles[i].getPoint(2), tempV2);

        Vector3D::crossProduct(tempV1, tempV2, triangleVectors[i]);

        Vector3D::normalize(triangleVectors[i], normalTriangleVectors[i]);
    }
}

void Cube::setAvgVertexVectors() {
    // dla kazdego wierzcholka na podstawie wektorow normalnych scian do ktorych nalezy, obliczamy sredni wektor normalny
    double VertexVectors[8][3];

    // point 0
    Vector3D::avgVectorVertex(normalWallVectors[0], normalWallVectors[2], normalWallVectors[4], avgNormalVertexVectors[0]);
    // point 1
    Vector3D::avgVectorVertex(normalWallVectors[0], normalWallVectors[2], normalWallVectors[5], avgNormalVertexVectors[1]);
    // point 2
    Vector3D::avgVectorVertex(normalWallVectors[0], normalWallVectors[3], normalWallVectors[5], avgNormalVertexVectors[2]);
    // point 3
    Vector3D::avgVectorVertex(normalWallVectors[0], normalWallVectors[3], normalWallVectors[4], avgNormalVertexVectors[3]);
    // point 4
    Vector3D::avgVectorVertex(normalWallVectors[1], normalWallVectors[2], normalWallVectors[4], avgNormalVertexVectors[4]);
    // point 5
    Vector3D::avgVectorVertex(normalWallVectors[1], normalWallVectors[2], normalWallVectors[5], avgNormalVertexVectors[5]);
    // point 6
    Vector3D::avgVectorVertex(normalWallVectors[1], normalWallVectors[3], normalWallVectors[5], avgNormalVertexVectors[6]);
    // point 7
    Vector3D::avgVectorVertex(normalWallVectors[1], normalWallVectors[3], normalWallVectors[4], avgNormalVertexVectors[7]);
}

// TODO: that function need optimalization
void Cube::texturingWalls(QImage *img, bool uniformColor, const int *colors) {

    MyPoint2D *p0, *p1, *p2, *p3;
    Triangle *sourceTriangleDown, *sourceTriangleUp, *wallTriangleDown, *wallTriangleUp;
    QImage *wallSource;

    int selectedColor;

    for(int i = 0; i < 6; i++) {

        if(uniformColor) { // fill uniform color

            selectedColor = colors[i];

            wallTriangleDown = triangles[2 * i].changeInto2D();
            wallTriangleUp = triangles[2 * i + 1].changeInto2D();

            if (isVisible(*wallTriangleDown/*, i, 2*i*/)) {
                TriangleTexturing::texturing(selectedColor, img, wallTriangleDown);
            }
            if (isVisible(*wallTriangleUp/*, i, 2*i+1*/)) {
                TriangleTexturing::texturing(selectedColor, img, wallTriangleUp);
            }

            wallTriangleDown = wallTriangleUp = nullptr;

        } else { // texturing from sources

            wallSource = new QImage(IMAGE_PATHS[i].c_str());

            p0 = new MyPoint2D(0, 0);
            p1 = new MyPoint2D(0, wallSource->height() - 1);
            p2 = new MyPoint2D(wallSource->width() - 1, wallSource->height() - 1);
            p3 = new MyPoint2D(wallSource->width(), 0);

            sourceTriangleDown = new Triangle(*p0, *p1, *p2);
            sourceTriangleUp = new Triangle(*p2, *p3, *p0);
            wallTriangleDown = triangles[2 * i].changeInto2D();
            wallTriangleUp = triangles[2 * i + 1].changeInto2D();

            if (isVisible(*wallTriangleDown/*, i, 2*i*/)) {
                TriangleTexturing::texturing(wallSource, sourceTriangleDown, img, wallTriangleDown);
            }
            if (isVisible(*wallTriangleUp/*, i, 2*i+1*/)) {
                TriangleTexturing::texturing(wallSource, sourceTriangleUp, img, wallTriangleUp);
            }
            delete wallSource;
            delete p0; delete p1; delete p2; delete p3;
            delete sourceTriangleDown; delete sourceTriangleUp;
            wallTriangleDown = wallTriangleUp = nullptr;
        }
    }
}

bool Cube::isVisible(Triangle& triangle/*, int iWall, int iTriangle*/) {

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
    double result2 = ((triangle.getPoint(1).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(2).getY() - triangle.getPoint(0).getY()))
                    - ((triangle.getPoint(2).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(1).getY() - triangle.getPoint(0).getY()));

//    std::cout << iTriangle << " " << result << " " << result2 << " " << " [" <<
//        normalTriangleVectors[iTriangle][0] << " " << normalTriangleVectors[iTriangle][1] << " " << normalTriangleVectors[iTriangle][2] << "], [" <<
//        observerBNormal[0] << " " << observerBNormal[1] << " " << observerBNormal[2] << "]" << std::endl;

    return result2 < 0.0;

//    return normalTriangleVectors[iTriangle][2] < 0.0;
}
