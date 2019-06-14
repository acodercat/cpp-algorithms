//
// Created by codercat on 19-6-14.
//

#include <iostream>
#include "max_heap.h"
using namespace std;

int main() {
    MaxHeap<int> *maxHeap1 = new MaxHeap<int>(10);
    maxHeap1->insert(100);
    maxHeap1->insert(2);
    maxHeap1->insert(3);
    maxHeap1->insert(31);
    cout<<"getMax:"<<maxHeap1->getMax()<<endl;
    cout<<"extractMax:"<<maxHeap1->extractMax()<<endl;
    cout<<"extractMax:"<<maxHeap1->extractMax()<<endl;

    int arr[] = {11, 23, 1, 2, 3};
    MaxHeap<int> *maxHeap2 = new MaxHeap<int>(arr, 10, sizeof(arr) / sizeof(int));
    cout<<"heapify: {11, 23, 1, 2, 3}"<<endl;
    cout<<"getMax:"<<maxHeap2->getMax()<<endl;
    cout<<"extractMax:"<<maxHeap2->extractMax()<<endl;
}