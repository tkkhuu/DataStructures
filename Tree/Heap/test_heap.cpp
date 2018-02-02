//
//  test_heap.cpp
//  DataStructures
//
//  Created by Tri Khuu on 2/1/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "test_heap.hpp"

#include <assert.h>
#include <iostream>

//using namespace Heap;
using namespace std;

void TestHeap()
{
    TestMinHeap();
    TestMaxHeap();
}

void TestMinHeap()
{
    
    TestMinHeapPush();
    TestMinHeapPop();
}

void TestMaxHeap()
{
    TestMaxHeapPush();
    TestMaxHeapPop();
}

void TestMinHeapPush()
{
    try
    {
        Heap::MinHeap<int> mheap;
        
        assert(mheap.Size() == 0);
        
        mheap.Push(9);
        assert(mheap.Peek() == 9);
        assert(mheap.Size() == 1);
        
        mheap.Push(2);
        assert(mheap.Peek() == 2);
        assert(mheap.Size() == 2);
        
        mheap.Push(5);
        assert(mheap.Peek() == 2);
        assert(mheap.Size() == 3);
        
        mheap.Push(1);
        assert(mheap.Peek() == 1);
        assert(mheap.Size() == 4);
        
        cout << "MinHeap Test Push: Passed" << endl;
    }
    catch (...)
    {
        cout << "MinHeap Test Push: Failed" << endl;
    }
    
}

void TestMinHeapPop()
{
    try
    {
        
        int list[] = {1, 8, 3, 9, 7, 3, 12};
        Heap::MinHeap<int> mheap;
        
        for (int i : list) mheap.Push(i);
        
        assert(mheap.Size() == 7);
        
        assert(mheap.Pop() == 1);
        assert(mheap.Size() == 6);
        
        assert(mheap.Pop() == 3);
        assert(mheap.Size() == 5);
        
        assert(mheap.Pop() == 3);
        assert(mheap.Size() == 4);
        
        assert(mheap.Pop() == 7);
        assert(mheap.Size() == 3);
        
        assert(mheap.Pop() == 8);
        assert(mheap.Size() == 2);
        
        assert(mheap.Pop() == 9);
        assert(mheap.Size() == 1);
        
        assert(mheap.Pop() == 12);
        assert(mheap.Size() == 0);
        
        cout << "MinHeap Test Pop: Passed" << endl;
    }
    catch (...)
    {
        cout << "MinHeap Test Pop: Failed" << endl;
    }
    
}

void TestMaxHeapPush()
{
    try
    {
        Heap::MaxHeap<int> mheap;
        
        assert(mheap.Size() == 0);
        
        mheap.Push(5);
        assert(mheap.Peek() == 5);
        assert(mheap.Size() == 1);
        
        mheap.Push(2);
        assert(mheap.Peek() == 5);
        assert(mheap.Size() == 2);
        
        mheap.Push(9);
        assert(mheap.Peek() == 9);
        assert(mheap.Size() == 3);
        
        mheap.Push(1);
        assert(mheap.Peek() == 9);
        assert(mheap.Size() == 4);
        
        cout << "MaxHeap Test Push: Passed" << endl;
    }
    catch (...)
    {
        cout << "MaxHeap Test Push: Failed" << endl;
    }
    
}

void TestMaxHeapPop()
{
    try
    {
        int list[] = {1, 8, 3, 9, 7, 3, 12};
        Heap::MaxHeap<int> mheap;
        
        for (int i : list) mheap.Push(i);
        
        assert(mheap.Size() == 7);
        
        assert(mheap.Pop() == 12);
        assert(mheap.Size() == 6);
        
        assert(mheap.Pop() == 9);
        assert(mheap.Size() == 5);
        
        assert(mheap.Pop() == 8);
        assert(mheap.Size() == 4);
        
        assert(mheap.Pop() == 7);
        assert(mheap.Size() == 3);
        
        assert(mheap.Pop() == 3);
        assert(mheap.Size() == 2);
        
        assert(mheap.Pop() == 3);
        assert(mheap.Size() == 1);
        
        assert(mheap.Pop() == 1);
        assert(mheap.Size() == 0);
        
        cout << "MaxHeap Test Pop: Passed" << endl;
    }
    catch (...)
    {
        cout << "MaxHeap Test Pop: Failed" << endl;
    }
    
}
