//
//  CompleteBinaryTree.cpp
//  DataStructures
//
//  Created by Tri Khuu on 2/5/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "CompleteBinaryTree.hpp"
using namespace CompleteBinaryTree;

// ======== Public Methods ========
template <typename T>
unsigned long AbsCompleteBinaryTree<T>::Size() const
{return _heap_size;}

// ======== Protected Methods ========
template <typename T>
unsigned int AbsCompleteBinaryTree<T>::GetLeftChildIndex(unsigned int& index) const
{return 2 * index + 1;}

template <typename T>
unsigned int AbsCompleteBinaryTree<T>::GetRightChildIndex(unsigned int& index) const
{return 2 * index + 2;}

template <typename T>
unsigned int AbsCompleteBinaryTree<T>::GetParentIndex(unsigned int& index) const
{return (index - 1) / 2;}

template <typename T>
bool AbsCompleteBinaryTree<T>::HasLeftChild(unsigned int& index) const
{return GetLeftChildIndex(index) < _heap_size;}

template <typename T>
bool AbsCompleteBinaryTree<T>::HasRightChild(unsigned int& index) const
{return GetRightChildIndex(index) < _heap_size;}

template <typename T>
bool AbsCompleteBinaryTree<T>::HasParent(unsigned int& index) const
{return (index > 0) && (GetParentIndex(index) < _heap_size);}

template <typename T>
void AbsCompleteBinaryTree<T>::Swap(unsigned int index1, unsigned int index2)
{
    T temp = _items[index1];
    _items[index1] = _items[index2];
    _items[index2] = temp;
}

template <typename T>
const T AbsCompleteBinaryTree<T>::GetItem(unsigned int index) const
{return _items[index];}

template <typename T>
const T AbsCompleteBinaryTree<T>::GetLastItem() const
{return _items[_heap_size - 1];}

template <typename T>
void AbsCompleteBinaryTree<T>::SetItem(unsigned int index, const T new_value)
{
    if (index >= 0 && index < _heap_size)
    {
        _items[index] = new_value;
    }
}

template <typename T>
void AbsCompleteBinaryTree<T>::AddItem(const T new_value)
{
    _items.push_back(new_value);
    ++_heap_size;
}

template <typename T>
void AbsCompleteBinaryTree<T>::EraseLastItem()
{
    _items.erase(AbsCompleteBinaryTree<T>::_items.begin() + _heap_size - 1);
    --_heap_size;
}

template<typename T>
AbsCompleteBinaryTree<T>::AbsCompleteBinaryTree() : _heap_size(0){}

template<typename T>
AbsCompleteBinaryTree<T>::~AbsCompleteBinaryTree(){}

