//
// Created by codercat on 19-4-15.
//


#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList<int> linkedList;
    linkedList.insert(3);
    linkedList.insert(31);
    linkedList.insert(18);
    linkedList.remove(18);
    linkedList.insert(28);
    std::cout << linkedList.toString() << std::endl;
}