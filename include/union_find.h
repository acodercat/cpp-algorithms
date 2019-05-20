//
// Created by codercat on 19-5-10.
//

#ifndef CPP_ALGORITHMS_UNION_FIND_H
#define CPP_ALGORITHMS_UNION_FIND_H

class UnionFind {
private:
    unsigned int size = 0;
    int *parents;
    // 记录每个根节点所在树的深度
    int *ranks;

public:
    UnionFind(unsigned int size) {
        this->size = size;
        this->parents = new int[size];
        this->ranks = new int[size];
        for ( int i = 0; i < size; i ++ ) {
            this->parents[i] = i;
            this->ranks[i] = 1;
        }
    }

    int find(int element) {
        int parent = parents[element];
        if (parent == element) {
            return parent;
        }
        // pathCompression
        parents[element] = parents[parent];
        return this->find(parents[element]);
    }

//    int find(int element) {
//        int parent = parents[element];
//        if (parent == element) {
//            return parent;
//        }
//        // pathCompression
//        parents[element] = this->find(parents[element]);
//        return parents[element];
//    }

    bool isConnected(int p ,int q) {
        return this->find(p) == this->find(q);
    }

    unsigned int getSize() {
        return this->size;
    }

    void unionElement(int p, int q) {
        int pRoot = this->find(p);
        int qRoot = this->find(q);
        if ( pRoot == qRoot ) {
            return;
        }

        int pRank = this->ranks[pRoot];
        int qRank = this->ranks[qRoot];

        // 把深度低的树的根节点指向深度高的树的根节点,保证树的平衡,避免退化成链表.
        if ( qRank < qRank ) {
            this->parents[qRoot] = pRoot;
        } else if ( pRank < qRank ) {
            this->parents[pRoot] = qRoot;
        } else {
            this->parents[pRoot] = qRoot;
            this->ranks[qRoot] ++;
        }
    }

};



#endif //CPP_ALGORITHMS_UNION_FIND_H
