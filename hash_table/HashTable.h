#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <string>

class HashTable {
   private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

   public:
    void printTable();
};

class Node {
   public:
    std::string key;
    int value;
    Node *next;
    Node(std::string key, int value);
};

#endif