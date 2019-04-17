cmake_minimum_required(VERSION 3.13)
project(cpp-algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

add_executable(linked_list src/demo/linked_list.cpp)
add_executable(circular_queue src/demo/circular_queue.cpp)
add_executable(linked_list_queue src/demo/linked_list_queue.cpp)
add_executable(linked_list_stack src/demo/linked_list_stack.cpp)
add_executable(stack src/demo/stack.cpp)
add_executable(trie_tree src/demo/trie_tree.cpp)

