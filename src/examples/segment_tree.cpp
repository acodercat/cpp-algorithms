//
// Created by codercat on 19-5-7.
//

#include "segment_tree.h"
#include <iostream>

int main() {
    int arr[] = { 1, 2, 3, 5, 6, 7, 8, 9 };
    SegmentTree<int> segmentTree(arr, 8);
    cout<<segmentTree.query(0, 6)<<endl;
    segmentTree.update(0, 10);
    cout<<segmentTree.query(0, 6)<<endl;

}