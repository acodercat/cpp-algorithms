//
// Created by codercat on 2019-05-28.
//

#ifndef CPP_ALGORITHMS_AVL_TREE_MAP_H
#define CPP_ALGORITHMS_AVL_TREE_MAP_H

#include <assert.h>
#include <optional>
#include <iostream>
using namespace std;

template<typename K, typename V>
class AVLTreeMap {
private:
    typedef struct Node {
        K k;
        V v;
        Node *leftNode = NULL, *rightNode = NULL;
        unsigned int height = 1;
        Node(K k, V v) {
            this->rightNode = this->leftNode = NULL;
            this->k = k;
            this->v = v;
            this->height = 1;
        }
    } Node;
    Node *rootNode = NULL;
    unsigned int size = 0;
    Node *insert(Node *rootNode, K k, V v) {
        if (NULL == rootNode) {
            this->size ++;
            return new Node(k, v);
        } else {
            if (k < rootNode->k) {
                rootNode->leftNode = this->insert(rootNode->leftNode, k, v);
            } else if (k > rootNode->k) {
                rootNode->rightNode = this->insert(rootNode->rightNode, k, v);
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

    Node *remove(Node *rootNode, K k) {
        if (NULL == rootNode) {
            return NULL;
        }
        Node *newRootNode = NULL;
        if (k < rootNode->k) {
            rootNode->leftNode = this->remove(rootNode->leftNode, k);
            newRootNode = rootNode;
        } else if (k > rootNode->k) {
            rootNode->rightNode = this->remove(rootNode->rightNode, k);
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
                Node *rightMinNode = this->minNode(rootNode->rightNode);
                newRootNode = new Node(rightMinNode->k, rightMinNode->v);
                newRootNode->leftNode = rootNode->leftNode;
                newRootNode->rightNode = this->remove(rootNode->rightNode, rightMinNode->k);
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

    bool contrainsKey(Node *node, K k) {
        if (NULL == node) {
            return false;
        }

        if (k == node->k) {
            return true;
        } else if (k < node->k) {
            return this->contrainsKey(node->leftNode, k);
        } else {
            return this->contrainsKey(node->rightNode, k);
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
    AVLTreeMap() {
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

    void remove(K k) {
        assert(!this->isEmpty());
        this->rootNode = this->remove(this->rootNode, k);
    }

    optional<V> find(K k) {
        Node *curNode = this->rootNode;
        while( curNode != NULL ) {
            if ( k == curNode->k ) {
                return optional<V>(curNode->v);
            } else if ( k < (curNode->k) ) {
                curNode = curNode->leftNode;
            } else {
                curNode = curNode->rightNode;
            }
        }
        return optional<V>();
    }


    void insert(K k, V v) {
        this->rootNode = this->insert(this->rootNode, k, v);
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contrainsKey(K k) {
        return this->contrainsKey(this->rootNode, k);
    }

};

#endif //CPP_ALGORITHMS_AVL_TREE_MAP_H
