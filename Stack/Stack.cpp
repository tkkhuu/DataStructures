//
//  Stack.cpp
//  DataStructures
//
//  Created by Tri Khuu on 2/5/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "Stack.hpp"

using namespace Stack;

template <class T>
Stack<T>::Stack() : list() {}

template<class T>
void Stack<T>::Push(T new_value)
{
    list.PushToHead(new_value);
}

template<class T>
T Stack<T>::Peek()
{
    return list.PeekHead();
}

template<class T>
T Stack<T>::Pop()
{
    return list.PopHead();
}

template<class T>
unsigned long Stack<T>::Size()
{
    return list.Size();
}
