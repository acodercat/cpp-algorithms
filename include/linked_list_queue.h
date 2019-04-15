//
// Created by codercat on 19-3-14.
//

#ifndef ALGORITHM_LINKEDLISTQUEUE_H
#define ALGORITHM_LINKEDLISTQUEUE_H

#include <cstring>
#include <assert.h>
#include <string>
using namespace std;

class LinkedListQueue {

private:
    typedef struct Node {
        int v;
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

    void enqueue (int v) {
        Node *node = new Node;
        node->v = v;
        if (NULL == this->head) {
            this->head = node;
            this->tail = this->head;
        } else {
            this->tail->next = node;
            this->tail = node;
        }
        this->size ++;
    }

    int dequeue () {
        assert(!this->isEmpty());
        Node *head = this->head;
        int v = head->v;
        if (head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else {
            this->head = head->next;
        }
        this->size --;
        delete head;
        return v;

    }

    int getSize() {
        return this->size;
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    string toString() {
        Node *currentNode = this->head;
        string str = "head";
        while(NULL != currentNode) {
            str = str + "->" + to_string(currentNode->v);
            currentNode = currentNode->next;
        }

        return str;
    }
};


#endif //ALGORITHM_LINKEDLISTQUEUE_H
