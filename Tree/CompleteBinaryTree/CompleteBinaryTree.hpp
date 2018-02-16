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
    
    template<typename T>
    class AbsCompleteBinaryTree
    {
        std::vector<T> _items;
        unsigned long _heap_size;
        
    protected:
        AbsCompleteBinaryTree<T>();
        virtual ~AbsCompleteBinaryTree<T>();
        
        const T GetItem(unsigned int) const;
        const T GetLastItem() const;
        void SetItem(unsigned int, const T);
        void EraseLastItem();
        void AddItem(const T);
        virtual void Swap(unsigned int, unsigned int);
        virtual unsigned int GetLeftChildIndex(unsigned int&) const;
        virtual unsigned int GetRightChildIndex(unsigned int&) const;
        virtual unsigned int GetParentIndex(unsigned int&) const;
        virtual bool HasLeftChild(unsigned int&) const;
        virtual bool HasRightChild(unsigned int&) const;
        virtual bool HasParent(unsigned int&) const;
        
    public:
        virtual unsigned long Size() const;
    };
};

#endif /* CompleteBinaryTree_hpp */
