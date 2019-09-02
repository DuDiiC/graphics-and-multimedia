#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QImage>

#include <vector>
#include <utility>

#include "MyPoint2D.h"
#include "LineSegment.h"

class Triangle {
public:

    Triangle();
    Triangle(std::vector < MyPoint2D > points);
    Triangle(const MyPoint2D& point1, const MyPoint2D& point2, const MyPoint2D& point3);

    ~Triangle();

    void draw(QImage *img, int RGBColor = 0xFFFFFF);

    void setPoints(std::vector < MyPoint2D > points) { this->points = points; }
    std::vector < MyPoint2D > getPoints() { return points; }

    void setPoint(int index, MyPoint2D point) { points[index] = point; }
    MyPoint2D getPoint(int index) { return points[index]; }

    void addPoint(MyPoint2D point) {
        points.push_back(point);
    }

    void removePoint(MyPoint2D point) {
        points.erase(std::remove(points.begin(),
                                 points.end(), point),
                     points.end());
    }

    /**
     * sprawdza czy punkt jest w zbiorze punktow, albo w podanej okolicy
     * jesli tak, zwraca pozycje punktu, jesli nie zwraca -1
     */
    int pointInSet(MyPoint2D point, int scale);

    int minimumX();
    int maximumX();

    int minimumY();
    int maximumY();

private:

    std::vector < MyPoint2D > points;
};

#endif // TRIANGLE_H
