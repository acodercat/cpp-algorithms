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
        int v;
        Node *next;
    } Node;

    Node *top = NULL;
    unsigned int size = 0;
public:
    LinkedListStack() {
        this->top = NULL;
        this->size = 0;
    }

    void push(int v) {
        Node *newNode = new Node;
        newNode->v = v;
        newNode->next = this->top;
        this->top = newNode;
        this->size ++;

    }

    int pop() {
        assert(!this->isEmpty());
        Node *top = this->top;
        int v = this->top->v;
        this->top = top->next;
        delete top;
        this->size --;
        return v;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned int getSize() {
        return this->size;
    }
};


#endif //ALGORITHM_LINKEDLISTSTACK_H
