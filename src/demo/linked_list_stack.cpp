//
// Created by codercat on 19-4-15.
//

#include <iostream>
#include "linked_list_stack.h"

int main() {
    LinkedListStack *stack = new LinkedListStack();
    stack->push(6);
    stack->push(7);
    stack->push(8);
    stack->push(9);
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
}