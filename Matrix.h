//
// Created by nicolas on 25/05/2020.
//

#ifndef OKMD_MATRIX_H
#define OKMD_MATRIX_H

#include "TripleMatrix.h"

class Matrix {
public:
    Matrix (const int xSize, const int ySize)noexcept;
    void setAt(const int x, const int y, double value);
    double getAt(const int x, const int y);
private:
    const double MIN_BOUND = -0.99;
    const double MAX_BOUND = 0.99;
    const int xSize;
    const int ySize;
    std::vector<std::vector<int>> matrix;
    void initMatrix();
    double random()noexcept ;
};


#endif //OKMD_MATRIX_H
