//
// Created by codercat on 19-4-15.
//


#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
}