//
// Created by uberslam on 2/11/18.
//

#include <vector>
#include "LinkedList.hpp"

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{

}

template<class ItemType>
void LinkedList<ItemType>::addToEmpty(const ItemType &newEntry)
{
    auto newNodePtr = new Node<ItemType>(newEntry);
    headPtr = newNodePtr;
    headPtr->setNext(nullptr);
    itemCount++;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    bool empty = getLength() > 0;
    return empty;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw()
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position";
        throw(message);
    }
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    assert( (position >= 1) && (position <= itemCount) );

    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
    {
        curPtr = curPtr -> getNext();
    }

    return curPtr;
}
//
//template<class ItemType>
//bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
//{
//    bool ableToInsert = (newPosition >= 1 && (newPosition <=  itemCount + 1));
//    if (ableToInsert)
//    {
//        auto newNodePtr = new Node<ItemType>(newEntry);
//
//        if (newPosition == 1)
//        {
//            newNodePtr -> setNext(headPtr);
//            headPtr = newNodePtr;
//        }
//        else
//        {
//            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
//
//            newNodePtr -> setNext(prevPtr -> getNext());
//            prevPtr -> setNext(newNodePtr);
//        }
//
//        itemCount++;
//    }
//
//    return ableToInsert;
//}
//
//template<class ItemType>
//bool LinkedList<ItemType>::remove(int position)
//{
//    bool ableToRemove = (position >= 1) && (position <= itemCount);
//    if (ableToRemove) {
//        Node<ItemType> *curPtr = nullptr;
//        if (position == 1)
//        {
//            curPtr = headPtr;
//            headPtr = headPtr->getNext();
//        }
//        else
//        {
//            Node<ItemType>* prevPtr = getNodeAt(position - 1);
//
//            curPtr = prevPtr->getNext();
//
//            prevPtr ->setNext(curPtr -> getNext());
//        }
//
//        curPtr -> setNext(nullptr);
//        delete curPtr;
//        curPtr = nullptr;
//
//        itemCount--;
//    }
//}
//
//template<class ItemType>
//void LinkedList<ItemType>::clear()
//{
//    while (!isEmpty())
//        remove(1);
//}

template<class ItemType>
void LinkedList<ItemType>::addToBack(const ItemType &newEntry)
{
    if(itemCount == 0){
        addToEmpty(newEntry);
    }
    else
    {
        auto newNodePtr = new Node<ItemType>(newEntry);
        auto curPtr = headPtr;

        vector<int>::iterator ptr;

        while(curPtr != nullptr && curPtr -> getNext() != nullptr)
        {
            curPtr = curPtr -> getNext();
        }
        curPtr -> setNext(newNodePtr);
        itemCount++;
    }
}

template<class ItemType>
void LinkedList<ItemType>::addToFront(const ItemType &newEntry)
{
    if(itemCount == 0){
        addToEmpty(newEntry);
    }
    else
    {
        auto newNodePtr = new Node<ItemType>(newEntry);
        auto curPtr = headPtr;

        newNodePtr -> setNext(curPtr);

        headPtr = newNodePtr;

        itemCount++;
    }
}

template<class ItemType>
void LinkedList<ItemType>::removeFromBack()
{
    if(itemCount == 0){
        return;
    }
    else
    {
        auto curPtr = headPtr;
        while(curPtr != nullptr && curPtr -> getNext() -> getNext() != nullptr)
        {
            curPtr = curPtr -> getNext();

        }

        curPtr -> setNext(nullptr);

        itemCount--;
    }
}

template<class ItemType>
void LinkedList<ItemType>::removeFromFront()
{
    if(itemCount == 0){
        return;
    }
    else
    {
        headPtr = headPtr->getNext();

        itemCount--;
    }
}

template<class ItemType>
void LinkedList<ItemType>::print()
{

    LinkedIterator<ItemType> currentIterator = this->begin();
    while(currentIterator != this->end())
    {
        std::cout << *currentIterator << " ";
        ++currentIterator;
    }

}

template<class ItemType>
LinkedIterator<ItemType> LinkedList<ItemType>::begin()
{
    return LinkedIterator<ItemType>(this,headPtr);
}

template<class ItemType>
LinkedIterator<ItemType> LinkedList<ItemType>::end()
{
    return LinkedIterator<ItemType>(this, nullptr);
}



