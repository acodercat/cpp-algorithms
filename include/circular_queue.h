//
// Created by codercat on 19-3-12.
//


#ifndef ALGORITHM_CIRCULARQUEUE_H
#define ALGORITHM_CIRCULARQUEUE_H

#include <cassert>

template<typename E>
class CircularQueue {
private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    E *container = NULL;
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
        this->container = new E[capacity];
    }

    void enqueue(E e) {
        assert(!this->isFull());
        this->container[this->tailIndex] = e;
        this->tailIndex = this->getNextIndex(this->tailIndex);
        this->size ++;
    }

    E dequeue() {
        assert(!this->isEmpty());
        E front = this->container[this->frontIndex];
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

    E getFront() {
        return this->container[this->frontIndex];
    }

    unsigned int getSize() {
        return this->size;
    }

    ~CircularQueue() {
        free(this->container);
    }
};


#endif //ALGORITHM_CIRCULARQUEUE_H
