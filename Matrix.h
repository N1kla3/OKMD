//
// Created by nicolas on 25/05/2020.
//

#ifndef OKMD_MATRIX_H
#define OKMD_MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix (const int xSize, const int ySize)noexcept;
private:
    const int xSize;
    const int ySize;
    std::vector<std::vector<int>> matrix;
    void initMatrix();
    double random()noexcept ;
};


#endif //OKMD_MATRIX_H
