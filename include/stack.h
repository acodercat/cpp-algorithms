//
// Created by codercat on 19-3-11.
//
#include <malloc.h>
#include <cstring>
#include <assert.h>

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

template<typename T>
class Stack {

private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    T *container;

public:
    Stack(unsigned int capacity) {
        assert(capacity > 0);
        this->capacity = capacity;
        this->container = (T *)malloc(capacity * sizeof(T));
        memset(this->container, 0, capacity * sizeof(T));
    }

    void pop() {
        assert(!this->isEmpty());
        T top = this->container[this->getSize() - 1];
        this->size--;
    }

    T top() {
        assert(!this->isEmpty());
        T top = this->container[this->getSize() - 1];
        return top;
    }

    void push(T element) {
        assert(!this->isFull());
        this->container[this->getSize()] = element;
        this->size++;
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

    ~Stack() {
        free(this->container);
    }
};


#endif //ALGORITHM_STACK_H
