#ifndef TRANSFORMATIONMATRIX3X3_H
#define TRANSFORMATIONMATRIX3X3_H

#include <QGenericMatrix>

#include <cmath>


class TransformationMatrix3x3 {

public:

    TransformationMatrix3x3(int tX, int tY, int sX, int sY, int shX, int shY, double alpha_) :
        tx(tX), ty(tY), sx(sX), sy(sY), shx(shX), shy(shY), alpha(alpha_) {
        updateMatrix();
    }

    TransformationMatrix3x3(int tX, int tY, int sX, int sY, int shX, int shY, int degrees) :
        tx(tX), ty(tY), sx(sX), sy(sY), shx(shX), shy(shY), alpha((double)degrees/M_PI) {
        updateMatrix();
    }

    ~TransformationMatrix3x3() {}

    void setTX(int tx) { this->tx = tx; updateMatrix(); }
    int getTX() { return tx; }

    void setTY(int ty) { this->ty = ty; updateMatrix(); }
    int getTX() { return ty; }

    void setSX(int sx) { this->sx = sx; updateMatrix(); }
    int getSX() { return sx; }

    void setSY(int sy) { this->sy = sy; updateMatrix(); }
    int getSY() { return sy; }

    void setSHX(int shx) { this->shx = shx; updateMatrix(); }
    int getSHX() { return shx; }

    void setSHY(int shy) { this->shy = shy; updateMatrix(); }
    int getSHY() { return shy; }

    void setAlpha(double alpha) { this->alpha = alpha; updateMatrix(); }
    void setAlphaFromDegrees(int degrees) {
        this->alpha = (double)degrees/M_PI;
        updateMatrix();
    }
    double getAlpha() { return alpha; }

    QGenericMatrix<3, 3, double> getTransformationMatrix() { return transformationMatrix; }

private:

    /**
     * 3x3 matrix to make 2D transformations for points in homogenuous coordinates notation (vector 3x1 [x, y, 1])
     */
    QGenericMatrix<3, 3, double> transformationMatrix;

    /**
     * values to translation
     */
    int tx;
    int ty;

    /**
     * values to scaling
     */
    int sx;
    int sy;

    /**
     * values to shearing
     */
    int shx;
    int shy;

    /**
     * values in radians, between (-2*PI, 2*PI), value to rotation
     */
    double alpha;

    /**
     * updateMatrix is method calling after modyfying some values in transformation matrix
     */
    void updateMatrix();
};

#endif // TRANSFORMATIONMATRIX3X3_H
