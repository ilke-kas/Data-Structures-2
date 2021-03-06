
CC=g++
CFLAGS= -std=c++11 -c -Wall
OBJS = sorting.o main.o

hw1: $(OBJS)
	$(CC) -o hw1 $(OBJS)
sorting.o: sorting.cpp sorting.h
	$(CC) $(CFLAGS) sorting.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o system