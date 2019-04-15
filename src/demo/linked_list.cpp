//
// Created by codercat on 19-4-15.
//


#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList *linkedList = new LinkedList();
    linkedList->insert(3);
    linkedList->insert(31);
    linkedList->insert(18);
    std::cout << linkedList->toString() << std::endl;
}