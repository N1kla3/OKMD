//
// Created by nicolas on 26/05/2020.
//

#include "Controller.h"
#include <thread>
#include <random>

using namespace std;

Controller::Controller(){
    std::uniform_int_distribution<int> unif(1, 10);
    std::default_random_engine  engine;
    p = unif(engine);
    m = unif(engine);
    q = unif(engine);
    a = new Matrix(p, m);
    b = new Matrix(m, q);
    e = new Matrix(1, m);
    g = new Matrix(p, q);
    f = new TripleMatrix(p, m, q);
    d = new TripleMatrix(p, m, q);
}

Controller::~Controller() {
    delete a;
    delete b;
    delete e;
    delete g;
    delete f;
    delete d;
}

Matrix Controller::matrixProduct(const Matrix &one, const Matrix &two) {
    return Matrix(0, 0);
}

void Controller::getTripleMatrixProduct(const Matrix &one, const Matrix &two) {
    vector<thread> threads;
    for(int i = 0; i < p; ++i){
        threads.emplace_back(&Controller::calcD, this,i);
    }
    for(auto &t : threads)t.join();

    vector<thread> threads2;
    for(int i = 0; i < p; ++i){
        threads.emplace_back(&Controller::calcF, this, i);
    }
    for(auto &t : threads2)t.join();
}

void Controller::calcD(const int index) {
    int maxi, maxj, maxk;
    d->getSize(maxi, maxj, maxk);
    for(int j = 0; j < maxj; ++j){
        for(int k = 0; k < maxk; ++k){
            d->setAt(index, j, k, a->getAt(index, k)*b->getAt(k, j));
        }
    }
}

void Controller::calcF(int index) {
    int maxi, maxj, maxk;
    d->getSize(maxi, maxj, maxk);
    for(int j = 0; j < maxj; ++j){
        for(int k = 0; k < maxk; ++k){

        }
    }
}
