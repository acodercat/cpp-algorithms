//
// Created by codercat on 19-6-10.
//

#ifndef CPP_ALGORITHMS_HASH_MAP_H
#define CPP_ALGORITHMS_HASH_MAP_H

#include <assert.h>
#include <iostream>
#include <map>
using namespace std;

template<typename K, typename V>
class HashMap {
private:
    unsigned M;
    unsigned size;
    map<K, V> *hashtable;

    int hash(string k) {
        std::hash<string> hasher;
        return hasher(k) % M;
    }

public:
    HashMap(int M = 73) {
        this->M = M;
        this->size = 0;
        this->hashtable = new map<string, string>[M];
    }

    void insert(K k, V v) {
        unsigned index = this->hash(k);
        assert(index < this->M);
        if (!this->contrainsKey(k)) {
            this->size ++;
        }
        this->hashtable[index][k] = v;
    }

    V find(K k) {
        unsigned index = this->hash(k);
        assert(index < this->M);
        return this->hashtable[index][k];
    }

    bool contrainsKey(K k) {
        unsigned index = this->hash(k);
        if (this->hashtable[index].find(k) == this->hashtable[index].end()) {
            return false;
        }
        return true;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned getSize() {
        return this->size;
    }

};

#endif //CPP_ALGORITHMS_HASH_MAP_H
