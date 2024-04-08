#include "HashTable.h"

#include <iostream>
#include <string>

// node constructor
Node::Node(std::string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
}