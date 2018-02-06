//
//  test_linked_list.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "test_linked_list.hpp"

using namespace LinkedList;

void TestSingleLinkedList()
{
    TestSingleLinkedListAdd();
    TestSingleLinkedListDelete();
    TestSingleLinkedListContains();
    TestSingleLinkedListReverse();
    TestSingleLinkedListDeleteAll();
    TestSingleLinkedListPopHead();
    TestSingleLinkedListPopTail();
}

void TestSingleLinkedListAdd()
{
    try
    {
        SingleLinkedList<int> linked_list;
        linked_list.PushToHead(11);
        assert(linked_list.PeekHead() == 11);
        assert(linked_list.PeekTail() == 11);
        assert(linked_list.Size() == 1);
        
        linked_list.PushToHead(9);
        assert(linked_list.PeekHead() == 9);
        assert(linked_list.PeekTail() == 11);
        assert(linked_list.Size() == 2);
        
        linked_list.PushToHead(7);
        assert(linked_list.PeekHead() == 7);
        assert(linked_list.PeekTail() == 11);
        assert(linked_list.Size() == 3);
        
        linked_list.PushToTail(4);
        assert(linked_list.PeekHead() == 7);
        assert(linked_list.PeekTail() == 4);
        assert(linked_list.Size() == 4);
        
        
        linked_list.PushToTail(2);
        assert(linked_list.PeekHead() == 7);
        assert(linked_list.PeekTail() == 2);
        assert(linked_list.Size() == 5);
        
        linked_list.PushToHead(5);
        assert(linked_list.PeekHead() == 5);
        assert(linked_list.PeekTail() == 2);
        assert(linked_list.Size() == 6);
        
        linked_list.PushToTail(6);
        assert(linked_list.PeekHead() == 5);
        assert(linked_list.PeekTail() == 6);
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
            mlist.PushToTail(i);
        }
        
        mlist.DeleteNode(1);
        assert(mlist.PeekHead() == 3);
        assert(mlist.PeekTail() == 6);
        assert(mlist.Size() == 5);
        
        mlist.DeleteNode(6);
        assert(mlist.PeekHead() == 3);
        assert(mlist.PeekTail() == 4);
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
            mlist.PushToTail(i);
        }
        
        mlist.DeleteAllNodes(1);
        assert(mlist.Size() == 4);
        assert(mlist.PeekHead() == 3);
        assert(mlist.PeekTail() == 9);
        
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
            mlist.PushToHead(i);
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
            mlist.PushToTail(n);
        }
        
        mlist.Reverse();
        assert(mlist.PeekTail() == 1);
        assert(mlist.PeekHead() == 9);
        cout << "SingleLinkedList<T> Test Reverse List: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Reverse List: Failed" << endl;
    }
}

void TestSingleLinkedListPopHead()
{
    try
    {
        int list[] = {1, 3, 5, 7, 9};
        SingleLinkedList<int> mlist;
        for (int n : list)
        {
            mlist.PushToTail(n);
        }
        
        assert(mlist.PopHead() == 1);
        assert(mlist.PeekTail() == 9);
        assert(mlist.PeekHead() == 3);
        
        assert(mlist.PopHead() == 3);
        assert(mlist.PeekTail() == 9);
        assert(mlist.PeekHead() == 5);
        cout << "SingleLinkedList<T> Test Pop Head: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Pop Head: Failed" << endl;
    }
}

void TestSingleLinkedListPopTail()
{
    try
    {
        int list[] = {1, 3, 5, 7, 9};
        SingleLinkedList<int> mlist;
        for (int n : list)
        {
            mlist.PushToTail(n);
        }

        assert(mlist.PopTail() == 9);
        assert(mlist.PeekTail() == 7);
        assert(mlist.PeekHead() == 1);
        
        assert(mlist.PopTail() == 7);
        assert(mlist.PeekTail() == 5);
        assert(mlist.PeekHead() == 1);
        cout << "SingleLinkedList<T> Test Pop Tail: Passed" << endl;
    }
    catch(...)
    {
        cout << "SingleLinkedList<T> Test Pop Tail: Failed" << endl;
    }
}
