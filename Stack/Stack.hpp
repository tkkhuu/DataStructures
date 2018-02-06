//
//  Stack.hpp
//  DataStructures
//
//  Created by Tri Khuu on 2/5/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "../LinkedList/linked_list.hpp"

namespace Stack
{
    template<class T>
    class Stack
    {
        private:
        LinkedList::SingleLinkedList<T> list;
        
        public:
        Stack<T>();
        
        void Push(T new_value);
        T Peek();
        T Pop();
        
        unsigned long Size();
    };
};

#endif /* Stack_hpp */
