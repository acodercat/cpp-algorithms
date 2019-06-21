//
// Created by codercat on 19-6-18.
//

#include <iostream>
#include "dense_weighted_graph.h"

int main() {
    DenseWeightedGraph dwg = DenseWeightedGraph(10);
    dwg.addEdge(1, 0, 5);
//    dwg.addEdge(1, 2, 5);
    dwg.addEdge(4, 8, 5);
//    dwg.addEdge(2, 7, 5);
//    dwg.addEdge(2, 11, 5);
    dwg.dfs();
    dwg.bfs();
//    DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(&dwg, 1);
//    iter.begin();
//    cout<<iter.end()<<endl;
//    cout<<iter.next()<<endl;
//    cout<<iter.next()<<endl;
//
//    cout<<iter.end()<<endl;
}