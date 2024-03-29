/*
 *  LinkedList.cpp
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 */

#include "LinkedList.h"

#include <iostream>

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

LinkedList::LinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList() {
    Node *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value) {}

bool LinkedList::insert(int value, int index) {}

void LinkedList::print() {
    Node *temp = head;
    while (temp) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

int LinkedList::size() {
    return length;
}

int LinkedList::getHead() {
    return head->value;
}

int LinkedList::getTail() {
    return tail->value;
}
