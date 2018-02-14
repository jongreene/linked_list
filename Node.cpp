//
// Created by Jonathon Greene on 2/11/18.
//

#include "Node.hpp"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem)
        : item(anItem), next(nullptr)
{

}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
    next = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setPrevious(Node<ItemType> *lastNodePtr)
{
    previous = lastNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrevious() const
{
    return previous;
}