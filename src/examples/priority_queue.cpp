//
// Created by codercat on 19-6-14.
//

#include <iostream>
#include "priority_queue.h"

int main() {
    PriorityQueue<int> priorityQueue(5);
    priorityQueue.enqueue(1);
    priorityQueue.enqueue(2);
    priorityQueue.enqueue(3);
    std::cout <<"dequeue:"<< priorityQueue.dequeue() << std::endl;
    std::cout <<"dequeue:"<< priorityQueue.dequeue() << std::endl;
    priorityQueue.enqueue(4);
    priorityQueue.enqueue(5);
    priorityQueue.enqueue(6);
    std::cout <<"dequeue:"<< priorityQueue.dequeue() << std::endl;
    std::cout <<"dequeue:"<< priorityQueue.dequeue() << std::endl;
    std::cout <<"getFront:"<< priorityQueue.getFront() << std::endl;
}