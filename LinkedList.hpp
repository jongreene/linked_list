//
// Created by Jonathon Greene on 2/11/18.
//

#ifndef LINKED_LIST_LINKEDLIST_HPP
#define LINKED_LIST_LINKEDLIST_HPP

#include <cassert>
#include "Node.hpp"
#include "Node.cpp"
#include "LinkedIterator.hpp"
#include "LinkedIterator.cpp"
#include <iostream>

//#include "PrecondViolatedExcept.h"


template<class ItemType>
class LinkedList {
private:
    Node<ItemType> *headPtr;

    Node<ItemType> *tailPtr;

    int itemCount;

    Node<ItemType> *getNodeAt(int position) const;

    void addToEmpty(const ItemType &newEntry);

public:
    LinkedList();
//    LinkedList(const LinkedList<ItemType>& aList);
//    virtual ~LinkedList();

    bool isEmpty() const;

    int getLength() const;

//    bool insert(int newPosition, const ItemType& newEntry);
//    bool remove(int position);
//    void clear();
    void addToBack(const ItemType &newEntry);

    void addToFront(const ItemType &newEntry);

    void removeFromBack();

    void removeFromFront();

    ItemType getEntry(int position) const throw();

    void print();

//    ItemType replace(int position, const ItemType& newEntry) throw();


    LinkedIterator<ItemType> begin();

    LinkedIterator<ItemType> end();

};

#endif //LINKED_LIST_LINKEDLIST_HPP
