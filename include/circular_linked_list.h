//
// Created by codercat on 19-4-18.
//

#ifndef CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H
#define CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H

#include <cstring>
#include <assert.h>
#include <string>


class CircularLinkedList {
private:
    typedef struct Node {
        int v;
        Node *next;
    } Node;
    Node *head = NULL;
    unsigned int size = 0;

};


#endif //CPP_ALGORITHMS_CIRCULAR_LINKED_LIST_H
