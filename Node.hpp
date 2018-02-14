//
// Created by Jonathon Greene on 2/11/18.
//

#ifndef LINKED_LIST_NODE_HPP
#define LINKED_LIST_NODE_HPP

#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
private:
    // holds the item which can be of any standard type
    ItemType item;

    // stores the location of the next node in the chain
    Node<ItemType>* next;

    Node<ItemType>* previous;

    Node<ItemType>* last;

public:
    // generic constructor which assigns next node to nullptr
    Node();

    // does not allow for copy constructor
    explicit Node(const ItemType& anItem);

    // sets the item/value for a particular node
    void setItem(const ItemType& anItem);

    // sets the next node in the chain
    void setNext (Node<ItemType>* nextNodePtr);

    // sets the last node in the chain
    void setPrevious (Node<ItemType>* nextNodePtr);

    // returns the nodes item/value
    ItemType getItem() const;

    // gets the next node in the chain
    Node<ItemType>* getNext() const;

    Node<ItemType>* getPrevious() const;
};


#endif //LINKED_LIST_NODE_HPP
