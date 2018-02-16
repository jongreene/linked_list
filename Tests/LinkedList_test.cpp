//
// Created by uberslam on 2/15/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstdlib>
#include "../LinkedList.hpp"
#include "../LinkedList.cpp"
#include <random>


using testing::Eq;

int itemCount = 10000;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,itemCount);


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
    for(int i=0; i<itemCount; i++){
        int number = rand();
        linkedList->addToFront(number);

        ASSERT_EQ(linkedList->getNodeAt(1)->getItem(),number);
    }

}

TEST_F(LinkedList_test, addToBack){
    for(int i=0; i<itemCount; i++){
        int number = rand();
        linkedList->addToBack(number);

        ASSERT_EQ(linkedList->getNodeAt(linkedList->getLength())->getItem(),number);
    }

}

TEST_F(LinkedList_test, removeFromBack){
//    int itemCount = 10000;
    Node<int>* curPtr;

    for(int i=0; i<itemCount; i++){
        int number = rand();
        linkedList->addToFront(number);
    }

    // must leave at least one element in linked list
    for(int i=0; i<itemCount-1; i++){
        linkedList->removeFromBack();

        curPtr = linkedList->getHeadPtr();

        // There will always be at least one item in the list
        int items = 1;

        while(curPtr->getNext()!= nullptr)
        {
            curPtr= curPtr -> getNext();
            items++;
        }
        ASSERT_EQ(linkedList->getLength(),items);
    }

}

TEST_F(LinkedList_test, removeFromFront){
//    int itemCount = 10000;
    Node<int>* curPtr;

    for(int i=0; i<itemCount; i++){
        int number = rand();
        linkedList->addToFront(number);
    }

    // must leave at least one element in linked list
    for(int i=0; i<itemCount-1; i++){
        linkedList->removeFromFront();

        curPtr = linkedList->getHeadPtr();

        // There will always be at least one item in the list
        int items = 1;

        while(curPtr->getNext()!= nullptr)
        {
            curPtr= curPtr -> getNext();
            items++;
        }
        ASSERT_EQ(linkedList->getLength(),items);
    }

}

TEST_F(LinkedList_test, insertAt){
    int timesToTest = 10000;

    for(int i = 0; i<timesToTest; i++) {
        int position = distribution(generator);
        int valueToInsert = distribution(generator);

        for (int i = 0; i < itemCount; i++) {
            int number = distribution(generator);
            linkedList->addToFront(number);
        }

        linkedList->insertAt(position, valueToInsert);

        ASSERT_EQ(linkedList->getNodeAt(position)->getItem(), valueToInsert);
    }
}