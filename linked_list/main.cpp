/*
 *  main.cpp
 *  Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
 *
 *  Main program for user to interact with the LinkedList
 */

#include <iostream>

#include "LinkedList.h"

void demo(LinkedList *myList) {
    std::cout << "Size: " << myList->size() << std::endl;
    std::cout << "Head: " << myList->getHead() << std::endl;
    std::cout << "Tail: " << myList->getTail() << std::endl;
    std::cout << "Node(s): [ ";
    myList->print();
    std::cout << "]" << std::endl;
}

int main() {
    LinkedList *myList = new LinkedList(10);
    demo(myList);

    // append some values
    myList->append(16);
    std::cout << "\nAfter adding a value to the back: \n";
    demo(myList);

    // delete last
    myList->deleteLast();
    std::cout << "\nAfter deleting last value: \n";
    demo(myList);

    // prepend some values
    myList->prepend(9);
    std::cout << "\nAfter adding a value to the front: \n";
    demo(myList);

    // prepend some values
    myList->deleteFirst();
    std::cout << "\nAfter deleting first value: \n";
    demo(myList);

    // test get
    std::cout << "\nValue at index 0 is "
              << myList->get(0)->value << std::endl;

    // test set
    std::cout << "\nSet value at index 0 to 4: ";
    myList->set(0, 4);
    std::cout << "\nAfter setting first value to 4: \n";
    demo(myList);

    // test insert
    std::cout << "\nInsert 1 at index 1: ";
    myList->insert(1, 1);
    demo(myList);

    return 0;
}
