//
// Created by codercat on 19-3-12.
//


#ifndef ALGORITHM_CIRCULARQUEUE_H
#define ALGORITHM_CIRCULARQUEUE_H

#include <stdlib.h>
#include <cstring>
#include <assert.h>

template<typename T>
class CircularQueue {
private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    T *container = NULL;
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
        this->container = (T *)malloc(capacity * sizeof(T));
        memset(this->container, 0, capacity * sizeof(T));
    }

    void enqueue(T v) {
        assert(!this->isFull());
        this->container[this->tailIndex] = v;
        this->tailIndex = this->getNextIndex(this->tailIndex);
        this->size ++;
    }

    T dequeue() {
        assert(!this->isEmpty());
        T front = this->container[this->frontIndex];
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
        free(this->container);
    }
};


#endif //ALGORITHM_CIRCULARQUEUE_H
