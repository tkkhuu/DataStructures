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

void TestSingleLinkedListAdd()
{
    try
    {
        SingleLinkedList<int> linked_list;
        linked_list.AddNodeToHead(11);
        assert(linked_list.GetHead() == 11);
        assert(linked_list.GetTail() == 11);
        assert(linked_list.Size() == 1);
        
        linked_list.AddNodeToHead(9);
        assert(linked_list.GetHead() == 9);
        assert(linked_list.GetTail() == 11);
        assert(linked_list.Size() == 2);
        
        linked_list.AddNodeToHead(7);
        assert(linked_list.GetHead() == 7);
        assert(linked_list.GetTail() == 11);
        assert(linked_list.Size() == 3);
        
        linked_list.AddNodeToTail(4);
        assert(linked_list.GetHead() == 7);
        assert(linked_list.GetTail() == 4);
        assert(linked_list.Size() == 4);
        
        
        linked_list.AddNodeToTail(2);
        assert(linked_list.GetHead() == 7);
        assert(linked_list.GetTail() == 2);
        assert(linked_list.Size() == 5);
        
        linked_list.AddNodeToHead(5);
        assert(linked_list.GetHead() == 5);
        assert(linked_list.GetTail() == 2);
        assert(linked_list.Size() == 6);
        
        linked_list.AddNodeToTail(6);
        assert(linked_list.GetHead() == 5);
        assert(linked_list.GetTail() == 6);
        assert(linked_list.Size() == 7);

        cout << "SingleLinkedList<T> Test Add Node: Passed" << endl;
    } catch (...) {
        cout << "SingleLinkedList<T> Test Add Node: Failed" << endl;
    }
}

void TestSingleLinkedListDelete()
{
    try
    {
        int list0[] = {1, 3, 5, 2, 4, 6};
        
        SingleLinkedList<int> mlist;
        for (int i : list0)
        {
            mlist.AddNodeToTail(i);
        }
        
        mlist.DeleteNode(1);
        assert(mlist.GetHead() == 3);
        assert(mlist.GetTail() == 6);
        assert(mlist.Size() == 5);
        
        mlist.DeleteNode(6);
        assert(mlist.GetHead() == 3);
        assert(mlist.GetTail() == 4);
        assert(mlist.Size() == 4);
        
        cout << "SingleLinkedList<T> Test Delete Node: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Delete Node: Failed" << endl;
    }
}

void TestSingleLinkedListDeleteAll()
{
    try
    {
        int list[] = {1, 3, 1, 5, 2, 1, 9, 1};
        
        SingleLinkedList<int> mlist;
        
        for (int i : list)
        {
            mlist.AddNodeToTail(i);
        }
        
        mlist.DeleteAllNodes(1);
        assert(mlist.Size() == 4);
        assert(mlist.GetHead() == 3);
        assert(mlist.GetTail() == 9);
        
        cout << "SingleLinkedList<T> Test Delete All Nodes With Value: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Delete All Nodes With Value: Passed" << endl;
    }
}

void TestSingleLinkedListContains()
{
    try
    {
        int list[] = {2, 4, 6, 8};
        
        SingleLinkedList<int> mlist;
        
        for(int i : list)
        {
            mlist.AddNodeToHead(i);
        }
        
        assert(mlist.Contains(2));
        assert(!mlist.Contains(1));
        
        cout << "SingleLinkedList<T> Test Contains Node: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Contains Node: Failed" << endl;
    }
}

void TestSingleLinkedListReverse()
{
    try
    {
        int list[] = {1, 3, 5, 7, 9};
        SingleLinkedList<int> mlist;
        for (int n : list)
        {
            mlist.AddNodeToTail(n);
        }
        
        mlist.Reverse();
        assert(mlist.GetTail() == 1);
        assert(mlist.GetHead() == 9);
        cout << "SingleLinkedList<T> Test Reverse List: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Reverse List: Failed" << endl;
    }
}

void TestSingleLinkedList()
{
    TestSingleLinkedListAdd();
    TestSingleLinkedListDelete();
    TestSingleLinkedListContains();
    TestSingleLinkedListReverse();
    TestSingleLinkedListDeleteAll();
}
