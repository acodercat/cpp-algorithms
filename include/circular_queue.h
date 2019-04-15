//
// Created by codercat on 19-3-12.
//


#ifndef ALGORITHM_CIRCULARQUEUE_H
#define ALGORITHM_CIRCULARQUEUE_H

#include <malloc.h>
#include <cstring>
#include <assert.h>

class CircularQueue {
private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    int *arr = NULL;
    int frontIndex = 0;
    int tailIndex = 0;

    int getNextIndex(int index) {
      return (int)(index + 1) % this->capacity;
    }

public:
    CircularQueue(unsigned int capacity) {
        assert(capacity > 0);
        this->capacity = capacity;
        this->frontIndex = 0;
        this->tailIndex = 0;
        this->arr = (int *)malloc(capacity * sizeof(int));
        memset(this->arr, 0, capacity * sizeof(int));
    }

    void enqueue(int v) {
        assert(!this->isFull());
        this->arr[this->tailIndex] = v;
        this->tailIndex = this->getNextIndex(this->tailIndex);

        this->size ++;
    }

    int dequeue() {
        assert(!this->isEmpty());
        int front = this->arr[this->frontIndex];
        this->frontIndex = this->getNextIndex(this->frontIndex);
        this->size --;
        return front;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    bool isFull() {
        return this->getSize() == this->capacity;
    }

    unsigned int getSize() {
        return this->size;
    }

    ~CircularQueue() {
        free(this->arr);
    }
};


#endif //ALGORITHM_CIRCULARQUEUE_H
