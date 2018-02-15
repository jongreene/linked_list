//
// Created by Jonathon Greene on 2/11/18.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    return 0;
}