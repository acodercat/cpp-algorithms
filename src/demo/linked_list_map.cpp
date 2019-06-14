//
// Created by codercat on 19-6-11.
//


#include <iostream>
#include "linked_list_map.h"
using namespace std;

int main() {
    LinkedListMap<string, string> linkedListMap;
    linkedListMap.insert("asdasdas", "asdasdasd");
    linkedListMap.insert("codercat", "codercat");
    linkedListMap.insert("1", "codercat");
    linkedListMap.insert("2", "codercat");
    linkedListMap.insert("34", "codercat");
    linkedListMap.insert("4", "codercat");
    cout<<*linkedListMap.find("4")<<endl;
    linkedListMap.remove("4");
    cout<<*linkedListMap.find("4")<<endl;
}
