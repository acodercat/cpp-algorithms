//
// Created by codercat on 2019-05-28.
//

#include <iostream>
#include "avl_tree.h"

int main() {
    AVLTree<int> avlTree;
    avlTree.add(1);
    avlTree.add(2);
    avlTree.add(3);
    avlTree.add(4);
    cout<<"isBalanced :"<<avlTree.isBalanced()<<endl;


}