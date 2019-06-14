//
// Created by codercat on 19-6-14.
//

#include <iostream>
#include "max_heap.h"
using namespace std;

int main() {
    MaxHeap<int> *maxHeap = new MaxHeap<int>(10);
    maxHeap->insert(100);
    maxHeap->insert(2);
    maxHeap->insert(3);
    maxHeap->insert(31);
    cout<<"getMax:"<<maxHeap->getMax()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;
    cout<<"extract:"<<maxHeap->extract()<<endl;
}