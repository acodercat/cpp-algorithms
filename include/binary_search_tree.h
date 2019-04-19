//
// Created by codercat on 19-4-18.
//

#ifndef CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHMS_BINARY_SEARCH_TREE_H

#include <stack>
using namespace std;

class BinarySearchTree {
private:
    typedef struct Node {
        int v;
        Node *leftNode = NULL, *rightNode = NULL;
        Node(int v) {
            this->leftNode = NULL;
            this->rightNode = NULL;
            this->v = v;
        }
    } Node;
    Node *rootNode = NULL;
    unsigned int size = 0;
    Node * add(Node *rootNode, int v) {
        if (NULL == rootNode) {
            this->size ++;
            return new Node(v);
        } else {
            if (v < rootNode->v) {
                rootNode->leftNode = this->add(rootNode->leftNode, v);
            } else {
                rootNode->rightNode = this->add(rootNode->rightNode, v);
            }
        }
        return rootNode;
    }

    bool contains(Node *node, int v) {
        if (NULL == node) {
            return false;
        }

        if (v == node->v) {
            return true;
        } else if (v < node->v) {
            return this->contains(node->leftNode, v);
        } else {
            return this->contains(node->rightNode, v);
        }
    }

    void inOrderTraverse(Node *node) {
        if (NULL == node) {
            return;
        }
        this->inOrderTraverse(node->leftNode);
        cout<<node->v<<" ";
        this->inOrderTraverse(node->rightNode);
    }

    void postOrderTraverse(Node *node) {
        if (NULL == node) {
            return;
        }
        this->postOrderTraverse(node->leftNode);
        this->postOrderTraverse(node->rightNode);
        cout<<node->v<<" ";
    }

public:
    BinarySearchTree() {
        this->rootNode = NULL;
        this->size = 0;
    }

    unsigned int getSize() {
        return this->size;
    }

    void preOrderTraverse() {
        stack<Node *> nodeStack;
        nodeStack.push(this->rootNode);
        while( !nodeStack.empty()) {
            Node *currentNode = nodeStack.top();
            cout<<currentNode->v<<" ";
            nodeStack.pop();

            if (currentNode->rightNode != NULL) {
                nodeStack.push(currentNode->rightNode);
            }

            if (currentNode->leftNode != NULL) {
                nodeStack.push(currentNode->leftNode);
            }
        }
        cout<<endl;
    }

    void inOrderTraverse() {
        this->inOrderTraverse(this->rootNode);
        cout<<endl;
    }

    void postOrderTraverse() {
        this->postOrderTraverse(this->rootNode);
        cout<<endl;
    }

    void add(int v) {
        this->rootNode = this->add(this->rootNode, v);
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contains(int v) {
        return this->contains(this->rootNode, v);
    }

};


#endif //CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
