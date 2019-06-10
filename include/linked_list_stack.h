//
// Created by codercat on 19-3-14.
//

#ifndef ALGORITHM_LINKEDLISTSTACK_H
#define ALGORITHM_LINKEDLISTSTACK_H

#include <cstring>
#include <assert.h>

class LinkedListStack {

private:
    typedef struct Node {
        int element;
        Node *next;
    } Node;

    Node *top = NULL;
    unsigned int size = 0;
public:
    LinkedListStack() {
        this->top = NULL;
        this->size = 0;
    }

    void push(int element) {
        Node *newNode = new Node;
        newNode->element = element;
        newNode->next = this->top;
        this->top = newNode;
        this->size ++;

    }

    int pop() {
        assert(!this->isEmpty());
        Node *top = this->top;
        int element = this->top->element;
        this->top = top->next;
        delete top;
        this->size --;
        return element;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned int getSize() {
        return this->size;
    }
};


#endif //ALGORITHM_LINKEDLISTSTACK_H
