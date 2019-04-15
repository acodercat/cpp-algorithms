//
// Created by codercat on 19-3-11.
//
#include <malloc.h>
#include <cstring>
#include <assert.h>

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H


class Stack {

private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    int *arr;

public:
    Stack(unsigned int capacity) {
        assert(capacity > 0);
        this->capacity = capacity;
        this->arr = (int *)malloc(capacity * sizeof(int));
        memset(this->arr, 0, capacity * sizeof(int));
    }

    int pop() {
        assert(!this->isEmpty());
        int top = this->arr[this->getSize() - 1];
        this->size--;
        return top;

    }

    void push(int v) {
        assert(!this->isFull());
        this->arr[this->getSize()] = v;
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
        free(this->arr);
    }
};


#endif //ALGORITHM_STACK_H
