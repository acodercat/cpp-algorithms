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
        T element;
        Node *leftNode = NULL, *rightNode = NULL;
    } Node;

    Node *rootNode = NULL;
    unsigned int size = 0;
    Node *buildSegmentTree(T arr[], unsigned int leftIndex, unsigned int rightIndex) {
        Node *node = new Node();
        if ( leftIndex == rightIndex ) {
            node->element = arr[leftIndex];
            return node;
        }
        unsigned int midIndex = (rightIndex - leftIndex) / 2 + leftIndex;
        node->leftNode = this->buildSegmentTree(arr, leftIndex, midIndex);
        node->rightNode = this->buildSegmentTree(arr, midIndex + 1, rightIndex);
        node->element = node->leftNode->element + node->rightNode->element;
        return node;
    }

    T query(Node *node, unsigned int leftIndex, unsigned int rightIndex, unsigned int qLeftIndex, unsigned int qRightIndex) {

        if ( leftIndex == qLeftIndex && rightIndex == qRightIndex ) {
            return node->element;
        }
        unsigned int midIndex = (rightIndex - leftIndex) / 2 + leftIndex;
//        unsigned int qMidIndex = (qRightIndex - qLeftIndex) / 2 + qLeftIndex;

        if ( qRightIndex <= midIndex) {
            return this->query(node->leftNode, leftIndex, midIndex, qLeftIndex, qRightIndex);
        } else if ( qLeftIndex > midIndex) {
            return this->query(node->rightNode, midIndex + 1, rightIndex, qLeftIndex, qRightIndex);
        }
        // 这一步不好理解,当要查找的区间分别在当前节点的左右2个子区间内的时候,由于索引是连续的,那么一定是以当前节点的midIndex作为分隔.因为它们们是连续相邻的!!!!!
        T v1 = this->query(node->leftNode, leftIndex, midIndex, qLeftIndex, midIndex);
        T v2 = this->query(node->rightNode, midIndex + 1, rightIndex, midIndex + 1, qRightIndex);

//        T v1 = this->query(node->leftNode, leftIndex, midIndex, qLeftIndex, qMidIndex);
//        T v2 = this->query(node->rightNode, midIndex + 1, rightIndex, qMidIndex + 1, qRightIndex);
        return v1 + v2;
    }

    void update(Node *node, unsigned int leftIndex, unsigned int rightIndex, unsigned int updateIndex, T element) {
        if ( leftIndex == rightIndex ) {
            node->element = element;
            return;
        }
        unsigned int midIndex = (rightIndex - leftIndex) / 2 + leftIndex;
        if (updateIndex <= midIndex) {
            this->update(node->leftNode, leftIndex, midIndex, updateIndex, element);
        } else {
            this->update(node->rightNode, midIndex + 1, rightIndex, updateIndex, element);
        }
         // 后续遍历
        node->element = node->leftNode->element + node->rightNode->element;
        return;
    }

public:
    SegmentTree(T arr[], unsigned int size) {
        this->size = size;
        this->rootNode = this->buildSegmentTree(arr, 0, size - 1);
    }


    T query( unsigned int qLeftIndex, unsigned int qRightIndex) {
        return this->query(this->rootNode, 0, this->getSize() - 1, qLeftIndex, qRightIndex);
    }

    void update(unsigned int updateIndex, T element) {
        this->update(this->rootNode, 0, this->getSize() - 1, updateIndex, element);
    }

    unsigned int getSize() {
        return this->size;
    }
};


#endif //CPP_ALGORITHMS_SEGMENT_TREE_H
