//
// Created by codercat on 19-6-10.
//

#include <iostream>
#include "hash_map.h"
using namespace std;

int main() {
    HashMap<string, string> *hmap = new HashMap<string, string>;
    hmap->insert("codercat", "rust1");
    hmap->insert("codercat1", "rust2");
    hmap->insert("codercat2", "rust3");
    hmap->insert("codercat3", "rust4");
    hmap->insert("codercat", "rust5");
    cout<<"find:"<<hmap->find("codercat")<<endl;
    cout<<"contrainsKey:"<<hmap->contrainsKey("codercat")<<endl;
    cout<<"size:"<<hmap->getSize()<<endl;
}