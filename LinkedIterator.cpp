//
// Created by Jonathon Greene on 2/11/18.
//

#include "LinkedIterator.hpp"

template<class ItemType>
LinkedIterator<ItemType>::LinkedIterator(LinkedList<ItemType>* someList, Node<ItemType>* nodePtr)
    : containerPtr(someList), currentItemPtr(nodePtr)
{

}

template<class ItemType>
const ItemType LinkedIterator<ItemType>::operator*()
{
    return currentItemPtr -> getItem();
}

template<class ItemType>
LinkedIterator<ItemType> LinkedIterator<ItemType>::operator++()
{
    currentItemPtr = currentItemPtr -> getNext();
}

template<class ItemType>
bool LinkedIterator<ItemType>::operator==(const LinkedIterator<ItemType> &rightHandSide) const
{
    return ((containerPtr == rightHandSide.containerPtr) && (currentItemPtr == rightHandSide.currentItemPtr));
}

template<class ItemType>
bool LinkedIterator<ItemType>::operator!=(const LinkedIterator<ItemType> &rightHandSide) const
{
    return ((containerPtr != rightHandSide.containerPtr) || (currentItemPtr != rightHandSide.currentItemPtr));
}