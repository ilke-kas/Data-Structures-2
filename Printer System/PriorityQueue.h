#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H
#include "Heap.h"
#include "PrintRequest.h"
#include <iostream>
/*
* Title: PriorityQueue.h
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Header of the priority class
*/
using namespace std;
class PriorityQueue
{
	private:
		Heap h;
	public:
		bool isEmpty() const;
		void pqInsert(const PrintRequest& newRequest);
		void pqDelete(PrintRequest& priorityItem);
};
#endif
