//
// Created by codercat on 19-4-18.
//

#include <iostream>
#include "binary_search_tree.h"

int main() {
    BinarySearchTree<int> binarySearchTree;
    binarySearchTree.insert(5);
    binarySearchTree.insert(6);
    binarySearchTree.insert(16);
    binarySearchTree.insert(1);
    binarySearchTree.insert(2);
    binarySearchTree.insert(4);
    binarySearchTree.insert(64);
    binarySearchTree.insert(88);
    binarySearchTree.insert(99);
    binarySearchTree.insert(100);
    binarySearchTree.insert(96);
    binarySearchTree.insert(98);
    cout<<binarySearchTree.contains(53)<<endl;
    binarySearchTree.preOrderTraverse();
    binarySearchTree.inOrderTraverse();
    binarySearchTree.postOrderTraverse();
    binarySearchTree.levelOrderTraverse();
    cout<<"min:"<<binarySearchTree.min()<<endl;
    cout<<"max:"<<binarySearchTree.max()<<endl;
    cout<<"remove min :"<<binarySearchTree.removeMin()<<endl;
    cout<<"remove max :"<<binarySearchTree.removeMax()<<endl;
    cout<<"remove 99 "<<endl;
    binarySearchTree.remove(99);
    binarySearchTree.levelOrderTraverse();
    cout<<"find :"<<binarySearchTree.find(2)->element<<endl;

}