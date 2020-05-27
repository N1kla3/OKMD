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
    strangeD = new Matrix(p, m);
    strangeF = new Matrix(p, m);
    maxStrange = new Matrix(p, m);
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
    delete strangeF;
    delete strangeD;
    delete maxStrange;
}

Matrix Controller::matrixProduct(const Matrix &one, const Matrix &two) {
    return Matrix(0, 0);
}

void Controller::getTripleMatrixProduct(const Matrix &one, const Matrix &two) {
    vector<thread> threads;
    for(int i = 0; i < p; ++i){
        threads.emplace_back(&Controller::calcD, this,i);
    }


    vector<thread> threads2;
    for(int i = 0; i < p; ++i){
        threads.emplace_back(&Controller::calcF, this, i);
    }
    for(auto &t : threads)t.join();
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

void Controller::calcF(const int index) {
    int maxi, maxj, maxk;
    d->getSize(maxi, maxj, maxk);
    for(int j = 0; j < maxj; ++j){
        for(int k = 0; k < maxk; ++k){
            double result = 0;
            result += supAB(index, j, k) * (2*e->getAt(0, k)-1) * e->getAt(0, k);
            result += supBA(index, j, k) * (1+(4*(supAB(index, j, k))-2)*e->getAt(0, k)) * (1 - e->getAt(0, k));
            f->setAt(index, j, k, result);
        }
    }
}

double Controller::supAB(int i, int j, int k) {
    double result = 0;
    double ajk = 1 - a->getAt(j, k);
    double bkj = b->getAt(k, j);
    if(ajk > bkj){
        result = bkj / ajk;
    }else if(ajk <= bkj){
        result = 1;
    }
    return result;
}

double Controller::supBA(int i, int j, int k) {
    double result = 0;
    double ajk = a->getAt(j, k);
    double bkj = 1 - b->getAt(k, j);
    if(ajk < bkj){
        result = ajk / bkj;
    }else if(ajk <= bkj){
        result = 1;
    }
    return result;
}

Matrix Controller::calcC() {
    Matrix result(p, m);

}

void Controller::calcStrange() {
    vector<thread> threads;
    for(int i = 0; i < p; ++i){
        threads.emplace_back([this, i](){
            for(int j = 0; j < m; ++j){
                double res = 0;
                for(int k = 0; k < q; ++k){
                    res += f->getAt(i, j, k);
                }
                strangeF->setAt(p, m, res);
            }
        });
    }
    for(int i = 0; i < p; ++i){
        threads.emplace_back([this, i](){
            for(int j = 0; j < m; ++j){
                double res = 1;
                for(int k = 0; k < q; ++k){
                    res -= (1 - d->getAt(i, j, k));
                }
                strangeD->setAt(i, j, res);
            }
        });
    }
    for(auto &i : threads){
        i.join();
    }
}

void Controller::calcMaxStrange() {

}

