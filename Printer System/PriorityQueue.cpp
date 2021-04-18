#include "PriorityQueue.h"
/*
* Title: PriorityQueue.cpp
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Implementation of the priority class which is heap-based
*/
/*
*Function that shows queue is empty or not
*@return bool
*/
bool PriorityQueue::isEmpty() const{
	return h.isEmpty();
}
/*
*Function that insert print request to the priority queue
*@param newRequest as the inserted request to the priority queue
*/
void PriorityQueue::pqInsert(const PrintRequest& newRequest){
	h.heapInsert(newRequest);	
}
/*
*Function that delete the print request that has the highest priority
*@param prirorityItem as the deleted item from the priority queue
*/
void PriorityQueue::pqDelete(PrintRequest& priorityItem){
	h.heapDelete(priorityItem);
}

