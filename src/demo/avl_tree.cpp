//
// Created by codercat on 2019-05-28.
//

#include <iostream>
#include "avl_tree.h"

int main() {
    AVLTree<int> avlTree;
    avlTree.insert(50);
    avlTree.insert(1);
    avlTree.insert(80);
    avlTree.insert(70);
    avlTree.insert(75);
    avlTree.insert(21);
    avlTree.insert(43);
    avlTree.insert(81);
    avlTree.insert(71);
    avlTree.insert(75);
    avlTree.insert(48);
    avlTree.insert(40);
    avlTree.insert(41);
    avlTree.remove(80);
    avlTree.remove(41);
    avlTree.remove(1);
    avlTree.remove(21);
    cout<<"contains :"<<avlTree.contains(41)<<endl;
    cout<<"isBalanced :"<<avlTree.isBalanced()<<endl;
}