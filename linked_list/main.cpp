/*
 *  main.cpp
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 *
 *  Main program for user to interact with the LinkedList
 */

#include <iostream>

#include "LinkedList.h"

int main(int argc, char *argv[]) {
    LinkedList *myList = new LinkedList(10);
    // for (int i = 0; i < 10; i++) {
    //     myList->append(i);
    // }
    std::cout << myList->size() << std::endl;
    std::cout << myList->getHead() << std::endl;
    std::cout << myList->getTail() << std::endl;
    //myList->print();
    return 0;
}
