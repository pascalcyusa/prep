#include <iostream>

#include "HashTable.h"

int main(int argc, char *argv[]) {
    HashTable *myHashTable = new HashTable();
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);
    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);
    myHashTable->printTable();
}