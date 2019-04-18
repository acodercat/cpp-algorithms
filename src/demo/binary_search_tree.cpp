//
// Created by codercat on 19-4-18.
//

#include <iostream>
#include "binary_search_tree.h"

int main() {
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    binarySearchTree->add(56);
    binarySearchTree->add(57);
    binarySearchTree->add(59);
    binarySearchTree->add(53);
    cout<<binarySearchTree->contains(531)<<endl;
    binarySearchTree->test();
}