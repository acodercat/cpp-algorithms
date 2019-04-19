//
// Created by codercat on 19-4-18.
//

#include <iostream>
#include "binary_search_tree.h"

int main() {
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    binarySearchTree->add(1);
    binarySearchTree->add(2);
    binarySearchTree->add(5);
    binarySearchTree->add(6);
    binarySearchTree->add(4);
    cout<<binarySearchTree->contains(53)<<endl;
    binarySearchTree->preOrderTraverse();
    binarySearchTree->inOrderTraverse();
    binarySearchTree->postOrderTraverse();
}