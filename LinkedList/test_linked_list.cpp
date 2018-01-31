//
//  test_linked_list.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "test_linked_list.hpp"
#include "linked_list.cpp"
using namespace LinkedList;

void TestSingleLinkedListConstructor()
{
    try
    {
        int list[] = {1, 3, 5, 7, 9, 11};
        
        SingleLinkedList<int> linked_list11 (11);
        SingleLinkedList<int> linked_list9 (9, &linked_list11);
        SingleLinkedList<int> linked_list7 (7, &linked_list9);
        SingleLinkedList<int> linked_list5 (5, &linked_list7);
        SingleLinkedList<int> linked_list3 (3, &linked_list5);
        SingleLinkedList<int> linked_list1 (1, &linked_list3);
        
        SingleLinkedList<int>* iter = &linked_list1;
        
        int linked_list_length = 0;
        
        while(iter)
        {
            assert(iter->GetValue() == list[linked_list_length]);
            linked_list_length++;
            iter = iter->GetNextNode();
        }
        
        assert(linked_list_length == 6);
        
        cout << "SingleLinkedList<T> Test Constructors: Passed" << endl;
    } catch (...) {
        cout << "SingleLinkedList<T> Test Constructors: Failed" << endl;
    }
}

void TestSingleLinkedListFind()
{
    try
    {
        SingleLinkedList<int> linked_list11 (11);
        SingleLinkedList<int> linked_list9 (9, &linked_list11);
        SingleLinkedList<int> linked_list7 (7, &linked_list9);
        SingleLinkedList<int> linked_list5 (5, &linked_list7);
        SingleLinkedList<int> linked_list3 (3, &linked_list5);
        SingleLinkedList<int> linked_list1 (1, &linked_list3);
        
        SingleLinkedList<int>* temp7 = &linked_list7;
        SingleLinkedList<int>* find_result = (&linked_list1)->Find(7);
        
        assert(temp7 == find_result);
        assert(temp7->GetValue() == 7);
        cout << "SingleLinkedList<T> Test Find: Passed" << endl;
    } catch (...) {
        cout << "SingleLinkedList<T> Test Find: Failed" << endl;
    }
}

void TestSingleLinkedList()
{
    TestSingleLinkedListConstructor();
    TestSingleLinkedListFind();
}
