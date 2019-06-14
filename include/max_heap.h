//
// Created by codercat on 19-6-14.
//

#ifndef CPP_ALGORITHMS_MAX_HEAP_H
#define CPP_ALGORITHMS_MAX_HEAP_H

#include <math.h>
#include <assert.h>
using namespace std;

template<typename E>
class MaxHeap {
private:
    E *container = NULL;
    unsigned int capacity = 0;
    unsigned int size = 0;

    unsigned getLeftChildIndex(unsigned index) {
        return index * 2 + 1;
    }

    unsigned getRightChildIndex(unsigned index) {
        return this->getLeftChildIndex(index) + 1;
    }

    unsigned getParentIndex(unsigned index) {
        int parentIndex = floor(index / 2) - 1;
        if (parentIndex < 0) {
            return 0;
        }
        return parentIndex;
    }

    unsigned getLastParentIndex() {
        return this->getParentIndex(this->getSize() - 1);
    }

    void shiftUp(unsigned index) {

        while ((index > 0) && this->container[index] > this->container[this->getParentIndex(index)]) {
            swap(this->container[index], this->container[this->getParentIndex(index)]);
            index = this->getParentIndex(index);
        }

    }

    void shiftDown(unsigned index = 0) {
        E e = this->container[index];
        while(this->getSize() > getLeftChildIndex(index)) {
            E maxChildIndex = getLeftChildIndex(index);
            if (this->getSize() > this->container[getRightChildIndex(index)]) {
                if (this->container[getRightChildIndex(index)] > this->container[getLeftChildIndex(index)]) {
                    maxChildIndex = getRightChildIndex(index);
                }
            }
            if (e >= this->container[maxChildIndex]) {
                break;
            }
            this->container[index] = this->container[maxChildIndex];
            index = maxChildIndex;
        }
        this->container[index] = e;
    }

public:
    MaxHeap(unsigned capacity) {
        assert(capacity > 0);
        this->container = new E[capacity];
        this->capacity = capacity;
    }

    // heapify
    MaxHeap(E *arr, unsigned capacity, unsigned size) {
        assert(capacity >= size);
        assert(capacity > 0);
        this->container = arr;
        this->capacity = capacity;
        this->size = size;
        for (int i = this->getLastParentIndex(); i >= 0; i --) {
            this->shiftDown(i);
        }

    }

    void insert(E element) {
        assert(!this->isFull());
        this->container[this->size] = element;
        this->shiftUp(this->size);
        this->size ++;
    }

    E extractMax() {
        assert(!this->isEmpty());
        E max = this->getMax();
        E tail = this->container[this->getSize() - 1];
        this->setMax(tail);
        this->shiftDown();
        this->size --;
        return max;
    }

    E replace(E e) {
        E max = this->getMax();
        this->setMax(max);
        shiftDown();
        return max;
    }

    E getMax() {
        return this->container[0];
    }

    void setMax(E element) {
        this->container[0] = element;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned getSize() {
        return this->size;
    }

    bool isFull() {
        return this->size >= this->capacity;
    }

    ~MaxHeap() {
        free(this->container);
    }

};

#endif //CPP_ALGORITHMS_MAX_HEAP_H
