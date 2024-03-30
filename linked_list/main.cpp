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
    std::cout << "\nValue at index 1 is "
              << myList->get(0)->value << std::endl;

    // test set
    std::cout << "\nSet value at 1 to 4: ";
    myList->set(0, 4);
    std::cout << "Value at index is now "
              << myList->get(0)->value << std::endl;
    myList->print();

    return 0;
}
