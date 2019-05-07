//
// Created by codercat on 19-5-7.
//

#ifndef CPP_ALGORITHMS_SEGMENT_TREE_H
#define CPP_ALGORITHMS_SEGMENT_TREE_H
#include <cstring>
#include <iostream>
using namespace std;

template<typename T>
class SegmentTree {
private:
    typedef struct Node {
        T v;
        Node *leftNode = NULL, *rightNode = NULL;
    } Node;

    Node *rootNode = NULL;
    Node *buildSegmentTree(T arr[], unsigned int leftIndex, unsigned int rightIndex) {
        Node *node = new Node();
        if ( leftIndex == rightIndex ) {
            node->v = arr[leftIndex];
            return node;
        }
        unsigned int minIndex = (rightIndex - leftIndex) / 2 + leftIndex;
        node->leftNode = this->buildSegmentTree(arr, leftIndex, minIndex);
        node->rightNode = this->buildSegmentTree(arr, minIndex + 1, rightIndex);
        node->v = node->leftNode->v + node->rightNode->v;
        return node;
    }

public:
    SegmentTree(T arr[], unsigned int lenght) {
        this->rootNode = this->buildSegmentTree(arr, 0, lenght - 1);
        cout<<this->rootNode->v<<endl;

    }



};


#endif //CPP_ALGORITHMS_SEGMENT_TREE_H
