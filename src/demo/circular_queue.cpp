//
// Created by codercat on 19-4-15.
//

#include <iostream>
#include "circular_queue.h"

int main() {
    CircularQueue<int> circularQueue(5);
    circularQueue.enqueue(1);
    circularQueue.enqueue(2);
    circularQueue.enqueue(3);
    std::cout <<"dequeue:"<< circularQueue.dequeue() << std::endl;
    std::cout <<"dequeue:"<< circularQueue.dequeue() << std::endl;
    circularQueue.enqueue(4);
    circularQueue.enqueue(5);
    circularQueue.enqueue(6);
    std::cout <<"dequeue:"<< circularQueue.dequeue() << std::endl;
    std::cout <<"dequeue:"<< circularQueue.dequeue() << std::endl;
    std::cout <<"getFront:"<< circularQueue.getFront() << std::endl;
}