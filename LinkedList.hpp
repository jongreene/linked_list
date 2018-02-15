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



    void addToEmpty(const ItemType &newEntry);

public:
    LinkedList();
    LinkedList(LinkedList<ItemType>* aList);
//    virtual ~LinkedList();

    Node<ItemType> *getNodeAt(int position);

    // returns a bool; true if empty false otherwise
    bool isEmpty() const;

    // returns the length of the list
    int getLength() const;

    // takes a position and a new entry
    // creates a new node and inserts it at the specified place if possible
    bool insertAt(int newPosition, const ItemType& newEntry);

    bool removeAt(int position);

    void clear();

    // adds an item to the back of the list
    void addToBack(const ItemType &newEntry);

    // adds an item to the front of the list
    void addToFront(const ItemType &newEntry);

    // removes the last node in the list
    void removeFromBack();

    // removes the leading node of the list
    void removeFromFront();

    // returns the item at the requested position (if possible)
    ItemType getEntry(int position) throw();

//    ItemType replace(int position, const ItemType& newEntry) throw();

    void swapNodes(int firstPosition, int secondPosition);

    // replaces a node at the specified position with a new of the given value
    void replaceNodeAt(int position, const ItemType &newEntry);

    // adds an element to the front of the list
    void push(const ItemType &newEntry);

    // removes the first element from the list
    void pop();

    // bubble sorts the list
    // accepts string values: ascending or descending
    void bubbleSort(string direction);

    string search(ItemType querie);

    // Used as a starting point for iterator functionality
    LinkedIterator<ItemType> begin();

    // Used as an stopping(ending) point for iterator functionality
    LinkedIterator<ItemType> end();

};

#endif //LINKED_LIST_LINKEDLIST_HPP
