#include <iostream>

#include "HashTable.h"

int main(int argc, char *argv[]) {
    HashTable *myHashTable = new HashTable();

    // test set function
    std::cout << "Setting values..." << std::endl;
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);
    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);
    myHashTable->printTable();

    // test get function
    std::cout << "\nGetting values..." << std::endl;
    std::cout << "\nLumber: " << myHashTable->get("lumber") << std::endl;
    std::cout << "Bolts: " << myHashTable->get("bolts") << std::endl;

    // test keys function
    std::vector<std::string> myKeys = myHashTable->keys();
    std::cout << "\nKeys: ";
    for (auto key : myKeys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}