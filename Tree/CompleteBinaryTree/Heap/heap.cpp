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

template<class T>
AbsHeap<T>::AbsHeap() : CompleteBinaryTree<T>()
{
}

template<class T>
void AbsHeap<T>::Swap(unsigned long index1, unsigned long index2)
{
    T temp = CompleteBinaryTree<T>::items[index1];
    CompleteBinaryTree<T>::items[index1] = CompleteBinaryTree<T>::items[index2];
    CompleteBinaryTree<T>::items[index2] = temp;
}

template<class T>
T AbsHeap<T>::Peek()
{
    if(CompleteBinaryTree<T>::heap_size <= 0)
    {
        std::cout << "Can't Peek an empty heap" << std::endl;
        exit(0);
    }
    return CompleteBinaryTree<T>::items[0];
}

template<class T>
T AbsHeap<T>::Pop()
{
    if(CompleteBinaryTree<T>::heap_size <= 0)
    {
        std::cout << "Can't Pop an empty heap" << std::endl;
        exit(0);
    }
    
    T result = CompleteBinaryTree<T>::items[0];
    CompleteBinaryTree<T>::items[0] = CompleteBinaryTree<T>::items[CompleteBinaryTree<T>::heap_size - 1];
    CompleteBinaryTree<T>::items.erase(CompleteBinaryTree<T>::items.begin() + (CompleteBinaryTree<T>::heap_size - 1));
    CompleteBinaryTree<T>::heap_size--;
    HeapifyDown();
    return result;
}

template<class T>
void AbsHeap<T>::Push(T new_value)
{
    CompleteBinaryTree<T>::items.push_back(new_value);
    CompleteBinaryTree<T>::heap_size++;
    HeapifyUp();
}

template<class T>
MinHeap<T>::MinHeap() : AbsHeap<T>()
{
}

template<class T>
void MinHeap<T>::HeapifyUp()
{
    unsigned long current_item_index = AbsHeap<T>::heap_size - 1;
    
    while(AbsHeap<T>::HasParent(current_item_index))
    {
        unsigned long parent_index = AbsHeap<T>::GetParentIndex(current_item_index);
        if (AbsHeap<T>::items[current_item_index] < AbsHeap<T>::items[parent_index])
        {
            AbsHeap<T>::Swap(current_item_index, parent_index);
        }
        current_item_index = parent_index;
    }
}

template<class T>
void MinHeap<T>::HeapifyDown()
{
    unsigned long current_index = 0;
    
    while (AbsHeap<T>::HasLeftChild(current_index))
    {
        unsigned long small_child_index = AbsHeap<T>::GetLeftChildIndex(current_index);
        if (AbsHeap<T>::HasRightChild(current_index))
        {
            unsigned long right_child_index = AbsHeap<T>::GetRightChildIndex(current_index);
            if (AbsHeap<T>::items[right_child_index] < AbsHeap<T>::items[small_child_index])
            {
                small_child_index = right_child_index;
            }
            
        }
        
        if (AbsHeap<T>::items[small_child_index] < AbsHeap<T>::items[current_index])
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

template<class T>
MaxHeap<T>::MaxHeap() : AbsHeap<T>()
{
}

template<class T>
void MaxHeap<T>::HeapifyUp()
{
    unsigned long current_item_index = AbsHeap<T>::heap_size - 1;
    while(AbsHeap<T>::HasParent(current_item_index))
    {
        unsigned long parent_index = AbsHeap<T>::GetParentIndex(current_item_index);
        if (AbsHeap<T>::items[current_item_index] > AbsHeap<T>::items[parent_index])
        {
            AbsHeap<T>::Swap(current_item_index, parent_index);
        }
        current_item_index = parent_index;
    }
}

template<class T>
void MaxHeap<T>::HeapifyDown()
{
    unsigned long current_index = 0;
    
    while (AbsHeap<T>::HasLeftChild(current_index))
    {
        unsigned long large_child_index = AbsHeap<T>::GetLeftChildIndex(current_index);
        if (AbsHeap<T>::HasRightChild(current_index))
        {
            unsigned long right_child_index = AbsHeap<T>::GetRightChildIndex(current_index);
            if (AbsHeap<T>::items[right_child_index] > AbsHeap<T>::items[large_child_index])
            {
                large_child_index = right_child_index;
            }
            
        }
        
        if (AbsHeap<T>::items[large_child_index] > AbsHeap<T>::items[current_index])
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
