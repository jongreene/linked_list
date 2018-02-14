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
    linkedList->addToBack(1);
    linkedList->addToBack(2);
    linkedList->addToBack(9);
//    linkedList->addToFront(12);
    linkedList->addToBack(4);
    linkedList->addToBack(5);

//    linkedList->removeFromFront();
//    linkedList->removeFromBack();


    linkedList->insert(5,14);

    linkedList->removeAt(3);
//    linkedList->addToFront(12);

//    linkedList->removeFromBack();
//    linkedList->removeFromFront();

//    pretty print linked list
    std::cout << linkedList;

    std::cout << "\nEntry at pos. 2: " << linkedList->getEntry(2);

//    Test to throw error
//    std::cout << "\nEntry at pos. 3: " << linkedList->getEntry(12);

    return 0;
}