//
// Created by codercat on 19-4-18.
//

#ifndef CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHMS_BINARY_SEARCH_TREE_H

#include "stack.h"
#include <assert.h>
#include "circular_queue.h"
using namespace std;
/*
 *
 *
 *
 *
 * */
template<typename T>
class BinarySearchTree {
private:
    typedef struct Node {
        T element;
        Node *leftNode = NULL, *rightNode = NULL;
        Node(T element) {
            this->leftNode = NULL;
            this->rightNode = NULL;
            this->element = element;
        }
    } Node;
    Node *rootNode = NULL;
    unsigned int size = 0;
    Node * insert(Node *rootNode, T element) {
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

    void inOrderTraverse(Node *node) {
        if (NULL == node) {
            return;
        }
        this->inOrderTraverse(node->leftNode);
        cout<<node->element<<" ";
        this->inOrderTraverse(node->rightNode);
    }


    void postOrderTraverse(Node *node) {
        if (NULL == node) {
            return;
        }
        this->postOrderTraverse(node->leftNode);
        this->postOrderTraverse(node->rightNode);
        cout<<node->element<<" ";
    }

    Node *removeMin(Node *node) {
        if (NULL == node) {
            return NULL;
        }

        if (NULL == node->leftNode) {
            Node *rightNode = node->rightNode;
            this->size --;
            node = NULL;
            delete node;
            return rightNode;
        }

        node->leftNode = this->removeMin(node->leftNode);
        return node;
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
        Stack<Node *> nodeStack(this->getSize());
        nodeStack.push(this->rootNode);
        cout<<"preOrderTraverse ";
        while( !nodeStack.isEmpty() ) {
            Node *currentNode = nodeStack.top();
            cout<<currentNode->element<<" ";
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

    T min() {
        assert(!this->isEmpty());
        Node *currentNode = this->rootNode;
        while(currentNode->leftNode != NULL) {
            currentNode = currentNode->leftNode;
        }
        return currentNode->element;
    }


    Node *minNode(Node *node) {
        assert(!this->isEmpty());
        Node *currentNode = node;
        while(currentNode->leftNode != NULL) {
            currentNode = currentNode->leftNode;
        }
        return currentNode;
    }

    T removeMin() {
        assert(!this->isEmpty());
        T min = this->min();
        this->rootNode = this->removeMin(this->rootNode);
        return min;
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


    Node *remove(Node *node, T element) {
        if( node == NULL ) {
            return NULL;
        }

        if ( element < node->element ) {
            node->leftNode = this->remove(node->leftNode, element);
            return node;
        } else if (element > node->element) {
            node->rightNode = this->remove(node->rightNode, element);
            return node;
        } else {
            if ( NULL == node->leftNode ) {
                Node *rightNode = node->rightNode;
                this->size --;
                node = NULL;
                delete node;
                return rightNode;
            } else if ( NULL == node->rightNode ) {
                Node *leftNode = node->leftNode;
                this->size --;
                node = NULL;
                delete node;
                return leftNode;
            } else {
                T rightMinElement = this->minNode(rootNode->rightNode)->element;
                Node *newRootNode = new Node(rightMinElement);
                newRootNode->leftNode = rootNode->leftNode;
                newRootNode->rightNode = rootNode->rightNode;
                this->removeMin(rootNode->rightNode);
                rootNode = NULL;
                delete(rootNode);
                return newRootNode;
            }

        }
    }

    void remove(T element) {
        assert(!this->isEmpty());
        this->rootNode = this->remove(this->rootNode, element);
        return;
    }

    /*
     * 使用stack来实现删除最大节点,因为stack先进后出的特性可以记录最大节点的父节点
     */
    T removeMax() {
        assert(!this->isEmpty());
        T max = this->max();
        Stack<Node *> nodeStack(this->getSize());
        nodeStack.push(this->rootNode);
        while( nodeStack.top()->rightNode != NULL ) {
            nodeStack.push(nodeStack.top()->rightNode);
        }

        Node *maxNode = nodeStack.top();
        nodeStack.pop();
        if ( maxNode == this->rootNode ) {
            this->rootNode = maxNode->leftNode;
        } else {
            Node *parentNode = nodeStack.top();
            parentNode->rightNode = maxNode->leftNode;
        }
        this->size --;
        maxNode = NULL;
        delete maxNode;
        return max;
    }

    T max() {
        assert(!this->isEmpty());
        Node *currentNode = this->rootNode;
        while(currentNode->rightNode != NULL) {
            currentNode = currentNode->rightNode;
        }
        return currentNode->element;
    }

    void inOrderTraverse() {
        assert(!this->isEmpty());
        cout<<"inOrderTraverse ";
        this->inOrderTraverse(this->rootNode);
        cout<<endl;
    }

    void postOrderTraverse() {
        assert(!this->isEmpty());
        cout<<"postOrderTraverse ";
        this->postOrderTraverse(this->rootNode);
        cout<<endl;
    }

    /*
     * 使用queue实现层序遍历(广度优先遍历),queue具有先进先出的特性,把每一层的节点放入queue,然后逐一处理.
     */
    void levelOrderTraverse() {
        assert(!this->isEmpty());
        cout<<"levelOrderTraverse";
        CircularQueue<Node *> nodeCircularQueue(this->getSize());
        nodeCircularQueue.enqueue(this->rootNode);
        while( !nodeCircularQueue.isEmpty() ) {
            Node *currentNode = nodeCircularQueue.dequeue();
            cout<<currentNode->element<<" ";
            if (currentNode->leftNode != NULL) {
                nodeCircularQueue.enqueue(currentNode->leftNode);
            }

            if (currentNode->rightNode != NULL) {
                nodeCircularQueue.enqueue(currentNode->rightNode);
            }
        }
        cout<<endl;
    }

    void insert(T element) {
        this->rootNode = this->insert(this->rootNode, element);
    }

    bool isEmpty() {
        return 0 == this->getSize();
    }

    bool contains(T element) {
        return this->contains(this->rootNode, element);
    }

};


#endif //CPP_ALGORITHMS_BINARY_SEARCH_TREE_H
