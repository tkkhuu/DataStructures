//
//  heap.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/31/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "heap.hpp"
#include "../CompleteBinaryTree.cpp"

using namespace Heap;

// **************** AbsHeap ****************
// ======== Public Methods ========
template<typename T>
T AbsHeap<T>::Peek()
{
    if(AbsHeap<T>::Size() <= 0)
    {
        std::cout << "Can't Peek an empty heap" << std::endl;
        exit(0);
    }
    return AbsHeap<T>::GetItem(0);
}

template<class T>
T AbsHeap<T>::Pop()
{
    if(AbsHeap<T>::Size() <= 0)
    {
        std::cout << "Can't Pop an empty heap" << std::endl;
        exit(0);
    }
    
    T result = AbsHeap<T>::GetItem(0);
    T last_item_in_heap = AbsHeap<T>::GetLastItem();
    AbsHeap<T>::SetItem(0, last_item_in_heap);
    AbsHeap<T>::EraseLastItem();
    HeapifyDown();
    return result;
}

template<class T>
void AbsHeap<T>::Push(T new_value)
{
    AbsHeap<T>::AddItem(new_value);
    HeapifyUp();
}

// ======== Protected Methods ========
template<class T>
AbsHeap<T>::AbsHeap() : AbsCompleteBinaryTree<T>() {}

template<class T>
AbsHeap<T>::~AbsHeap() {}

// **************** MinHeap ****************
// ======== Public Methods ========
template<class T>
MinHeap<T>::MinHeap() : AbsHeap<T>(){}

template<class T>
MinHeap<T>::~MinHeap(){}

template<class T>
void MinHeap<T>::HeapifyUp()
{
    unsigned int current_item_index = AbsHeap<T>::Size() - 1;
    
    while(AbsHeap<T>::HasParent(current_item_index))
    {
        unsigned int parent_index = AbsHeap<T>::GetParentIndex(current_item_index);
        if (AbsHeap<T>::GetItem(current_item_index) < AbsHeap<T>::GetItem(parent_index))
        {
            AbsHeap<T>::Swap(current_item_index, parent_index);
        }
        current_item_index = parent_index;
    }
}

template<class T>
void MinHeap<T>::HeapifyDown()
{
    unsigned int current_index = 0;
    
    while (AbsHeap<T>::HasLeftChild(current_index))
    {
        unsigned int small_child_index = AbsHeap<T>::GetLeftChildIndex(current_index);
        if (AbsHeap<T>::HasRightChild(current_index))
        {
            unsigned int right_child_index = AbsHeap<T>::GetRightChildIndex(current_index);
            if (AbsHeap<T>::GetItem(right_child_index) < AbsHeap<T>::GetItem(small_child_index))
            {
                small_child_index = right_child_index;
            }
            
        }
        
        if (AbsHeap<T>::GetItem(small_child_index) < AbsHeap<T>::GetItem(current_index))
        {
            AbsHeap<T>::Swap(small_child_index, current_index);
        }
        else
        {
            break;
        }
        current_index = small_child_index;
    }
}

// **************** MaxHeap ****************
// ======== Public Methods ========

template<class T>
MaxHeap<T>::MaxHeap() : AbsHeap<T>(){}

template<class T>
MaxHeap<T>::~MaxHeap(){}

template<class T>
void MaxHeap<T>::HeapifyUp()
{
    unsigned int current_item_index = AbsHeap<T>::Size() - 1;
    while(AbsHeap<T>::HasParent(current_item_index))
    {
        unsigned int parent_index = AbsHeap<T>::GetParentIndex(current_item_index);
        if (AbsHeap<T>::GetItem(current_item_index) > AbsHeap<T>::GetItem(parent_index))
        {
            AbsHeap<T>::Swap(current_item_index, parent_index);
        }
        current_item_index = parent_index;
    }
}

template<class T>
void MaxHeap<T>::HeapifyDown()
{
    unsigned int current_index = 0;
    
    while (AbsHeap<T>::HasLeftChild(current_index))
    {
        unsigned int large_child_index = AbsHeap<T>::GetLeftChildIndex(current_index);
        if (AbsHeap<T>::HasRightChild(current_index))
        {
            unsigned int right_child_index = AbsHeap<T>::GetRightChildIndex(current_index);
            if (AbsHeap<T>::GetItem(right_child_index) > AbsHeap<T>::GetItem(large_child_index))
            {
                large_child_index = right_child_index;
            }
            
        }
        
        if (AbsHeap<T>::GetItem(large_child_index) > AbsHeap<T>::GetItem(current_index))
        {
            AbsHeap<T>::Swap(large_child_index, current_index);
        }
        else
        {
            break;
        }
        current_index = large_child_index;
    }
}
