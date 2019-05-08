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

    public:
        int v;
        char c;
        bool isKey;
        short int childNodeNum = 0;
        Node(char c) {
            this->c = c;
        }

        Node() {

        }

        Node *findChildNode(char c) {
            for (int i = 0; i < this->childNodeNum; i ++) {
                if (this->childNodes[i]->c == c) {
                    return this->childNodes[i];
                }
            }
            return NULL;
        }

        void addChildNode(Node *node) {
            this->childNodes[this->childNodeNum] = node;
            this->childNodeNum ++;
        }
    private:
        // flexible array
        Node *childNodes[1];

    } Node;

    Node *rootNode = NULL;
    int size = 0;

public:
    TrieTree() {
        this->rootNode = new Node;
    }

    void insert(string key, int v) {
        Node *currentNode = this->rootNode;
        for(int i = 0; i <= key.length(); i ++) {
            if (Node *node = currentNode->findChildNode(key[i])) {
                currentNode = node;
                continue;
            }
            Node *newNode = new Node(key[i]);
            currentNode->addChildNode(newNode);
            currentNode = newNode;
        }

        if (!currentNode->isKey) {
            this->size ++;
            currentNode->isKey = true;
        }
        currentNode->v = v;
    }

    Node *find(string key) {
        Node *currentNode = this->rootNode;
        for(int i = 0; i <= key.length(); i ++) {
            if (Node *node = currentNode->findChildNode(key[i])) {
                currentNode = node;
                continue;
            }
            return NULL;
        }
        if (currentNode->isKey) {
            return currentNode;
        }
        return NULL;
    }

};


#endif //CPP_ALGORITHMS_TRIE_TREE_H
