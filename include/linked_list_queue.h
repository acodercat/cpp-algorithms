//
// Created by codercat on 19-3-14.
//

#ifndef ALGORITHM_LINKEDLISTQUEUE_H
#define ALGORITHM_LINKEDLISTQUEUE_H

#include <cstring>
#include <cassert>
using namespace std;

template<typename E>
class LinkedListQueue {
private:
    typedef struct Node {
        E element;
        Node *next = NULL;
    } Node;

    Node *head = NULL;
    Node *tail = NULL;
    unsigned int size = 0;

public:
    LinkedListQueue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue (E element) {
        Node *newNode = new Node;
        newNode->element = element;
        if (this->isEmpty()) {
            this->head = newNode;
        } else {
            this->tail->next = newNode;
        }
        this->tail = newNode;
        this->size ++;
    }

    E dequeue () {
        assert(!this->isEmpty());
        Node *head = this->head;
        E element = head->element;
        if (head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else {
            this->head = head->next;
        }
        this->size --;
        delete head;
        return element;

    }

    int getSize() {
        return this->size;
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    E getFront() {
        return this->head->element;
    }

    string toString() {
        Node *currentNode = this->head;
        string str = "head";
        while(NULL != currentNode) {
            str = str + "->" + to_string(currentNode->element);
            currentNode = currentNode->next;
        }

        return str;
    }
};


#endif //ALGORITHM_LINKEDLISTQUEUE_H
