//
// Created by codercat on 19-6-18.
//

#include <iostream>
#include "dense_weighted_graph.h"

int main() {
    DenseWeightedGraph dwg = DenseWeightedGraph(10);
    dwg.addEdge(1, 0, 4);
    dwg.addEdge(1, 2, 5);
    dwg.addEdge(1, 4, 2);
    dwg.addEdge(4, 8, 15);
    dwg.addEdge(2, 8, 51);
//    dwg.addEdge(2, 7, 5);
//    dwg.addEdge(2, 11, 5);
//    dwg.dfs();
//    dwg.bfs();
    dwg.prim();
//    cout<<dwg.isConnected(1, 5)<<endl;
//    DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(&dwg, 1);
//    iter.begin();
//    cout<<iter.end()<<endl;
//    cout<<iter.next()<<endl;
//    cout<<iter.next()<<endl;
//
//    cout<<iter.end()<<endl;
}