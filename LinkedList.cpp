//
// Created by Jonathon Greene on 2/11/18.
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
    headPtr->setPrevious(nullptr);

    tailPtr = newNodePtr;

    itemCount++;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return getLength() > 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) throw()
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
//        TODO: refactor this code
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position";
        throw(message);
    }
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position)
{
    assert( (position >= 1) && (position <= itemCount) );

    LinkedIterator<int> currentIterator = this->begin();

    for (int i = 1; i < position; i++)
    {
        ++currentIterator;
    }
    return currentIterator.getPointer();
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1 && (newPosition <=  itemCount + 1));
    if (ableToInsert)
    {
        if (newPosition == 1)
        {
            addToFront(newEntry);
        }
        else if(newPosition == itemCount)
        {
            addToBack(newEntry);
        }
        else
        {
            auto newNodePtr = new Node<ItemType>(newEntry);

            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

            newNodePtr -> setNext(prevPtr -> getNext());
            prevPtr -> setNext(newNodePtr);
            itemCount++;
        }
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::removeAt(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove) {
        if (position == 1)
        {
            removeFromFront();
        }
        else if(position == itemCount)
        {
            removeFromBack();
        }
        else
        {
            auto toBeReplaced = getNodeAt(position);

            auto prevPtr = toBeReplaced -> getPrevious();

            auto nextPtr = toBeReplaced -> getNext();

            prevPtr -> setNext(nextPtr);

            nextPtr -> setPrevious(prevPtr);

            delete toBeReplaced;
        }


        itemCount--;
    }
}

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

        auto prevTail = tailPtr;

        tailPtr -> setNext(newNodePtr);

        tailPtr = tailPtr -> getNext();

        tailPtr -> setPrevious(prevTail);

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

        newNodePtr -> setNext(headPtr);

        headPtr -> setPrevious(newNodePtr);

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
        auto oldTail = tailPtr;

        tailPtr = oldTail -> getPrevious();

        tailPtr -> setNext(nullptr);

        delete oldTail;

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
        auto oldHead = headPtr;

        headPtr = oldHead->getNext();

        delete oldHead;

        itemCount--;
    }
}

template<class ItemType>
void LinkedList<ItemType>::swapNodes(int firstPosition, int secondPosition)
{
    auto firstNode = getNodeAt(firstPosition);
    auto secondNode = getNodeAt(secondPosition);

    ItemType firstItem = firstNode->getItem();
    ItemType secondItem = secondNode->getItem();

    replaceNodeAt(firstPosition, secondItem);
    replaceNodeAt(secondPosition, firstItem);

}

template<class ItemType>
void LinkedList<ItemType>::replaceNodeAt(int position, const ItemType &newEntry)
{
    auto oldNode = getNodeAt(position);
    auto newNode = new Node<ItemType>(newEntry);

    newNode -> setNext(oldNode->getNext());
    newNode -> setPrevious(oldNode->getPrevious());

    oldNode -> getPrevious() -> setNext(newNode);
    oldNode -> getNext() -> setPrevious(newNode);

    delete oldNode;
}

template<class ItemType>
void LinkedList<ItemType>::push(const ItemType &newEntry)
{
    addToFront(newEntry);
}

template<class ItemType>
void LinkedList<ItemType>::pop()
{
    removeFromFront();
}

template<class ItemType>
LinkedIterator<ItemType> LinkedList<ItemType>::begin()
{
    return LinkedIterator<ItemType>(this,headPtr);
}

template<class ItemType>
LinkedIterator<ItemType> LinkedList<ItemType>::end()
{
    return LinkedIterator<ItemType>(this, tailPtr);
}



