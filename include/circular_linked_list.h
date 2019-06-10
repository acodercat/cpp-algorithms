//
// Created by codercat on 19-4-18.
//

#ifndef CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H
#define CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H

#include <cstring>
#include <assert.h>

using namespace std;

class CircularLinkedList {
private:
    typedef struct Node {
        int element;
        Node *next = NULL, *prev = NULL;
    } Node;

    Node *dummyHead = NULL;
    unsigned int size = 0;
public:
    CircularLinkedList() {
        this->size = 0;
        this->dummyHead = new Node;
    }

    void insert(int element) {
        Node *newNode = new Node;
        newNode->element = element;
        Node **head = &(this->dummyHead->next);
        Node **tail = &(this->dummyHead->prev);
        if (NULL == *head) {
            newNode->prev = this->dummyHead;
            newNode->next = this->dummyHead;
            *head = newNode;
        } else {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            newNode->next = this->dummyHead;
        }
        *tail = newNode;
        this->size ++;
    }

    unsigned int getSize() {
        return this->size;
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    string toString() {
        Node *currentNode = this->dummyHead->next;
        string str = "head";
        while(this->dummyHead != currentNode) {
            str = str + "->" + to_string(currentNode->element);
            currentNode = currentNode->next;
        }
        return str;
    }
};


#endif //CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H
