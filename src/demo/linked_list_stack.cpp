//
// Created by codercat on 19-4-15.
//

#include <iostream>
#include "linked_list_stack.h"

int main() {
    LinkedListStack<int> *stack = new LinkedListStack<int>();
    stack->push(6);
    stack->push(7);
    stack->push(8);
    stack->push(9);
    stack->pop();
    stack->pop();
    std::cout << stack->top() << std::endl;
}