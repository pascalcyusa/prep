### Created by Jean Pascal Cyusa Shyaka on Mar 28th, 2024
### Makefile for LinkedList

CXX      = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -g
LDFLAGS  = -g


main.o: main.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h 
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp 

main: main.o LinkedList.o
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f main *.o *~

