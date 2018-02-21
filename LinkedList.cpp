//
// Created by Jonathon Greene on 2/11/18.
//

#include <vector>
#include "LinkedList.hpp"

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

// copy constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList<ItemType>* aList)
{
    itemCount = aList->itemCount;
    Node<ItemType>* origListPtr = aList->headPtr;  // Points to nodes in original chain

    if (origListPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>(aList->headPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newListPtr = headPtr;      // Points to last node in new chain

        newListPtr -> setPrevious(nullptr);

        origListPtr = origListPtr->getNext();     // Advance original-chain pointer

        while (origListPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origListPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newListPtr->setNext(newNodePtr);

            auto newListLastPtr = newListPtr;

            // Advance pointer to new last node
            newListPtr = newListPtr->getNext();

            newListPtr -> setPrevious(newListLastPtr);

            // Advance original-chain pointer
            origListPtr = origListPtr->getNext();
        }  // end while

        newListPtr->setNext(nullptr);              // Flag end of new chain

        tailPtr = newListPtr;
    }  // end if
}  // end copy constructor


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
    return getLength() == 0;
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
        std::string message = "getEntry() called with an empty list or invalid position";
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
bool LinkedList<ItemType>::insertAt(int newPosition, const ItemType& newEntry)
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

            itemCount--;
        }



    }
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        removeAt(1);
}

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

    if(position==1)
    {
        auto oldNode = headPtr;
        auto newNode = new Node<ItemType>(newEntry);

        newNode->setNext(oldNode->getNext());
        newNode->setPrevious(nullptr);

        oldNode->getNext()->setPrevious(newNode);

        headPtr = newNode;

        delete oldNode;
    }
    else if(position==itemCount)
    {
        auto oldNode = tailPtr;
        auto newNode = new Node<ItemType>(newEntry);

        newNode->setNext(nullptr);
        newNode->setPrevious(oldNode->getPrevious());

        oldNode->getPrevious()->setNext(newNode);

        tailPtr = newNode;
        delete oldNode;
    }
    else {
        auto oldNode = getNodeAt(position);
        auto newNode = new Node<ItemType>(newEntry);

        newNode->setNext(oldNode->getNext());
        newNode->setPrevious(oldNode->getPrevious());

        oldNode->getPrevious()->setNext(newNode);
        oldNode->getNext()->setPrevious(newNode);

        delete oldNode;
    }
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
void LinkedList<ItemType>::bubbleSort(string direction)
{
    assert(direction == "ascending" || direction == "descending");

    for(int i=1; i<=itemCount; i++)
    {
        for(int j=1; j<=itemCount; j++)
        {
            if(direction=="ascending" && getNodeAt(i)->getItem() < getNodeAt(j)->getItem())
            {
                swapNodes(i,j);
            }
            else if(direction=="descending" && getNodeAt(i)->getItem() > getNodeAt(j)->getItem()){
                swapNodes(i,j);
            }
        }
    }
}

template<class ItemType>
string LinkedList<ItemType>::search(ItemType querie)
{
    int i=1;
    bool hasValue = false;
    string valueLocation;

    LinkedIterator<int> currentIterator = this->begin();

    while(currentIterator != this->end())
    {
        ++currentIterator;
        i++;

        if(*currentIterator == querie){
            if(valueLocation.length()==0) {
                valueLocation += "\nvalue(s) found at: ";
                hasValue = true;
            }
            valueLocation+=std::to_string(i) + " ";
        }
    }

    if(hasValue)
        return valueLocation;
    else
        return "Value not found";
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



