//
// Created by codercat on 19-3-11.
//
#include <malloc.h>
#include <cstring>
#include <cassert>

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

template<typename E>
class Stack {

private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    E *container;

public:
    Stack(unsigned int capacity) {
        assert(capacity > 0);
        this->capacity = capacity;
        this->container = new E[capacity];
        memset(this->container, 0, capacity * sizeof(E));
    }

    void pop() {
        assert(!this->isEmpty());
        E top = this->container[this->getSize() - 1];
        this->size--;
    }

    E top() {
        assert(!this->isEmpty());
        E top = this->container[this->getSize() - 1];
        return top;
    }

    void push(E element) {
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
