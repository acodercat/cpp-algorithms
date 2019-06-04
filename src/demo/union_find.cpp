//
// Created by codercat on 19-4-18.
//

#include <iostream>
using namespace std;
#include "union_find.h"

int main() {
    UnionFind *unionFind = new UnionFind(5);
    unionFind->unionElement(1, 2);
    unionFind->unionElement(1, 4);
    unionFind->unionElement(5, 2);

    unionFind->unionElement(3, 4);

    cout<<unionFind->find(4)<<endl;

}