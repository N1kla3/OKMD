//
// Created by nicolas on 28/05/2020.
//

#include "gtest/gtest.h"
#include "../src/Controller.h"

TEST(contr, testone){
    Controller *c = new Controller(2, 2, 2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                auto z = c->supAB(i,j,k);
                EXPECT_TRUE(z <= 1.0);
                std::cout << z << " ";
            }
        }
    }
}

TEST(contr, testtwo){
    Controller *c = new Controller(5, 5, 5, 0);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; ++j){
            for(int k = 0; k < 5; ++k){
                auto z = c->supBA(i,j,k);
                EXPECT_TRUE(z <= 1.0);
            }
        }
    }
}
