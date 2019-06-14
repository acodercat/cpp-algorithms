//
// Created by codercat on 19-6-14.
//

#ifndef CPP_ALGORITHMS_MAX_HEAP_H
#define CPP_ALGORITHMS_MAX_HEAP_H

#include <math.h>
#include <assert.h>
using namespace std;

template<typename T>
class MaxHeap {
private:
    T *container = NULL;
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

    void shiftUp(unsigned index) {

        while ((index > 0) && this->container[index] > this->container[this->getParentIndex(index)]) {
            swap(this->container[index], this->container[this->getParentIndex(index)]);
            index = this->getParentIndex(index);
        }

    }

    void shiftDown(unsigned index = 0) {
        T e = this->container[index];
        while(this->getSize() > getLeftChildIndex(index)) {
            T maxChildIndex = this->container[getLeftChildIndex(index)];
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
        this->container = new T[capacity];
        this->capacity = capacity;
    }

    void insert(T element) {
        assert(!this->isFull());
        this->container[this->size] = element;
        this->shiftUp(this->size);
        this->size ++;
    }

    T extract() {
        assert(!this->isEmpty());
        T max = this->getMax();
        T tail = this->container[this->getSize() - 1];
        this->setMax(tail);
        this->shiftDown();
        this->size --;
        return max;
    }

    T getMax() {
        return this->container[0];
    }

    void setMax(T element) {
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

};

#endif //CPP_ALGORITHMS_MAX_HEAP_H
