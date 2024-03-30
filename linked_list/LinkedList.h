/*
 *  LinkedList.h
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 */

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>

class Node {
   public:
    int value;
    Node *next;
    Node(int value);
};

class LinkedList {
   private:
    Node *head;
    Node *tail;
    int length;

   public:
    LinkedList(int value);
    ~LinkedList();
    void append(int value);
    void prepend(int value);
    bool insert(int value, int index);
    void print();
    int size();
    int getHead();
    int getTail();
    void deleteLast();
    void deleteFirst();
    Node *get(int index);
    bool set(int index, int value);
};

#endif