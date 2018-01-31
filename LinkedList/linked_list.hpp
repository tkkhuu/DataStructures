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
    
    template <class T>
    class SingleLinkedList
    {
        private:
        T data;
        SingleLinkedList<T>* next_node;
        
        public:
        SingleLinkedList(T _data);
        SingleLinkedList(T _data, SingleLinkedList<T>* _next_node);
        
        SingleLinkedList* Find(T _data);
        SingleLinkedList* Reverse();
        SingleLinkedList* GetNextNode();
        void DeleteNode(T _data);
        void DeleteAllNodes(T _data);
        bool HasCycle();
        T GetValue();
        
        static void PrintSingleLinkedList(SingleLinkedList* head)
        {
            SingleLinkedList* iter = head;
            cout << "[";
            while(iter)
            {
                cout << iter->data;
                if(iter->next_node) cout << ", ";
                iter = iter->next_node;
            }
            
            cout << "]" << endl;
        }
    };
};


#endif /* linked_list_h */
