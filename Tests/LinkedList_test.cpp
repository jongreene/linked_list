//
// Created by uberslam on 2/15/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstdlib>
#include "../LinkedList.hpp"
#include "../LinkedList.cpp"


using testing::Eq;

namespace {
    class LinkedList_test : public testing::Test {
    public:
        LinkedList<int>* linkedList; //= new LinkedList<int>;

        LinkedList_test(){
            linkedList = new LinkedList<int>; // could put here a make method
        }
    };
}

TEST_F(LinkedList_test, addToFront){
    for(int i=0; i<10000; i++){
        int number = rand();
        linkedList->addToFront(number);

        ASSERT_EQ(linkedList->getNodeAt(1)->getItem(),number);
    }

}

TEST_F(LinkedList_test, addToBack){
    for(int i=0; i<10000; i++){
        int number = rand();
        linkedList->addToBack(number);

        ASSERT_EQ(linkedList->getNodeAt(linkedList->getLength())->getItem(),number);
    }

}

TEST_F(LinkedList_test, removeFromBack){

}

TEST_F(LinkedList_test, removeFromFront){

}