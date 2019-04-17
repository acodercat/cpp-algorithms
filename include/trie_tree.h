//
// Created by codercat on 19-4-16.
//

#ifndef CPP_ALGORITHMS_TRIE_TREE_H
#define CPP_ALGORITHMS_TRIE_TREE_H

#include <cstring>
#include <assert.h>
using namespace std;

class TrieTree {

private:
    typedef struct Node {
        int v;
        bool isKey;
        Node *next = NULL;
        Node *childNodes[];

    } Node;

    Node *rootNode = NULL;
    int size = 0;

public:
    TrieTree() {
        this->rootNode = NULL;
    }

    void insert(string key, string value) {
        Node *currentNode
    }

};


#endif //CPP_ALGORITHMS_TRIE_TREE_H
