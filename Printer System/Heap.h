#ifndef _HEAP_H
#define _HEAP_H
const int MAX_HEAP = 500;
#include <iostream>
#include "PrintRequest.h"
using namespace std;
/*
* Title: Heap.h
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Header file of the heap class
*/

class Heap{
	private:
		
	public:
		Heap(); //default constructor
		bool isEmpty() const;
		void heapInsert(const PrintRequest& newRequest);
		void heapDelete(PrintRequest& rootRequest);
	protected:
		void rebuild(int root);
	private:
		int size;
		PrintRequest requests[MAX_HEAP];		
};

#endif
