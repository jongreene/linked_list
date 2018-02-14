//
// Created by Jonathon Greene on 2/11/18.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

ostream& operator<<(ostream& os, LinkedList<int>* list)
{
    LinkedIterator<int> currentIterator = list->begin();
    string stringified;

    while(currentIterator != list->end())
    {
        stringified += std::to_string(*currentIterator) + " ";
        ++currentIterator;
    }

    os << stringified;

    return os;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    LinkedList<int>* linkedList = new LinkedList<int>;
//    linkedList->addToFront(12);
//    linkedList->addToFront(15);
    linkedList->addToBack(1);
    linkedList->addToBack(2);
    linkedList->addToBack(3);
    linkedList->addToFront(12);
    linkedList->addToBack(4);

    linkedList->removeFromFront();


//    linkedList->insert(2,14);

//    linkedList->addToFront(12);

//    linkedList->removeFromBack();
//    linkedList->removeFromFront();

//    linkedList->print();

    std::cout << linkedList;

//    std::cout << "length: " << linkedList->getLength();
//    << " item 1: " << linkedList->getEntry(1) << " item 2: " << linkedList->getEntry(2);

    return 0;
}