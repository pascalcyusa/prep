#include "HashTable.h"

#include <iostream>

// node constructor
Node::Node(std::string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
}

void HashTable::printTable(){
    for(int i=0; i<SIZE; i++){
        std::cout << i << ":"<< std::endl;
        if(dataMap[i]){
            Node *temp = dataMap[i];
            while(temp){
                std::cout << "  {" << temp->key << ", " << temp->value << "}";
                temp=temp->next;
            }
        }
    }
}