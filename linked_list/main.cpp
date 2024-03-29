/*
 *  main.cpp
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 *
 *  Main program for user to interact with the LinkedList
 */

#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList *myList = new LinkedList(10);
    std::cout << "Size: " << myList->size() << std::endl;
    std::cout << "Head: " << myList->getHead() << std::endl;
    std::cout << "Tail:" << myList->getTail() << std::endl;
    std::cout << "Node(s): ";
    myList->print();

    // Append some values
    myList->append(5);
    myList->append(16);
    std::cout << "Size: " << myList->size() << std::endl;
    std::cout << "Head: " << myList->getHead() << std::endl;
    std::cout << "Tail:" << myList->getTail() << std::endl;
    std::cout << "Node(s): ";
    myList->print();

    return 0;
}
