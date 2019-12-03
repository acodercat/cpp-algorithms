//
// Created by codercat on 2019-05-28.
//

#include <iostream>
#include "avl_tree_map.h"

int main() {
    AVLTreeMap<string, string> avlTreeMap;
    avlTreeMap.insert("c", "3");
    avlTreeMap.insert("c", "1");
    avlTreeMap.insert("b", "2");
    avlTreeMap.insert("d", "4");
    avlTreeMap.insert("e", "5");
    avlTreeMap.insert("f", "6");
    cout<<"contains :"<<avlTreeMap.contrainsKey("a")<<endl;
    cout<<"find :"<<avlTreeMap.find("c").has_value()<<endl;
    cout<<"remove"<<endl;
    avlTreeMap.remove("a");
    cout<<"contains :"<<avlTreeMap.contrainsKey("a")<<endl;
    cout<<"isBalanced :"<<avlTreeMap.isBalanced()<<endl;
}