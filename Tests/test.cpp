//
// Created by uberslam on 2/15/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ClassName.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        ClassName obj;
        ClassDeclaration(){
            obj; // could put here a make method
        }
    };
}

TEST_F(ClassDeclaration, nameOfTheTest1){
    ASSERT_EQ("","");
}

TEST_F(ClassDeclaration, nameOfTheTest2){
    ASSERT_EQ("","");
}