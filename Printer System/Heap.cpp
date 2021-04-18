#include <iostream>
#include "Heap.h"
using namespace std;

/*
* Title: Heap.cpp
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Implementation of the heap class
*/
/*
* DEFAULT CONSTRUCTOR
*/
Heap::Heap(): size(0){
}
/*
* Function that shows whether heap-based queue is empty or not
* @return boolean value
*/
bool Heap::isEmpty() const{
	return (size == 0);
}
/*
*Function that insert new request to the heap-based priority queue
*@param newRequest as the added print request to the heap
*/
void Heap::heapInsert(const PrintRequest& newRequest)
{
    
	if(size < MAX_HEAP)
	{
		requests[size] = newRequest;
		//Trickle new item up to its proper position
		int place = size;
		int parent  = (place-1)/2;
		while( (place > 0) && ((requests[place].getPriority() > requests[parent].getPriority())
				|| ((requests[place].getPriority() == requests[parent].getPriority()) && (requests[place].getRequestTime()< requests[parent].getRequestTime() ) )))
		{
		
				PrintRequest temp = requests[parent];
				requests[parent] = requests[place];
				requests[place] = temp;
				
				place = parent;
				parent = (place - 1) / 2;
		}
		size++;
	}
}
/*
* Function that delete the root request from the heap-based priority queue
*@param rootRequest ti get the deleted print request from the heap
*/
void Heap::heapDelete(PrintRequest& rootRequest)
{
	if(!(isEmpty()))
	{
		rootRequest = requests[0];
        requests[0] = requests[--size];
		rebuild(0);
	}
}
/*
* This function will rebuild the heap
*@param root as the starting point of the rebuilding
*/
void Heap::rebuild(int root)
{
	int child = 2 * root +1;
	if(child < size)
	{
		int rightChild = child + 1;
		if((rightChild < size ))
		{
			if( (requests[rightChild].getPriority() > requests[child].getPriority()) )
				child = rightChild;
			else if((requests[rightChild].getPriority() == requests[child].getPriority()) && (requests[rightChild].getRequestTime() <(requests[child].getRequestTime() ) ))
				child = rightChild;
		}
	
	//If root's item is smller than larger child, swap values
	if((requests[root].getPriority() < requests[child].getPriority())
	    ||((requests[root].getPriority() == requests[child].getPriority())&& (requests[child].getRequestTime() <requests[root].getRequestTime())) )
	{
		PrintRequest temp = requests[root];
		requests[root] = requests[child];
		requests[child] = temp;
		//transform the new subtree into heap 
		rebuild(child);
	}
}
}
