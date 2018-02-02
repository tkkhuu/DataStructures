//
//  heap.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/31/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "heap.hpp"

using namespace Heap;

template<class T>
AbsHeap<T>::AbsHeap() : heap_size(0)
{
}

template<class T>
unsigned long AbsHeap<T>::Size() {return heap_size;}

template<class T>
unsigned int AbsHeap<T>::GetLeftChildIndex(unsigned long index) {return 2 * index + 1;}

template<class T>
unsigned int AbsHeap<T>::GetRightChildIndex(unsigned long index) {return 2 * index + 2;}

template<class T>
unsigned int AbsHeap<T>::GetParentIndex(unsigned long index) {return (index - 1) / 2;}

template<class T>
bool AbsHeap<T>::HasLeftChild(unsigned long index) {return GetLeftChildIndex(index) < heap_size;}

template<class T>
bool AbsHeap<T>::HasRightChild(unsigned long index) {return GetRightChildIndex(index) < heap_size;}

template<class T>
bool AbsHeap<T>::HasParent(unsigned long index) {return (index > 0) && (GetParentIndex(index) < heap_size);}

template<class T>
void AbsHeap<T>::Swap(unsigned long index1, unsigned long index2)
{
    T temp = items[index1];
    items[index1] = items[index2];
    items[index2] = temp;
}

template<class T>
T AbsHeap<T>::Peek()
{
    if(heap_size <= 0)
    {
        std::cout << "Can't Peek an empty heap" << std::endl;
        exit(0);
    }
    return items[0];
}

template<class T>
T AbsHeap<T>::Pop()
{
    if(heap_size <= 0)
    {
        std::cout << "Can't Pop an empty heap" << std::endl;
        exit(0);
    }
    
    T result = items[0];
    items[0] = items[heap_size - 1];
    items.erase(items.begin() + (heap_size - 1));
    heap_size--;
    HeapifyDown();
    return result;
}

template<class T>
void AbsHeap<T>::Push(T new_value)
{
    items.push_back(new_value);
    heap_size++;
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
