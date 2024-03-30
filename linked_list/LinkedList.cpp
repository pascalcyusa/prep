/*
 *  LinkedList.cpp
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 */

#include "LinkedList.h"

#include <iostream>

// node constructor
Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

// linkedlist constructor
LinkedList::LinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

// linkedlist destructor
LinkedList::~LinkedList() {
    Node *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

// add to the end of list
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

// add to the front of list
void LinkedList::prepend(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

bool LinkedList::insert(int value, int index) {
    if (index < 0 or index > length)
        return false;
    if (index == 0) {
        prepend(value);
        return true;
    }
    if (index == length) {
        append(value);
        return true;
    }
    Node *newNode = new Node(value);
    Node *temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
}

void LinkedList::print() {
    Node *temp = head;
    while (temp) {
        std::cout << temp->value << " ";
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

void LinkedList::deleteLast() {
    // empty linked list
    if (length == 0)
        return;
    // list with one element
    Node *temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        // normal circurmstances
        Node *pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void LinkedList::deleteFirst() {
    if (length == 0)
        return;
    Node *temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
    }
    delete temp;
    length--;
}

Node *LinkedList::get(int index) {
    if (index < 0 or index >= length)
        return nullptr;
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

bool LinkedList::set(int index, int value) {
    Node *temp = get(index);
    if (temp) {
        temp->value = value;
        return true;
    }
    return false;
}

void LinkedList::deleteNode(int index) {
    if (index < 0 or index >= length)
        return;
    if (index == 0)
        return deleteFirst();
    if (index == length - 1)
        return deleteLast();
    Node *prev = get(index - 1);
    Node *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
}

void LinkedList::reverse() {
    Node *temp = head;
    head = tail;
    tail = temp;
    Node *after = temp->next;
    Node *before = nullptr;
    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}