//
// Created by codercat on 2019-05-28.
//

#ifndef CPP_ALGORITHMS_AVL_TREE_H
#define CPP_ALGORITHMS_AVL_TREE_H
#include <assert.h>
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
    Node *insert(Node *rootNode, T v) {
        if (NULL == rootNode) {
            this->size ++;
            return new Node(v);
        } else {
            if (v < rootNode->v) {
                rootNode->leftNode = this->insert(rootNode->leftNode, v);
            } else if (v > rootNode->v) {
                rootNode->rightNode = this->insert(rootNode->rightNode, v);
            }
        }
        rootNode->height = max(this->getNodeHeight(rootNode->leftNode), this->getNodeHeight(rootNode->rightNode)) + 1;
        return this->maintainBalance(rootNode);
    }

    Node *maintainBalance(Node *node) {
        int balanceFctor = this->getNodeBalanceFctor(node);
        // 如果左子树的高度大于右子树并且新节点是插入在该节点左子树的左子树上
        if (balanceFctor > 1 && (this->getNodeBalanceFctor(node->leftNode) >= 0)) { // LL
            cout<<"left left"<<endl;
            return this->rightRotate(node);
        } else if (balanceFctor > 1 && (this->getNodeBalanceFctor(node->leftNode) < 0)) { // LR
            cout<<"left right"<<endl;
            node->leftNode = this->leftRotate(node->leftNode);
            return this->rightRotate(node);
        } else if (balanceFctor < -1 && (this->getNodeBalanceFctor(node->rightNode) >= 0)) { // RL
            cout<<"right left"<<endl;
            node->rightNode = this->rightRotate(node->rightNode);
            return this->leftRotate(node);
        } else if (balanceFctor < -1 && (this->getNodeBalanceFctor(node->rightNode) < 0)) { // RR
            cout<<"right right"<<endl;
            return this->leftRotate(node);
        }
        return node;
    }

    Node *remove(Node *rootNode, T v) {
        if (NULL == rootNode) {
            return NULL;
        }
        Node *newRootNode = NULL;
        if (v < rootNode->v) {
            rootNode->leftNode = this->remove(rootNode->leftNode, v);
            newRootNode = rootNode;
        } else if (v > rootNode->v) {
            rootNode->rightNode = this->remove(rootNode->rightNode, v);
            newRootNode = rootNode;
        } else {
            if (NULL == rootNode->leftNode) {
                Node *rightNode = rootNode->rightNode;
                this->size --;
                rootNode = NULL;
                delete(rootNode);
                newRootNode == rightNode;
            } else if (NULL == rootNode->rightNode) {
                Node *leftNode = rootNode->leftNode;
                this->size --;
                rootNode = NULL;
                delete(rootNode);
                newRootNode == leftNode;
            } else {
                T rightMinV = this->minNode(rootNode->rightNode)->v;
                newRootNode = new Node(rightMinV);
                newRootNode->leftNode = rootNode->leftNode;
                newRootNode->rightNode = this->remove(rootNode->rightNode, rightMinV);
                rootNode = NULL;
                delete(rootNode);
            }
        }

        if (NULL == newRootNode) {
            return NULL;
        }

        newRootNode->height = max(this->getNodeHeight(newRootNode->leftNode), this->getNodeHeight(newRootNode->rightNode)) + 1;
        return this->maintainBalance(newRootNode);

    }

    Node *minNode(Node *node) {
        assert(!this->isEmpty());
        Node *currentNode = node;
        while(currentNode->leftNode != NULL) {
            currentNode = currentNode->leftNode;
        }
        return currentNode;
    }

    Node *rightRotate(Node *oldRootNode) {
        Node *newRootNode = oldRootNode->leftNode;
        Node *t3 = newRootNode->rightNode;
        newRootNode->rightNode = oldRootNode;
        oldRootNode->leftNode = t3;
        // 先更新旧根节点的高度后再更新新根节点的高度
        oldRootNode->height = max(this->getNodeHeight(oldRootNode->leftNode), this->getNodeHeight(oldRootNode->rightNode)) + 1;
        newRootNode->height = max(this->getNodeHeight(newRootNode->leftNode), this->getNodeHeight(newRootNode->rightNode)) + 1;
        return newRootNode;
    }

    Node *leftRotate(Node *oldRootNode) {
        Node *newRootNode = oldRootNode->rightNode;
        Node *t2 = newRootNode->leftNode;
        newRootNode->leftNode = oldRootNode;
        oldRootNode->rightNode = t2;
        // 先更新旧根节点的高度后再更新新根节点的高度
        oldRootNode->height = max(this->getNodeHeight(oldRootNode->leftNode), this->getNodeHeight(oldRootNode->rightNode)) + 1;
        newRootNode->height = max(this->getNodeHeight(newRootNode->leftNode), this->getNodeHeight(newRootNode->rightNode)) + 1;
        return newRootNode;
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

    int getNodeBalanceFctor(Node *node) {
        if (NULL == node) {
            return 0;
        }
        return this->getNodeHeight(node->leftNode) - this->getNodeHeight(node->rightNode);
    }

    bool isBalanced(Node *node) {
        if (NULL == node) {
            return true;
        }
        if (abs(this->getNodeBalanceFctor(node)) > 1) {
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

    void remove(T v) {
        assert(!this->isEmpty());
        this->rootNode = this->remove(this->rootNode, v);
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


    void insert(T v) {
        this->rootNode = this->insert(this->rootNode, v);
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contains(T v) {
        return this->contains(this->rootNode, v);
    }

};

#endif //CPP_ALGORITHMS_AVL_TREE_H
