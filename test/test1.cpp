//
// Created by nicolas on 28/05/2020.
//

#include "gtest/gtest.h"
#include "../src/Controller.h"

TEST(contr, testone){
    Controller *c = new Controller(2,2,2);
    c->a->setAt(0,1, 0.78);
    c->b->setAt(1,1, 0.78);
    EXPECT_EQ(c->supAB(0,1,1), 1.0);
}