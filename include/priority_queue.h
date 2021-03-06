//
// Created by codercat on 19-6-14.
//

#ifndef CPP_ALGORITHMS_PRIORITY_QUEUE_H
#define CPP_ALGORITHMS_PRIORITY_QUEUE_H

#include "binary_heap.h"

template<typename E>
class PriorityQueue {
private:
    BinaryHeap<E> *maxHeap;

public:
    PriorityQueue(unsigned capacity) {
        assert(capacity > 0);
        this->maxHeap = new BinaryHeap<E>(capacity);
    }

    void enqueue(E e) {
        return maxHeap->insert(e);
    }

    E dequeue() {
        return maxHeap->extract();
    }

    bool isEmpty() {
        return maxHeap->isEmpty();
    }

    bool isFull() {
        return maxHeap->isFull();
    }

    E getFront() {
        return maxHeap->getRoot();
    }

    unsigned int getSize() {
        return maxHeap->getSize();
    }

};

#endif //CPP_ALGORITHMS_PRIORITY_QUEUE_H
