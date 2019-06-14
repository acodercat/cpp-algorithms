//
// Created by codercat on 19-6-12.
//

#ifndef CPP_ALGORITHMS_LINKED_LIST_MAP_H
#define CPP_ALGORITHMS_LINKED_LIST_MAP_H

//#include <assert.h>
#include <iostream>
#include <optional>
using namespace std;

template<typename K, typename V>
class LinkedListMap {
private:
    typedef struct Node {
        K k;
        V v;
        Node *next;
    } Node;
    Node *head = NULL;
    unsigned size = 0;
public:
    LinkedListMap() {
        this->head = NULL;
        this->size = 0;
    }

    void insert(K k, V v) {
        Node *node = new Node;
        node->k = k;
        node->v = v;
        node->next = this->head;
        this->head = node;
        this->size ++;
    }

    optional<V> find(K k) {
        Node *curNode = this->head;
        while (curNode != NULL) {
            if (curNode->k == k) {
                return optional<V>(curNode->v);
            }
            curNode = curNode->next;
        }
        return optional<V>();
    }

    void remove(K k) {

        Node *dummyHeadNode = new Node;
        dummyHeadNode->next = this->head;

        Node *prevNode = dummyHeadNode;
        while(prevNode->next != NULL) {
            if (prevNode->next->k == k) {
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

    bool isEmpty() {
        return NULL == this->head;
    }

    unsigned getSize() {
        return this->size;
    }

};


#endif //CPP_ALGORITHMS_LINKED_LIST_MAP_H
