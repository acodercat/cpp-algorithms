//
// Created by codercat on 19-6-6.
//

#ifndef CPP_ALGORITHMS_RED_BLACK_TREE_H
#define CPP_ALGORITHMS_RED_BLACK_TREE_H
#include <assert.h>
#include <iostream>
using namespace std;

template<typename T>
class RedBlackTree {
private:
    typedef struct Node {
        T element;
        enum {
            RED,
            BLACK
        } color;
        Node *leftNode = NULL, *rightNode = NULL;
        Node(T element) {
            this->leftNode = NULL;
            this->rightNode = NULL;
            this->element = element;
            this->color = RED;
        }
    } Node;
    Node *rootNode = NULL;
    unsigned int size = 0;

    Node *leftRotate(Node *oldRootNode) {
        Node *newRootNode = oldRootNode->rightNode;
        Node *t2 = newRootNode->leftNode;
        newRootNode->leftNode = oldRootNode;
        oldRootNode->rightNode = t2;
        newRootNode->color = oldRootNode->color;
        oldRootNode->color = Node::RED;
        return newRootNode;
    }

    Node *rightRotate(Node *oldRootNode) {
        Node *newRootNode = oldRootNode->leftNode;
        Node *t3 = newRootNode->rightNode;
        newRootNode->rightNode = oldRootNode;
        oldRootNode->leftNode = t3;
        newRootNode->color = oldRootNode->color;
        oldRootNode->color = Node::RED;
        return newRootNode;
    }

    bool isRed(Node *node) {
        if (node != NULL && node->color == Node::RED) {
            return true;
        }
        return false;
    }

    void flipColors(Node *node) {
        node->color = Node::RED;
        node->rightNode->color = Node::BLACK;
        node->leftNode->color = Node::BLACK;
    }

    Node *insert(Node *rootNode, T element) {
        if (NULL == rootNode) {
            this->size ++;
            return new Node(element);
        } else {
            if (element < rootNode->element) {
                rootNode->leftNode = this->insert(rootNode->leftNode, element);
            } else if (element > rootNode->element) {
                rootNode->rightNode = this->insert(rootNode->rightNode, element);
            }
        }

        if (this->isRed(rootNode->rightNode) && !this->isRed(rootNode->leftNode)) {
            rootNode = this->leftRotate(rootNode);
        }

        if (this->isRed(rootNode->leftNode) && this->isRed(rootNode->leftNode->leftNode)) {
            rootNode = this->rightRotate(rootNode);
        }

        if (this->isRed(rootNode->leftNode) && this->isRed(rootNode->rightNode)) {
            this->flipColors(rootNode);
        }

        return rootNode;
    }

    bool contains(Node *node, T element) {
        if (NULL == node) {
            return false;
        }

        if (element == node->element) {
            return true;
        } else if (element < node->element) {
            return this->contains(node->leftNode, element);
        } else {
            return this->contains(node->rightNode, element);
        }
    }


public:
    RedBlackTree() {
        this->rootNode = NULL;
        this->size = 0;
    }

    Node *find(T element) {
        Node *currentNode = this->rootNode;
        while( currentNode != NULL ) {
            if ( element == currentNode->element ) {
                return currentNode;
            } else if ( element < (currentNode->element) ) {
                currentNode = currentNode->leftNode;
            } else {
                currentNode = currentNode->rightNode;
            }
        }
        return NULL;
    }

    unsigned int getSize() {
        return this->size;
    }

    void insert(T element) {
        this->rootNode = this->insert(this->rootNode, element);
        this->rootNode->color = Node::BLACK;
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contains(T element) {
        return this->contains(this->rootNode, element);
    }


};

#endif //CPP_ALGORITHMS_RED_BLACK_TREE_H
