//
// Created by codercat on 19-6-14.
//

#include <iostream>
#include "binary_heap.h"
using namespace std;

bool compare(double a, double b) {
    return a > b;
}

int main() {
    BinaryHeap<double> *minHeap = new BinaryHeap<double>(10, compare);
    minHeap->insert(100);
    minHeap->insert(2.1);
    minHeap->insert(3);
    minHeap->insert(31);
    cout<<"getRoot:"<<minHeap->getRoot()<<endl;
    cout<<"extract:"<<minHeap->extract()<<endl;
    cout<<"extract:"<<minHeap->extract()<<endl;

    int arr[] = {11, 23, 1, 2, 3};
    BinaryHeap<int> *maxHeap = new BinaryHeap<int>(arr, 10, sizeof(arr) / sizeof(int));
    cout<<"heapify: {11, 23, 1, 2, 3}"<<endl;
    cout<<"getRoot:"<<maxHeap->getRoot()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;
}