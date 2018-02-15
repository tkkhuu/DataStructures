//
//  main.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include <iostream>
#include "Matrix/test_matrix.hpp"
#include "LinkedList/test_linked_list.hpp"
#include "Tree/CompleteBinaryTree/Heap/test_heap.hpp"
#include "Numbers/numbers.hpp"


#include <cstdio>
int main(int argc, const char * argv[]) {
    
    //std::cout << "============ Test Matrix ============" << endl;
    //TestMatrix2D();
    
    //std::cout << "============ Test Linked List ============" << endl;
    //TestSingleLinkedList();
    
    //std::cout << "============ Test Heap ============" << endl;
    //TestHeap();
    
    for (int i = 1100; i < 1200; i++)
    {
        Number::UnsignedInteger my_int = i;
        cout << i << ": " << my_int.ToWord() << endl;
    }
    
    
    
    return 0;
    
    
}
