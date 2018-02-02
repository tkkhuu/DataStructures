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
SingleLinkedListNode<T>::SingleLinkedListNode(T _data)
: value(_data), next_node(nullptr)
{
}

template<class T>
SingleLinkedList<T>::SingleLinkedList()
: head(nullptr), tail(nullptr), list_size(0)
{
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList<T>()
{
    SingleLinkedListNode<T>* iter = head;
    while(iter)
    {
        SingleLinkedListNode<T>* next = iter->next_node;
        delete iter;
        iter = next;
    }
}

template <class T>
void SingleLinkedList<T>::AddNodeToHead(T _data)
{
    if (!head)
    {
        head = new SingleLinkedListNode<T>(_data);
        tail = head;
    }
    else
    {
        SingleLinkedListNode<T>* temp = new SingleLinkedListNode<T>(_data);
        temp->next_node = head;
        head = temp;
    }
    list_size++;
}

template <class T>
void SingleLinkedList<T>::AddNodeToTail(T _data)
{
    if (!tail)
    {
        AddNodeToHead(_data);
    }
    else
    {
        SingleLinkedListNode<T>* temp = new SingleLinkedListNode<T>(_data);
        tail->next_node = temp;
        tail = temp;
        list_size++;
    }
}

template <class T>
T SingleLinkedList<T>::GetHead() {return head->value;}

template <class T>
T SingleLinkedList<T>::GetTail() {return tail->value;}

template <class T>
unsigned long SingleLinkedList<T>::Size() {return list_size;}

template <class T>
void SingleLinkedList<T>::PrintSingleLinkedList()
{
    SingleLinkedListNode<T>* iter = head;
    cout << "[";
    while(iter)
    {
        cout << iter->value;
        if(iter->next_node) cout << ", ";
        iter = iter->next_node;
    }
    
    cout << "]" << endl;
}
 
template<class T>
bool SingleLinkedList<T>::Contains (T _data)
{
    SingleLinkedListNode<T>* iterator = head;
    while (iterator)
    {
        if (iterator->value == _data)
        {
            return true;
        }
        iterator = iterator->next_node;
    }
    
    return false;
}

template<class T>
void SingleLinkedList<T>::DeleteNode(T _data)
{
    if(!head) return;
    if(head->value == _data)
    {
        if (list_size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next_node;
        }
    }
    
    else
    {
        SingleLinkedListNode<T>* iter = head;
        while(iter)
        {
            if(iter->next_node && iter->next_node->value == _data)
            {
                if(iter->next_node == tail)
                {
                    iter->next_node = nullptr;
                    tail = iter;
                }
                else
                {
                    iter->next_node = iter->next_node->next_node;
                }
                break;
            }
            iter = iter->next_node;
        }
    }
    list_size--;
}

template <class T>
void SingleLinkedList<T>::Reverse()
{
    tail = head;
    SingleLinkedListNode<T>* current = head;
    SingleLinkedListNode<T>* temp_next;
    SingleLinkedListNode<T>* previous_node = nullptr;
    
    while(current)
    {
        temp_next = current->next_node;
        current->next_node = previous_node;
        
        previous_node = current;
        current = temp_next;
    }
    
    head = previous_node;
}


template <class T>
void SingleLinkedList<T>::DeleteAllNodes(T _data)
{
    
    SingleLinkedListNode<T>* iter = head;
    while(iter)
    {
        if(iter->next_node && iter->next_node->value == _data)
        {
            list_size--;
            if (iter->next_node == tail)
            {
                iter->next_node = nullptr;
                tail = iter;
                break;
            }
            else
            {
                iter->next_node = iter->next_node->next_node;
            }
        }
        iter = iter->next_node;
    }
    
    if (head->value == _data)
    {
        head = head->next_node;
        list_size--;
    }
}



