//
// Created by nicolas on 27/05/2020.
//

#ifndef OKMD_TRIPLEMATRIX_H
#define OKMD_TRIPLEMATRIX_H

#include <vector>

class TripleMatrix {
public:
    TripleMatrix(int i, int j, int k);
    double getAt(int i, int j, int k);
    void setAt(int i, int j, int k, double value);
    void getSize(int &i, int &j, int &k);
private:
    std::vector<std::vector<std::vector<double>>> matrix;
    int i, j, k;
};


#endif //OKMD_TRIPLEMATRIX_H
