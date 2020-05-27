//
// Created by nicolas on 26/05/2020.
//

#ifndef OKMD_CONTROLLER_H
#define OKMD_CONTROLLER_H

#include "Matrix.h"

class Controller {
public:
    Controller()noexcept ;
private:
    Matrix matrixProduct(const Matrix &one, const Matrix &two);
    TripleMatrix getTripleMatrixProduct(const Matrix &one, const Matrix &two);
    void oneTripleMatrixLayProduct(const Matrix &one, const Matrix &two, TripleMatrix result, const int index);
};


#endif //OKMD_CONTROLLER_H
