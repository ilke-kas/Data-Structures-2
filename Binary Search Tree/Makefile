
CC=g++
CFLAGS= -std=c++11 -c -Wall
OBJS = BinaryNode.o BinarySearchTree.o main.o

hw2: $(OBJS)
	$(CC) -o hw2 $(OBJS)
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CC) $(CFLAGS) BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	$(CC) $(CFLAGS) BinarySearchTree.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o system