//
// Created by Jonathon Greene on 2/11/18.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"


// pretty print of doubly linked list
ostream& operator<<(ostream& os, LinkedList<int>* list)
{
    LinkedIterator<int> currentIterator = list->begin();
    string stringified;

    while(currentIterator != list->end())
    {
        stringified += std::to_string(*currentIterator) + " ";
        ++currentIterator;
    }

    stringified += std::to_string(*(list->end()));

    os << stringified;

    return os;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    LinkedList<int>* linkedList = new LinkedList<int>;
//    linkedList->addToFront(12);
//    linkedList->addToFront(15);
    linkedList->addToBack(10);
    linkedList->addToBack(2);
    linkedList->addToBack(3);
//    linkedList->addToFront(12);
    linkedList->addToBack(4);
    linkedList->addToBack(2);
    linkedList->addToBack(1);
    linkedList->addToBack(7);

//    linkedList->removeFromFront();
//    linkedList->removeFromBack();

//    linkedList->swapNodes(1,7);

    linkedList->bubbleSort("descending");
//    linkedList->insert(5,14);
//
//    linkedList->removeAt(3);

//    linkedList->replaceNodeAt(3,10);

//    auto tmpNode = new Node<int>(3);
//    auto tmpNode2 = new Node<int>(6);
//    auto tmpNode = linkedList->getNodeAt(3)->getItem();
//    auto tmpNode2 = linkedList->getNodeAt(6)->getItem();

//    linkedList->replaceNodeAt(6,tmpNode);
//    linkedList->replaceNodeAt(3,tmpNode2);

//    linkedList->addToFront(12);

//    linkedList->removeFromBack();
//    linkedList->removeFromFront();

//    pretty print linked list
    std::cout << linkedList;

//    std::cout << "\nEntry at pos. 2: " << linkedList->getEntry(2);

//    Test to throw error
//    std::cout << "\nEntry at pos. 3: " << linkedList->getEntry(12);

    return 0;
}