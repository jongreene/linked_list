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

    // returns a bool; true if empty false otherwise
    bool isEmpty() const;

    // returns the length of the list
    int getLength() const;

    // takes a position and a new entry
    // creates a new node and inserts it at the specified place if possible
    bool insert(int newPosition, const ItemType& newEntry);

    // adds an item to the back of the list
    void addToBack(const ItemType &newEntry);

    // adds an item to the front of the list
    void addToFront(const ItemType &newEntry);

    // removes the last node in the list
    void removeFromBack();

    // removes the leading node of the list
    void removeFromFront();

    // returns the item at the requested position (if possible)
    ItemType getEntry(int position) const throw();

//    ItemType replace(int position, const ItemType& newEntry) throw();

    // Used as a starting point for iterator functionality
    LinkedIterator<ItemType> begin();

    // Used as an stopping(ending) point for iterator functionality
    LinkedIterator<ItemType> end();

};

#endif //LINKED_LIST_LINKEDLIST_HPP
