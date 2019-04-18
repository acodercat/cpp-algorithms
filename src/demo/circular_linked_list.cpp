//
// Created by codercat on 19-4-18.
//

#include <iostream>
#include "circular_linked_list.h"

int main() {
    CircularLinkedList *circularLinkedList = new CircularLinkedList();
    circularLinkedList->insert(67);
    circularLinkedList->insert(31);
    circularLinkedList->insert(18);
    circularLinkedList->insert(28);
    std::cout << circularLinkedList->toString() << std::endl;
}
