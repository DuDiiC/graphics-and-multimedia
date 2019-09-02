#ifndef TRANSFORMATIONMATRIX4X4_H
#define TRANSFORMATIONMATRIX4X4_H

#include <QGenericMatrix>
#include <QImage>

#include <cmath>

class TransformationMatrix4x4 {

public:
    TransformationMatrix4x4(int X0, int Y0, int Z0,
                            int tX, int tY, int tZ,
                            double sX, double sY, double sZ,
                            double alphaX, double alphaY, double alphaZ,
                            QImage *img) :
                                x0(X0), y0(Y0), z0(Z0), tx(tX), ty(tY), tz(tZ), sx(sX), sy(sY), sz(sZ),
                                alphax(alphaX), alphay(alphaY), alphaz(alphaZ)/*,
                                x0(img->width()/2), y0(img->height()/2)*/ {
    }

    TransformationMatrix4x4(int X0, int Y0, int Z0,
                            int tX, int tY, int tZ,
                            double sX, double sY, double sZ,
                            int degreesX, int degreesY, int degreesZ,
                            QImage *img) :
                                x0(X0), y0(Y0), z0(Z0), tx(tX), ty(tY), tz(tZ), sx(sX), sy(sY), sz(sZ),
                                alphax((double)degreesX/M_PI), alphay((double)degreesY/M_PI), alphaz((double)degreesZ/M_PI)/*,
                                x0(img->width()/2), y0(img->height()/2)*/ {
    }

    ~TransformationMatrix4x4() {
    }

    void setTX(int tx) { this->tx = tx; updateMatrix(); }
    int getTX() { return tx; }

    void setTY(int ty) { this->ty = ty; updateMatrix(); }
    int getTY() { return ty; }

    void setTZ(int tz) { this->tz = tz; updateMatrix(); }
    double getTZ() { return tz; }

    void setSX(double sx) { this->sx = sx; updateMatrix(); }
    double getSX() { return sx; }

    void setSY(double sy) { this->sy = sy; updateMatrix(); }
    double getSY() { return sy; }

    void setSZ(double sz) { this->sz = sz; updateMatrix(); }
    double getSZ() { return sz; }

    void setAlphaX(double alphax) { this->alphax = alphax; updateMatrix(); }
    void setAlphaXFromDegrees(int degreesX) {
        this->alphax = (double)degreesX * M_PI/180.0;
        updateMatrix();
    }
    double getAlphaX() { return alphax; }

    void setAlphaY(double alphay) { this->alphay = alphay; updateMatrix(); }
    void setAlphaYFromDegrees(int degreesY) {
        this->alphay = (double)degreesY * M_PI/180.0;
        updateMatrix();
    }
    double getAlphaY() { return alphay; }

    void setAlphaZ(double alphaz) { this->alphaz = alphaz; updateMatrix(); }
    void setAlphaZFromDegrees(int degreesZ) {
        this->alphaz = (double)degreesZ * M_PI/180.0;
        updateMatrix();
    }
    double getAlphaZ() { return alphaz; }

    QGenericMatrix<4, 4, double>* getTransformationMatrix() { return transformationMatrix; }

    /**
     * updateMatrix is method calling after modyfying some values in transformation matrix
     */
    void updateMatrix();

private:

    QGenericMatrix<4, 4, double> *transformationMatrix;

    /**
     * center point coordinates
     */
    int x0 = 0;
    int y0 = 0;
    int z0 = 0;

    /**
     * values to translation
     */
    int tx;
    int ty;
    int tz;

    /**
     * values to scaling
     */
    double sx;
    double sy;
    double sz;

    /**
     * values in radians, between [-PI, PI], value to rotation
     */
    double alphax;
    double alphay;
    double alphaz;
};

#endif // TRANSFORMATIONMATRIX4X4_H
