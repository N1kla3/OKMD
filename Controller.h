//
// Created by nicolas on 26/05/2020.
//

#ifndef OKMD_CONTROLLER_H
#define OKMD_CONTROLLER_H

#include "Matrix.h"

class Controller {
public:
    Controller();

    virtual ~Controller();

private:
    int p, m, q;
    Matrix *a, *b, *e, *g, *strangeF, *strangeD, *maxStrange;
    TripleMatrix *f, *d;
    Matrix matrixProduct(const Matrix &one, const Matrix &two);
    void getTripleMatrixProduct(const Matrix &one, const Matrix &two);
    Matrix calcC();
    void calcD(int index);
    void calcF(int index);
    double supAB(int i, int j, int k);
    double supBA(int i, int j, int k);
    void calcStrange();
    void calcMaxStrange();
};


#endif //OKMD_CONTROLLER_H
