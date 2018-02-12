//
// Created by uberslam on 2/11/18.
//

#ifndef LINKED_LIST_LINKEDITERATOR_HPP
#define LINKED_LIST_LINKEDITERATOR_HPP

#include <iterator>
#include "Node.hpp"

template<class ItemType>
class LinkedList;

template<class ItemType>
class LinkedIterator : public std::iterator<std::input_iterator_tag, int>
{
private:
    const LinkedList<ItemType>* containerPtr;

    Node<ItemType>* currentItemPtr;

public:
    LinkedIterator(LinkedList<ItemType>* someList, Node<ItemType>* nodePtr = nullptr);

    const ItemType operator*();

    LinkedIterator<ItemType> operator++();

    bool operator==(const LinkedIterator<ItemType>& rightHandSide) const;

    bool operator!=(const LinkedIterator<ItemType>& rightHandSide) const;
};


#endif //LINKED_LIST_LINKEDITERATOR_HPP
