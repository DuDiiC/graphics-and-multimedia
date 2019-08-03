#ifndef TRANSFORMATIONMATRIX3X3_H
#define TRANSFORMATIONMATRIX3X3_H

#include <QGenericMatrix>
#include <QImage>

#include <cmath>

class TransformationMatrix3x3 {

public:

    TransformationMatrix3x3(int tX, int tY, double sX, double sY, double shX, double shY, double alpha_, QImage *img) :
        tx(tX), ty(tY), sx(sX), sy(sY), shx(shX), shy(shY), alpha(alpha_), x0(img->width()/2), y0(img->height()/2) {
    }

    TransformationMatrix3x3(int tX, int tY, double sX, double sY, double shX, double shY, int degrees, QImage *img) :
        tx(tX), ty(tY), sx(sX), sy(sY), shx(shX), shy(shY), alpha((double)degrees/M_PI), x0(img->width()/2), y0(img->height()/2) {
    }

    ~TransformationMatrix3x3() {}

    void setTX(int tx) { this->tx = tx; updateMatrix(); }
    int getTX() { return tx; }

    void setTY(int ty) { this->ty = ty; updateMatrix(); }
    int getTY() { return ty; }

    void setSX(double sx) { this->sx = sx; updateMatrix(); }
    double getSX() { return sx; }

    void setSY(double sy) { this->sy = sy; updateMatrix(); }
    double getSY() { return sy; }

    void setSHX(double shx) { this->shx = shx; updateMatrix(); }
    double getSHX() { return shx; }

    void setSHY(double shy) { this->shy = shy; updateMatrix(); }
    double getSHY() { return shy; }

    void setAlpha(double alpha) { this->alpha = alpha; updateMatrix(); }
    void setAlphaFromDegrees(int degrees) {
        this->alpha = (double)degrees * M_PI/180.0;
        updateMatrix();
    }
    double getAlpha() { return alpha; }

    QGenericMatrix<3, 3, double> getTransformationMatrix() { return transformationMatrix; }

    /**
     * updateMatrix is method calling after modyfying some values in transformation matrix
     */
    void updateMatrix();

private:

    /**
     * 3x3 matrix to make 2D transformations for points in homogenuous coordinates notation (vector 3x1 [x, y, 1])
     */
    QGenericMatrix<3, 3, double> transformationMatrix;

    /**
     * center point coordinates
     */
    int x0;
    int y0;

    /**
     * values to translation
     */
    int tx;
    int ty;

    /**
     * values to scaling
     */
    double sx;
    double sy;

    /**
     * values to shearing
     */
    double shx;
    double shy;

    /**
     * values in radians, between (-PI, PI), value to rotation
     */
    double alpha;
};

#endif // TRANSFORMATIONMATRIX3X3_H
