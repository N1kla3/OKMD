//
// Created by nicolas on 26/05/2020.
//

#include "Controller.h"
#include <thread>

using namespace std;

Controller::Controller() noexcept {

}

Matrix Controller::matrixProduct(const Matrix &one, const Matrix &two) {
    return Matrix(0, 0);
}

TripleMatrix Controller::getTripleMatrixProduct(const Matrix &one, const Matrix &two) {
    TripleMatrix result(one.xSize, two.ySize, two.xSize);
    vector<thread> threads;
    for(int i = 0; i < one.xSize; ++i){
        threads.emplace_back(&Controller::oneTripleMatrixLayProduct, this, one, two, result, i);
    }
    for(auto &t : threads){
        t.join();
    }
    return result;
}

void Controller::oneTripleMatrixLayProduct(const Matrix &one, const Matrix &two, TripleMatrix result, const int index) {
    int maxi, maxj, maxk;
    result.getSize(maxi, maxj, maxk);
    for(int j = 0; j < maxj; ++j){
        for(int k = 0; k < maxk; ++k){
            result.setAt(index, j, k, one.getAt(index, k)*two.getAt(k, j));
        }
    }
}
