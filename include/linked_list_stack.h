//
// Created by codercat on 19-3-14.
//

#ifndef ALGORITHM_LINKEDLISTSTACK_H
#define ALGORITHM_LINKEDLISTSTACK_H

#include <cstring>
#include <cassert>

template<typename E>
class LinkedListStack {

private:
    typedef struct Node {
        E element;
        Node *next;
    } Node;

    Node *topNode = NULL;
    unsigned int size = 0;
public:
    LinkedListStack() {
        this->topNode = NULL;
        this->size = 0;
    }

    void push(E element) {
        Node *newNode = new Node;
        newNode->element = element;
        newNode->next = this->topNode;
        this->topNode = newNode;
        this->size ++;

    }

    void pop() {
        assert(!this->isEmpty());
        Node *topNode = this->topNode;
        this->topNode = topNode->next;
        delete topNode;
        this->size --;
    }

    E top() {
        assert(!this->isEmpty());
        return this->topNode->element;
    }


    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned int getSize() {
        return this->size;
    }
};


#endif //ALGORITHM_LINKEDLISTSTACK_H
