//
// Created by nicolas on 25/05/2020.
//

#include "Matrix.h"
#include <random>

Matrix::Matrix(const int xSize, const int ySize) noexcept :
    xSize(xSize),
    ySize(ySize){
    initMatrix();
}

double Matrix::random() noexcept {
    std::uniform_real_distribution<double> unif(-1, 1);
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
