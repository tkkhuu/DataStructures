//
//  linked_list.h
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <iostream>

using namespace std;

namespace LinkedList {
    
    template<class T>
    struct SingleLinkedListNode
    {
        /** Value. */
        T value;
        
        /** Pointers to next node. */
        SingleLinkedListNode<T>* next_node;

        SingleLinkedListNode<T>(T _data);
        
    };
    
    template <class T>
    class SingleLinkedList
    {
        private:
        SingleLinkedListNode<T>* head;
        SingleLinkedListNode<T>* tail;
        unsigned long list_size;
        
        public:
        SingleLinkedList();
        ~SingleLinkedList();
        
        void AddNodeToHead(T _data);
        void AddNodeToTail(T _data);
        
        void DeleteNode(T _data);
        void DeleteAllNodes(T _data);
        bool Contains(T _data);
        void Reverse();
        
        T GetHead();
        T GetTail();
        unsigned long Size();
        
        void PrintSingleLinkedList();
    };
};


#endif /* linked_list_h */
