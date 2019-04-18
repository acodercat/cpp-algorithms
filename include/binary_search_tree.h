//
// Created by codercat on 19-4-18.
//

#ifndef CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHMS_BINARY_SEARCH_TREE_H

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
            rootNode = new Node(v);
            this->size ++;
            return rootNode;
        } else {
            if (v < rootNode->v) {
                rootNode->leftNode = this->add(rootNode->leftNode, v);
            } else {
                rootNode->rightNode = this->add(rootNode->rightNode, v);
            }
        }
        return rootNode;
    }

    bool contains(Node *rootNode, int v) {
        if (NULL == rootNode) {
            return false;
        }

        if (v == rootNode->v) {
            return true;
        } else if (v < rootNode->v) {
            return this->contains(rootNode->leftNode, v);
        } else {
            return this->contains(rootNode->rightNode, v);
        }
    }

public:
    BinarySearchTree() {
        this->rootNode = NULL;
        this->size = 0;
    }

    unsigned int getSize() {
        return this->size;
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

    void test() {
        cout<<this->rootNode->leftNode->v<<endl;
    }
};


#endif //CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
