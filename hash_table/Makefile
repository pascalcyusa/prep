### Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
### Makefile for LinkedList

CXX      = g++
CXXFLAGS = -Wall -Wextra -Wreturn-type -g
LDFLAGS  = -g


main.o: main.cpp HashTable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

LinkedList.o: HashTable.cpp HashTable.h 
	$(CXX) $(CXXFLAGS) -c HashTable.cpp 

main: main.o HashTable.o
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f main *.o *~

