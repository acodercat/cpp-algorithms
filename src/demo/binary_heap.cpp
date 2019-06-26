//
// Created by codercat on 19-6-14.
//

#include <iostream>
#include "binary_heap.h"
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    // default is maxHeap
    BinaryHeap<double> *maxHeap = new BinaryHeap<double>(10);
    maxHeap->insert(100);
    maxHeap->insert(2.1);
    maxHeap->insert(3);
    maxHeap->insert(31);

    cout<<"getRoot:"<<maxHeap->getRoot()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;

    int arr[] = { -4,-5,-8,-21,-12,40,123,50,-40 };
    BinaryHeap<int> *minHeap = new BinaryHeap<int>(arr, 9, sizeof(arr) / sizeof(int), compare);
    cout<<"heapify: { -4,-5,-8,-21,-12,40,123,50,-40 }"<<endl;
    cout<<"getRoot:"<<minHeap->getRoot()<<endl;
    cout<<"extract:"<<minHeap->extract()<<endl;
    cout<<"extract:"<<minHeap->extract()<<endl;
    cout<<"extract:"<<minHeap->extract()<<endl;
}