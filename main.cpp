//
// Created by Jonathon Greene on 2/11/18.
//

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"


// pretty print of doubly linked list
ostream& operator<<(ostream& os, LinkedList<int>* list)
{
    assert(!(list->isEmpty()));

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
    linkedList->addToBack(1);
//    linkedList->addToFront(12);
    linkedList->addToBack(4);
    linkedList->addToBack(2);
    linkedList->addToBack(1);
    linkedList->addToBack(7);

    linkedList->removeFromFront();
    linkedList->removeFromBack();

    linkedList->swapNodes(1,3);

    linkedList->bubbleSort("descending");
    linkedList->insertAt(5,14);
//
    linkedList->removeAt(3);

    linkedList->replaceNodeAt(3,10);


    linkedList->addToFront(12);

    linkedList->removeFromBack();
    linkedList->removeFromFront();

    linkedList->getEntry(2);

    linkedList->insertAt(2, 4);

    linkedList->push(2);

    linkedList->pop();

//    pretty print linked list
    std::cout << linkedList;

    std::cout << linkedList->search(1);

//    std::cout << "\nEntry at pos. 2: " << linkedList->getEntry(2);

//    Test to throw error
//    std::cout << "\nEntry at pos. 3: " << linkedList->getEntry(12);

    LinkedList<int>* linkedList2 = new LinkedList<int>(linkedList);



//    delete linkedList;
    std::cout << "\nlinkedList2: " << linkedList2;

//    linkedList->clear();

    std::cout << "\nEmpty list: " << linkedList;

    delete linkedList;

    delete linkedList2;

    return 0;
}