//
// Created by codercat on 19-6-18.
//

#ifndef CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H
#define CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H

#include <vector>
#include <iostream>
#include <assert.h>
#include <linked_list_stack.h>
#include <linked_list_queue.h>
using namespace std;

class DenseWeightedGraph {
private:
    bool directed;
    vector<vector<double>> adj;
    unsigned vertexNum;
    unsigned edgeNum;

public:
    class AdjacentIterator {
        int curIndex = -1;
        unsigned v = 0;
        DenseWeightedGraph *g;
    public:
        AdjacentIterator(DenseWeightedGraph *g, unsigned v) {
            this->g = g;
            assert(v < this->g->getVertexNum());
            this->curIndex = -1;
            this->v = v;
        }

        unsigned begin() {
            this->curIndex = -1;
            return this->next();
        }

        int next() {
            for (this->curIndex ++; this->curIndex < this->g->getVertexNum(); this->curIndex++) {
                if (this->g->adj[v][this->curIndex] != 0) {
                    return this->curIndex;
                }
            }
            return -1;
        }

        bool end() {
            return this->curIndex >= this->g->getVertexNum();
        }

    };

    DenseWeightedGraph(unsigned vertexNum, bool directed = false) {
        this->adj = vector<vector<double>>(vertexNum, vector<double>(vertexNum, 0));
        this->vertexNum = vertexNum;
        this->edgeNum = 0;
        this->directed = directed;
    }

    bool hasEdge(unsigned a, unsigned b) {
        assert(a < this->vertexNum);
        assert(b < this->vertexNum);
        if (this->adj[a][b] == 0) {
            return false;
        }
        return true;
    }

    void addEdge(unsigned a, unsigned b, double w) {
        assert(a < this->vertexNum);
        assert(b < this->vertexNum);
        if (this->hasEdge(a, b)) {
            return;
        }
        if (!directed) {
            this->adj[b][a] = w;
        }
        this->adj[a][b] = w;
        this->edgeNum ++;
    }

    unsigned getEdgeNum() {
        return this->edgeNum;
    }

    unsigned getVertexNum() {
        return this->vertexNum;
    }

    void dfs() {
        LinkedListStack<unsigned> linkedListStack = LinkedListStack<unsigned>();
        unsigned connectedComponen = 0;
        vector<bool> visited = vector<bool>(this->getVertexNum(), false);
        for (unsigned vertex = 0; vertex < this->getVertexNum(); vertex++) {
            if (visited[vertex]) {
                continue;
            }
            linkedListStack.push(vertex);
            visited[vertex] = true;
            while (!linkedListStack.isEmpty()) {
                typename DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(this, linkedListStack.top());
                linkedListStack.pop();
                for (unsigned otherVertex = iter.begin(); !iter.end(); otherVertex = iter.next()) {
                    if (visited[otherVertex]) {
                        continue;
                    }
                    linkedListStack.push(otherVertex);
                    visited[otherVertex] = true;
                }
            }
            connectedComponen++;
        }
        cout<<connectedComponen<<endl;
    }

    void bfs() {
        LinkedListQueue<unsigned> linkedListQueue = LinkedListQueue<unsigned>();
        unsigned connectedComponen = 0;
        vector<bool> visited = vector<bool>(this->getVertexNum(), false);
        for (unsigned vertex = 0; vertex < this->getVertexNum(); vertex++) {
            if (visited[vertex]) {
                continue;
            }
            linkedListQueue.enqueue(vertex);
            visited[vertex] = true;
            while (!linkedListQueue.isEmpty()) {
                DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(this, linkedListQueue.getFront());
                linkedListQueue.dequeue();
                for (unsigned otherVertex = iter.begin(); !iter.end(); otherVertex = iter.next()) {
                    if (visited[otherVertex]) {
                        continue;
                    }
                    linkedListQueue.enqueue(otherVertex);
                    visited[otherVertex] = true;
                }
            }
            connectedComponen++;
        }
        cout<<connectedComponen<<endl;
    }


    bool isConnected(unsigned a, unsigned b) {

    }


};


#endif //CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H
