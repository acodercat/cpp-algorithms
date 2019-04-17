//
// Created by codercat on 19-4-16.
//

#include <iostream>
#include "trie_tree.h"

using namespace std;

int main() {
    TrieTree *trieTree = new TrieTree();
    trieTree->insert("cat", 12121);
    trieTree->insert("cat", 3214234);
    trieTree->insert("cat1212", 555555);
    cout<<trieTree->find("cat1212")->v<<endl;

}