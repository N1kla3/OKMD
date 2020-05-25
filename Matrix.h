//
// Created by nicolas on 25/05/2020.
//

#ifndef OKMD_MATRIX_H
#define OKMD_MATRIX_H

#include <vector>

class Matrix {
public:
    explicit Matrix(const std::vector<std::vector<int>> &matrix);
private:
    std::vector<std::vector<int>> matrix;
};


#endif //OKMD_MATRIX_H
