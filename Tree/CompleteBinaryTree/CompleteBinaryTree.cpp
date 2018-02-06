//
//  CompleteBinaryTree.cpp
//  DataStructures
//
//  Created by Tri Khuu on 2/5/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "CompleteBinaryTree.hpp"
using namespace CompleteBinaryTree;

template<class T>
CompleteBinaryTree<T>::CompleteBinaryTree() : heap_size(0)
{}

template<class T>
unsigned long CompleteBinaryTree<T>::Size() {return heap_size;}

template<class T>
unsigned int CompleteBinaryTree<T>::GetLeftChildIndex(unsigned long index) {return 2 * index + 1;}

template<class T>
unsigned int CompleteBinaryTree<T>::GetRightChildIndex(unsigned long index) {return 2 * index + 2;}

template<class T>
unsigned int CompleteBinaryTree<T>::GetParentIndex(unsigned long index) {return (index - 1) / 2;}

template<class T>
bool CompleteBinaryTree<T>::HasLeftChild(unsigned long index) {return GetLeftChildIndex(index) < heap_size;}

template<class T>
bool CompleteBinaryTree<T>::HasRightChild(unsigned long index) {return GetRightChildIndex(index) < heap_size;}

template<class T>
bool CompleteBinaryTree<T>::HasParent(unsigned long index) {return (index > 0) && (GetParentIndex(index) < heap_size);}
