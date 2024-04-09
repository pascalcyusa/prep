#include "HashTable.h"

#include <iostream>

// node constructor
Node::Node(std::string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
}


// printTable
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

// hash function
int HashTable::hash(std::string key) {
    int hash=0;
    for(int i=0; i<static_cast<int>(key.length()); i++){
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}

// set function
void HashTable::set(std::string key, int value){
    int index = hash(key);
    Node *newNode = new Node(key, value);
    if(dataMap[index] ==  nullptr){
        dataMap[index] == newNode;
    } else {
        Node *temp = dataMap[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}