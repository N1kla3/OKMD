//
// Created by nicolas on 25/05/2020.
//

#include "Matrix.h"
#include <random>

Matrix::Matrix(const int xSize, const int ySize) noexcept :
    xSize(xSize),
    ySize(ySize)
    {
    initMatrix();
}

double Matrix::random() noexcept {
    std::uniform_real_distribution<double> unif(MIN_BOUND, MAX_BOUND);
    std::default_random_engine  engine;
    double random = unif(engine);
    return random;
}

void Matrix::initMatrix() {
    for(int i = 0; i < ySize; ++i){
        for(int j = 0; j < xSize; ++j){
            matrix[i][j] = random();
        }
    }
}

void Matrix::setAt(const int x, const int y, double value) {
    if (x < 0 || x >= xSize)return;
    if (y < 0 || y >= ySize)return;
    matrix[x][y] = value;
}

double Matrix::getAt(const int x, const int y) {
    if (x < 0 || x >= xSize)return 0;
    if (y < 0 || y >= ySize)return 0;
    return matrix[x][y];
}
