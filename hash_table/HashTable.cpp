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
        std::cout << i << ":" << std::endl;
        if(dataMap[i]){
            Node *temp = dataMap[i];
            while(temp){
                std::cout << "  {" << temp->key << ", " << temp->value << "}"
                << std::endl;
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
    Node* newNode = new Node(key, value);
    if(dataMap[index] ==  nullptr){
        dataMap[index] == newNode;
    } else {
        Node *temp = dataMap[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // int index = hash(key);
    // Node* current = dataMap[index];

    // // If the key already exists, update its value
    // while (current != nullptr) {
    //     if (current->key == key) {
    //         current->value = value;
    //         return;
    //     }
    //     current = current->next;
    // }

    // // If the key doesn't exist, create a new node and add it to the beginning 
    // // of the linked list
    // Node* newNode = new Node(key, value);
    // newNode->next = dataMap[index];
    // dataMap[index] = newNode;
}