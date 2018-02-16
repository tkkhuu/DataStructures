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

using namespace CompleteBinaryTree;

namespace Heap {
    
    template<typename T>
    class AbsHeap : public AbsCompleteBinaryTree<T>
    {
    protected:
        AbsHeap();
        virtual ~AbsHeap();
        
    public:
        virtual void HeapifyUp() = 0;
        virtual void HeapifyDown() = 0;
        virtual void Push(T new_value);
        virtual T Peek();
        virtual T Pop();
    };
    
    template<typename T>
    class MinHeap : public AbsHeap<T>
    {
        public:
        MinHeap();
        ~MinHeap();
        void HeapifyUp();
        void HeapifyDown();
    };
    
    template<typename T>
    class MaxHeap : public AbsHeap<T>
    {
        public:
        MaxHeap();
        ~MaxHeap();
        void HeapifyUp();
        void HeapifyDown();
    };
    
};



#endif /* heap_hpp */
