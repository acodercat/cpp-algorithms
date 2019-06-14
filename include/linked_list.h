//
// Created by codercat on 19-3-13.
//

#ifndef ALGORITHM_LINKEDLIST_H
#define ALGORITHM_LINKEDLIST_H

#include <cstring>
#include <assert.h>
#include <string>

using namespace std;
template<typename E>
class LinkedList {
private:
    typedef struct Node {
        E element;
        Node *next;
    } Node;
    Node *head = NULL;
    unsigned int size = 0;

public:
    LinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    void remove(E element) {
        Node *dummyHeadNode = new Node;
        dummyHeadNode->next = this->head;

        Node *prevNode = dummyHeadNode;
        while(prevNode->next != NULL) {
            if (prevNode->next->element == element) {
                Node *removeNode = prevNode->next;
                prevNode->next = prevNode->next->next;
                this->size --;
                delete removeNode;
            } else {
                prevNode = prevNode->next;
            }
        }

        this->head = dummyHeadNode->next;
    }

    void insert(E element) {
        Node *node = new Node();
        node->element = element;
        node->next = this->head;
        this->head = node;
        this->size ++;
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


#endif //ALGORITHM_LINKEDLIST_H
