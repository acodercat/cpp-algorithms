//
// Created by codercat on 2019-05-28.
//

#ifndef CPP_ALGORITHMS_AVL_TREE_H
#define CPP_ALGORITHMS_AVL_TREE_H
using namespace std;

/*
 *
 *
 *
 *
 * */
template<typename T>
class AVLTree {
private:
    typedef struct Node {
        T v;
        Node *leftNode = NULL, *rightNode = NULL;
        unsigned int height = 1;
        Node(T v) {
            this->leftNode = NULL;
            this->rightNode = NULL;
            this->v = v;
            this->height = 1;
        }
    } Node;
    Node *rootNode = NULL;
    unsigned int size = 0;
    Node * add(Node *rootNode, T v) {
        if (NULL == rootNode) {
            this->size ++;
            return new Node(v);
        } else {
            if (v < rootNode->v) {
                rootNode->leftNode = this->add(rootNode->leftNode, v);
            } else if (v > rootNode->v) {
                rootNode->rightNode = this->add(rootNode->rightNode, v);
            }
        }
//        rootNode->height = max(this->getNodeHeight(rootNode->leftNode), this->getNodeHeight(rootNode->rightNode)) + 1;
        rootNode->height++;
        unsigned int balanceFctor = this->getNodeBalanceFctor(rootNode);
        cout<<balanceFctor<<endl;
        if (balanceFctor > 1) {
            cout<<"error"<<endl;
        }
        return rootNode;
    }

    bool contains(Node *node, T v) {
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

    unsigned int getNodeBalanceFctor(Node *node) {
        if (NULL == node) {
            return 0;
        }
        return abs(this->getNodeHeight(node->leftNode) - this->getNodeHeight(node->rightNode));
    }

    bool isBalanced(Node *node) {
        if (NULL == node) {
            return true;
        }
        if (this->getNodeBalanceFctor(node) > 1) {
            return false;
        }
        return this->isBalanced(node->leftNode) && this->isBalanced(node->rightNode);
    }


public:
    AVLTree() {
        this->rootNode = NULL;
        this->size = 0;
    }

    bool isBalanced() {
        return this->isBalanced(this->rootNode);
    }

    unsigned int getSize() {
        return this->size;
    }

    int getNodeHeight(Node *node) {
        if (NULL == node) {
            return 0;
        }
        return node->height;
    }



    Node *find(T v) {
        Node *currentNode = this->rootNode;
        while( currentNode != NULL ) {
            if ( v == currentNode->v ) {
                return currentNode;
            } else if ( v < (currentNode->v) ) {
                currentNode = currentNode->leftNode;
            } else {
                currentNode = currentNode->rightNode;
            }
        }
        return NULL;

    }



    void add(T v) {
        this->rootNode = this->add(this->rootNode, v);
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contains(T v) {
        return this->contains(this->rootNode, v);
    }

};

#endif //CPP_ALGORITHMS_AVL_TREE_H
