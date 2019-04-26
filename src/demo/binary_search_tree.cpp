//
// Created by codercat on 19-4-18.
//

#include <iostream>
#include "binary_search_tree.h"

int main() {
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    binarySearchTree->add(5);
    binarySearchTree->add(6);
    binarySearchTree->add(16);
    binarySearchTree->add(1);
    binarySearchTree->add(2);
    binarySearchTree->add(4);
    binarySearchTree->add(64);
    binarySearchTree->add(88);
    binarySearchTree->add(99);
    binarySearchTree->add(100);
    binarySearchTree->add(96);
    binarySearchTree->add(98);
    cout<<binarySearchTree->contains(53)<<endl;
    binarySearchTree->preOrderTraverse();
    binarySearchTree->inOrderTraverse();
    binarySearchTree->postOrderTraverse();
    binarySearchTree->levelOrderTraverse();
    cout<<"min:"<<binarySearchTree->min()<<endl;
    cout<<"max:"<<binarySearchTree->max()<<endl;
//    cout<<"remove min :"<<binarySearchTree->removeMin()<<endl;
//    cout<<"remove max :"<<binarySearchTree->removeMax()<<endl;
    cout<<"remove 99 "<<endl;
    binarySearchTree->remove(99);
    binarySearchTree->levelOrderTraverse();
    cout<<"find :"<<binarySearchTree->find(2)->v<<endl;

}