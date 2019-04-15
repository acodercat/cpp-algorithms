//
// Created by codercat on 19-4-15.
//

#include <iostream>
#include "linked_list_queue.h"

int main() {
    LinkedListQueue *linkedListQueue = new LinkedListQueue();
    linkedListQueue->enqueue(5);
    linkedListQueue->enqueue(6);
    linkedListQueue->enqueue(7);
    std::cout << linkedListQueue->toString() << std::endl;
    linkedListQueue->dequeue();
    std::cout << linkedListQueue->toString() << std::endl;
}