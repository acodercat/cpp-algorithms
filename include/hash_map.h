//
// Created by codercat on 19-6-10.
//

#ifndef CPP_ALGORITHMS_HASH_MAP_H
#define CPP_ALGORITHMS_HASH_MAP_H

#include <assert.h>
#include "avl_tree_map.h"
#include <iostream>
#include <optional>
using namespace std;

template<typename K, typename V>
class HashMap {
private:
    unsigned M;
    unsigned size;
    AVLTreeMap<K, V> *hashtable;

    int hash(string k) {
        std::hash<string> hasher;
        return hasher(k) % M;
    }

public:
    HashMap(int M = 73) {
        this->M = M;
        this->size = 0;
        this->hashtable = new AVLTreeMap<K, V>[M];
    }

    void insert(K k, V v) {
        unsigned index = this->hash(k);
        assert(index < this->M);
        if (!this->contrainsKey(k)) {
            this->size ++;
        }
        this->hashtable[index].insert(k, v);
    }

    optional<V> find(K k) {
        unsigned index = this->hash(k);
        if (index > this->M) {
            return optional<V>();
        }
        return this->hashtable[index].find(k);
    }

    bool contrainsKey(K k) {
        unsigned index = this->hash(k);
        if ((index < this->M) && this->hashtable[index].contrainsKey(k)) {
            return true;
        }
        return false;
    }

    void remove(K k) {
        unsigned index = this->hash(k);
        if ((index < this->M) && this->hashtable[index].contrainsKey(k)) {
            this->hashtable[index].remove(k);
            this->size --;
        }
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned getSize() {
        return this->size;
    }

};

#endif //CPP_ALGORITHMS_HASH_MAP_H
