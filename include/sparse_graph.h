//
// Created by codercat on 19-6-18.
//

#ifndef CPP_ALGORITHMS_SPARSE_GRAPH_H
#define CPP_ALGORITHMS_SPARSE_GRAPH_H

#include <vector>
#include <assert.h>
using namespace std;

template<typename G>
class SparseWeightedGraph {
private:
    bool directed;
    vector<vector<G>> vertexes;
    unsigned vertexNum;
    unsigned edgeNum;
    SparseGraph(unsigned vertexNum, bool directed) {
        this->vertexes = vector<vector<G>>(vertexNum, vector<G>());
        this->vertexNum = vertexNum;
        this->directed = directed;
    }

    void addEdge(G a, G b) {

    }



};


#endif //CPP_ALGORITHMS_SPARSE_GRAPH_H
