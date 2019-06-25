//
// Created by codercat on 19-6-18.
//

#ifndef CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H
#define CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H

#include <vector>
#include <iostream>
#include <assert.h>
#include "linked_list_stack.h"
#include "linked_list_queue.h"
#include "binary_heap.h"
using namespace std;

typedef double Weight;

class DenseWeightedGraph {
private:
    bool directed;
    vector<vector<Weight>> adj;
    unsigned vertexNum;
    unsigned edgeNum;

    struct Edge {
        Weight weight;
        unsigned a;
        unsigned b;

        Edge (unsigned vertex, unsigned otherVertex, Weight weight) {
            this->a = vertex;
            this->b = otherVertex;
            this->weight = weight;
        }

        Edge () {}

        unsigned getV() {
            return this->a;
        }

        unsigned getW() {
            return this->b;
        }

        Weight getWeight() {
            return this->weight;
        }

        bool operator<(Edge& otherEdge){
            return this->weight < otherEdge.getWeight();
        }

        bool operator<=(Edge& otherEdge){
            return this->weight <= otherEdge.getWeight();
        }

        bool operator>(Edge& otherEdge){
            return this->weight > otherEdge.getWeight();
        }

        bool operator>=(Edge& otherEdge){
            return this->weight >= otherEdge.getWeight();
        }

        bool operator==(Edge& otherEdge){
            return weight == otherEdge.getWeight();
        }

    };

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
        this->adj = vector<vector<Weight>>(vertexNum, vector<Weight>(vertexNum, 0));
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

    void addEdge(unsigned a, unsigned b, Weight w) {
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

    static bool binaryHeapCompare(Edge a, Edge b) {
        return a < b;
    }

    void prim() {
        BinaryHeap<Edge> minHeap = BinaryHeap<Edge>(this->getVertexNum(), this->binaryHeapCompare);
        LinkedListQueue<unsigned> queue = LinkedListQueue<unsigned>();
        vector<bool> visited = vector<bool>(this->getVertexNum(), false);
        queue.enqueue(0);
        while (!queue.isEmpty()) {
            unsigned vertex = queue.dequeue();
            if (visited[vertex]) {
                continue;
            }
            DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(this, vertex);
            visited[vertex] = true;
            for (unsigned otherVertex = iter.begin(); !iter.end(); otherVertex = iter.next()) {
                if (!visited[otherVertex]) {
                    minHeap.insert(Edge(vertex, otherVertex, this->adj[vertex][otherVertex]));
                }
            }
            if (!minHeap.isEmpty()) {
                Edge edge = minHeap.extract();
                if (visited[edge.getV()] && visited[edge.getW()]) {
                    continue;
                }

                if (!visited[edge.getV()]) {
                    queue.enqueue(edge.getV());
                } else {
                    queue.enqueue(edge.getW());
                }
            }
        }
    }

    void dfs() {
        LinkedListStack<unsigned> linkedListStack = LinkedListStack<unsigned>();
        unsigned connectedComponen = 0;
        vector<int> id = vector<int>(vertexNum, -1);
        vector<bool> visited = vector<bool>(this->getVertexNum(), false);
        for (unsigned vertex = 0; vertex < this->getVertexNum(); vertex++) {
            if (visited[vertex]) {
                continue;
            }
            linkedListStack.push(vertex);
            visited[vertex] = true;
            while (!linkedListStack.isEmpty()) {
                typename DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(this, linkedListStack.top());
                id[linkedListStack.top()] = connectedComponen;
                linkedListStack.pop();
                for (unsigned otherVertex = iter.begin(); !iter.end(); otherVertex = iter.next()) {
                    if (!visited[otherVertex]) {
                        visited[otherVertex] = true;
                        linkedListStack.push(otherVertex);
                    }
                }
            }
            connectedComponen++;
        }
        cout<<connectedComponen<<endl;
    }

    void bfs() {
        LinkedListQueue<unsigned> linkedListQueue = LinkedListQueue<unsigned>();
        unsigned connectedComponen = 0;
        vector<int> id = vector<int>(vertexNum, -1);
        vector<int> from = vector<int>(vertexNum, -1);
        vector<bool> visited = vector<bool>(this->getVertexNum(), false);
        for (unsigned vertex = 0; vertex < this->getVertexNum(); vertex++) {
            if (visited[vertex]) {
                continue;
            }
            linkedListQueue.enqueue(vertex);
            visited[vertex] = true;
            while (!linkedListQueue.isEmpty()) {
                unsigned front = linkedListQueue.getFront();
                DenseWeightedGraph::AdjacentIterator iter = DenseWeightedGraph::AdjacentIterator(this, front);
                id[front] = connectedComponen;
                linkedListQueue.dequeue();
                for (unsigned otherVertex = iter.begin(); !iter.end(); otherVertex = iter.next()) {
                    if (!visited[otherVertex]) {
                        from[otherVertex] = front;
                        visited[otherVertex] = true;
                        linkedListQueue.enqueue(otherVertex);
                    }
                }
            }
            connectedComponen++;
        }

        cout<<connectedComponen<<endl;
        for (unsigned a = from[4]; a != -1; a = from[a]) {
            cout<<a<<endl;
        }

    }

//
//    bool isConnected(unsigned a, unsigned b) {
//        assert(a < this->vertexNum);
//        assert(b < this->vertexNum);
//        return this->id[a] == this->id[b];
//    }


};


#endif //CPP_ALGORITHMS_DENSE_WEIGHTED_GRAPH_H
