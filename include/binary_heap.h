//
// Created by codercat on 19-6-14.
//

#ifndef CPP_ALGORITHMS_BINARY_HEAP_H
#define CPP_ALGORITHMS_BINARY_HEAP_H

#include <math.h>
#include <assert.h>
using namespace std;

template<typename E>
class BinaryHeap {
private:
    E *container = NULL;
    unsigned int capacity = 0;
    unsigned int size = 0;
    bool (*compare)(E a, E b);
    unsigned calculateLeftChildIndex(unsigned index) {
        return index * 2 + 1;
    }

    unsigned calculateRightChildIndex(unsigned index) {
        return this->calculateLeftChildIndex(index) + 1;
    }

    unsigned calculateParentIndex(unsigned index) {
//        int parentIndex = ceil((double)index / 2) - 1;
        int parentIndex = floor((double)(index - 1) / 2);
        if (parentIndex < 0) {
            return 0;
        }
        return parentIndex;
    }

    unsigned calculateLastParentIndex() {
        return this->calculateParentIndex(this->getSize() - 1);
    }

    void shiftUp(unsigned index) {
        unsigned currentIndex = index;
        unsigned parentIndexOfCurrentIndex = this->calculateParentIndex(currentIndex);
        while ((index > 0) && this->compare(this->container[index], this->container[parentIndexOfCurrentIndex])) {
            swap(this->container[index], this->container[parentIndexOfCurrentIndex]);
            currentIndex = parentIndexOfCurrentIndex;
            parentIndexOfCurrentIndex = this->calculateParentIndex(currentIndex);
        }
    }

    static bool defaultCompare(E a, E b) {
        return a > b;
    }

    void shiftDown(unsigned index = 0) {
        E e = this->container[index];
        while(this->getSize() > calculateLeftChildIndex(index)) {
            unsigned maxOrMinChildIndex = calculateLeftChildIndex(index);
            if (this->getSize() > calculateRightChildIndex(index)) {
                if (this->compare(this->container[calculateRightChildIndex(index)], this->container[calculateLeftChildIndex(index)])) {
                    maxOrMinChildIndex = calculateRightChildIndex(index);
                }
            }
            if (this->compare(e, this->container[maxOrMinChildIndex]) || e == this->container[maxOrMinChildIndex]) {
                break;
            }
            this->container[index] = this->container[maxOrMinChildIndex];
            index = maxOrMinChildIndex;
        }
        this->container[index] = e;
    }

    void setRoot(E element) {
        this->container[0] = element;
    }

public:

    BinaryHeap(unsigned capacity, bool (*compare)(E a, E b) = NULL) {
        assert(capacity > 0);
        this->container = new E[capacity];
        this->capacity = capacity;
        if (NULL == compare) {
            this->compare = this->defaultCompare;
        } else {
            this->compare = compare;
        }
    }

    // heapify
    BinaryHeap(E *arr, unsigned capacity, unsigned size, bool (*compare)(E a, E b) = NULL) {
        assert(capacity >= size);
        assert(capacity > 0);
        this->container = arr;
        this->capacity = capacity;
        this->size = size;
        if (NULL == compare) {
            this->compare = this->defaultCompare;
        } else {
            this->compare = compare;
        }
        for (int i = this->calculateLastParentIndex(); i >= 0; i --) {
            this->shiftDown(i);
        }
    }

    void insert(E element) {
        assert(!this->isFull());
        this->container[this->getSize()] = element;
        this->shiftUp(this->getSize());
        this->size ++;
    }

    E extract() {
        assert(!this->isEmpty());
        E root = this->getRoot();
        E tail = this->container[this->getSize() - 1];
        this->setRoot(tail);
        this->shiftDown();
        this->size --;
        return root;
    }

    E replace(E element) {
        E root = this->getRoot();
        this->setRoot(element);
        shiftDown();
        return root;
    }

    E getRoot() {
        return this->container[0];
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

    ~BinaryHeap() {
        delete(this->container);
    }

};

#endif //CPP_ALGORITHMS_BINARY_HEAP_H
