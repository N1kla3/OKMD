//
// Created by nicolas on 27/05/2020.
//

#include "TripleMatrix.h"
using std::vector;

TripleMatrix::TripleMatrix(const int i, const int j, const int k) {
    matrix = vector<vector<vector<double>>>(i, vector<vector<double>>(j, vector<double>(k, 0)));
}

double TripleMatrix::getAt(const int i, const int j, const int k) {
    return matrix[i][j][k];
}

void TripleMatrix::setAt(const int i, const int j, const int k, double value) {
    matrix[i][j][k] = value;
}
