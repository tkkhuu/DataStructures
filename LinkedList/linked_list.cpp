//
//  linked_list.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "linked_list.hpp"
using namespace LinkedList;

template<class T>
SingleLinkedList<T>::SingleLinkedList(T _data)
: data(_data), next_node(nullptr)
{
}


template<class T>
SingleLinkedList<T>::SingleLinkedList(T _data, SingleLinkedList<T>* _next_node)
: data(_data), next_node(_next_node)
{
}

 
template<class T>
SingleLinkedList<T>* SingleLinkedList<T>::Find (T _data)
{
    SingleLinkedList<T>* iterator = this;
    while (iterator != nullptr)
    {
        if (iterator->data == _data)
        {
            return iterator;
        }
        iterator = iterator->next_node;
    }
    
    return nullptr;
}

template<class T>
bool SingleLinkedList<T>::HasCycle()
{
    SingleLinkedList* iterator1 = this;
    SingleLinkedList* iterator2 = this;
    
    while(iterator1)
    {
        if (iterator2->next) iterator2 = iterator2->next->next;
        
        iterator1 = iterator1->next;
        
        if (!iterator2 || !iterator2->next) return false;
        
        if (iterator1 == iterator2) return true;
    }
    return false;
}

template <class T>
SingleLinkedList<T>* SingleLinkedList<T>::Reverse()
{
    SingleLinkedList* current = this;
    SingleLinkedList* temp_next;
    SingleLinkedList* previous_node = nullptr;
    
    while(current)
    {
        temp_next = current->next_node;
        current->next_node = previous_node;
        
        previous_node = current;
        current = temp_next;
    }
    return previous_node;
}

template <class T>
void SingleLinkedList<T>::DeleteNode(T _data)
{
    SingleLinkedList** iterator = &this;
    while((*iterator))
    {
        if((*iterator->data) == data)
        {
            (*iterator) = (*iterator->next);
            break;
        }
    }
}

template <class T>
void SingleLinkedList<T>::DeleteAllNodes(T _data)
{
    SingleLinkedList** iterator = &this;
    while((*iterator))
    {
        if((*iterator->data) == data)
        {
            (*iterator) = (*iterator->next);
            break;
        }
        else
        {
            iterator = &((*iterator)->next);
        }
    }
}

template <class T>
T SingleLinkedList<T>::GetValue()
{
    return data;
}

template <class T>
SingleLinkedList<T>* SingleLinkedList<T>::GetNextNode() {
    return next_node;
}
