//
//  heap.hpp
//  DataStructures
//
//  Created by Tri Khuu on 1/31/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <vector>
#include <iostream>

#include "../CompleteBinaryTree.hpp"

namespace Heap {
    
    template<class T>
    class AbsHeap : class CompleteBinaryTree
    {
        virtual void Swap(unsigned long index1, unsigned long index2);
        
        public:
        AbsHeap();
        virtual void HeapifyUp() = 0;
        virtual void HeapifyDown() = 0;
        
        virtual T Peek();
        virtual T Pop();
        virtual void Push(T new_value);
        
    };
    
    template<class T>
    class MinHeap : public AbsHeap<T>
    {
        public:
        MinHeap();
        void HeapifyUp();
        void HeapifyDown();
    };
    
    template<class T>
    class MaxHeap : public AbsHeap<T>
    {
        public:
        MaxHeap();
        void HeapifyUp();
        void HeapifyDown();
    };
    
};



#endif /* heap_hpp */
