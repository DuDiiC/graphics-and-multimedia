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

Cube::Cube(int a, int d) {
    x = a;
    y = a;
    z = a;
    this->d = d;
    setValues();
}

Cube::Cube(int x, int y, int z, int d) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->d = d;
    setValues();
}

void Cube::draw(QImage *img, int RGBColor) {

    img->fill(Qt::black);

    // drawing textures
    int colors[6] = {
            0xcc0000, //red
            0x00cc00, //green
            0x0000cc, //blue
            0xcccc00, //yellow
            0xcccccc, //white
            0xcc00cc // pink
    };
    texturingWalls(img, true, colors);
    // texturingWalls(img);

    // drawing cube's edges
    for(int i = 0; i < triangles.size(); i++) {
        triangles[i].changeInto2D()->draw(img, RGBColor);
    }
}

void Cube::updateValues(TransformationMatrix4x4 *matrix) {
    for(int i = 0; i < points.size(); i++) {
        MyPoint3D newPoint;

        double tempPointTab[] = { (double)points[i].getX(), (double)points[i].getY(), (double)points[i].getZ(), 1.0 };
        QGenericMatrix<1, 4, double> tempPointM(tempPointTab);

        tempPointM = *(matrix->getTransformationMatrix()) * tempPointM;

        newPoint.setXYZ(tempPointM.data()[0], tempPointM.data()[1], tempPointM.data()[2]);
        newPoint.setD(d);

        points[i] = newPoint;
    }
    setTriangles();
}

void Cube::setValues() {
    setPoints();
    setTriangles();
}

void Cube::setPoints() {
    points.clear();

    MyPoint3D tempPoint(50);

    // (wall, width, height)
    // 0 (front, left, up)
    tempPoint.setXYZD(-x, -y, -z, d);
    points.push_back(tempPoint);
    // 1 (front, left, down)
    tempPoint.setXYZD(-x, y, -z, d);
    points.push_back(tempPoint);
    // 2 (front, right, down)
    tempPoint.setXYZD(x, y, -z, d);
    points.push_back(tempPoint);
    // 3 (front, right, up)
    tempPoint.setXYZD(x, -y, -z, d);
    points.push_back(tempPoint);
    // 4 (back, left, up)
    tempPoint.setXYZD(-x, -y, z, d);
    points.push_back(tempPoint);
    // 5 (back, left, down)
    tempPoint.setXYZD(-x, y, z, d);
    points.push_back(tempPoint);
    // 6 (back, right, down)
    tempPoint.setXYZD(x, y, z, d);
    points.push_back(tempPoint);
    // 7 (back, right, up)
    tempPoint.setXYZD(x, -y, z, d);
    points.push_back(tempPoint);
}

void Cube::setTriangles() {
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

// TODO: that function need optimalization
void Cube::texturingWalls(QImage *img, bool uniformColor, int *colors) {

    MyPoint2D *p0, *p1, *p2, *p3;
    Triangle *sourceTriangleDown, *sourceTriangleUp, *wallTriangleDown, *wallTriangleUp;
    QImage *wallSource;

    int selectedColor;

    for(int i = 0; i < 6; i++) {

        if(uniformColor) { // fill uniform color

            selectedColor = colors[i];

            wallTriangleDown = triangles[2 * i].changeInto2D();
            wallTriangleUp = triangles[2 * i + 1].changeInto2D();

            if (isVisible(*wallTriangleDown)) {
                TriangleTexturing::texturing(selectedColor, img, wallTriangleDown);
            }
            if (isVisible(*wallTriangleUp)) {
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

            if (isVisible(*wallTriangleDown)) {
                TriangleTexturing::texturing(wallSource, sourceTriangleDown, img, wallTriangleDown);
            }
            if (isVisible(*wallTriangleUp)) {
                TriangleTexturing::texturing(wallSource, sourceTriangleUp, img, wallTriangleUp);
            }
            delete wallSource;
            delete p0; delete p1; delete p2; delete p3;
            delete sourceTriangleDown; delete sourceTriangleUp;
            wallTriangleDown = wallTriangleUp = nullptr;
        }
    }
}

bool Cube::isVisible(Triangle triangle) {

    double result = (triangle.getPoint(1).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(2).getY() - triangle.getPoint(0).getY())
                    - (triangle.getPoint(2).getX() - triangle.getPoint(0).getX()) * (triangle.getPoint(1).getY() - triangle.getPoint(0).getY());

    return result < 0;
}
