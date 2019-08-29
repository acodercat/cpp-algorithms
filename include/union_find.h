//
// Created by codercat on 19-5-10.
//

#ifndef CPP_ALGORITHMS_UNION_FIND_H
#define CPP_ALGORITHMS_UNION_FIND_H

class UnionFind {
private:
    // 元素个数
    unsigned int elementNum = 0;
    // 联通分量
    unsigned int connectedComponent = 0;
    int *parents;
    // 记录每个节点所在树的深度
    int *ranks;

public:
    UnionFind(unsigned int elementNum) {
        this->elementNum = elementNum;
        // 初始情况下联通分量为元素个数
        this->connectedComponent = elementNum;
        this->parents = new int[elementNum];
        this->ranks = new int[elementNum];
        for ( int i = 0; i < elementNum; i ++ ) {
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

    unsigned int getElementNum() {
        return this->elementNum;
    }

    unsigned int getConnectedComponent() {
        return this->connectedComponent;
    }

    void unionElement(int p, int q) {
        int pRoot = this->find(p);
        int qRoot = this->find(q);

        // 如果两个元素的根节点相同，则代表它们属于同一个集合，就不再需要合并
        if ( pRoot == qRoot ) {
            return;
        }

        int pRank = this->ranks[pRoot];
        int qRank = this->ranks[qRoot];

        // 把深度低的树的根节点指向深度高的树的根节点,保证树的平衡,避免退化成链表.
        if ( pRank > qRank ) {
            this->parents[qRoot] = pRoot;
        } else if ( pRank < qRank ) {
            this->parents[pRoot] = qRoot;
        } else {
            this->parents[pRoot] = qRoot;
            this->ranks[qRoot] ++;
        }

        this->connectedComponent --;
    }

    ~UnionFind() {
        delete this->parents;
        delete this->ranks;
    }

};



#endif //CPP_ALGORITHMS_UNION_FIND_H
