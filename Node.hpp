//
// Created by uberslam on 2/11/18.
//

#ifndef LINKED_LIST_NODE_HPP
#define LINKED_LIST_NODE_HPP

#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
private:
    ItemType item;
    Node<ItemType>* next;
public:
    Node();
    explicit Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext (Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};


#endif //LINKED_LIST_NODE_HPP
