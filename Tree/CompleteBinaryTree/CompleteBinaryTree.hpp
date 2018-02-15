//
//  CompleteBinaryTree.hpp
//  DataStructures
//
//  Created by Tri Khuu on 2/5/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef CompleteBinaryTree_hpp
#define CompleteBinaryTree_hpp

#include <vector>

namespace CompleteBinaryTree {
    
    template<class T>
    class CompleteBinaryTree
    {
        protected:
            std::vector<T> items;
            unsigned long heap_size;
        
            virtual unsigned long GetLeftChildIndex(unsigned long index);
            virtual unsigned long GetRightChildIndex(unsigned long index);
            virtual unsigned long GetParentIndex(unsigned long index);
            virtual bool HasLeftChild(unsigned long index);
            virtual bool HasRightChild(unsigned long index);
            virtual bool HasParent(unsigned long index);
        
        public:
            CompleteBinaryTree<T>();
            virtual unsigned long Size();
    };
};

#endif /* CompleteBinaryTree_hpp */
