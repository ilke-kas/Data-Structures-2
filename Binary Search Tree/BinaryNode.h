#ifndef _BINARYNODE_H
#define _BINARYNODE_H
#include <iostream>
using namespace std;
/*
* Title: Binary Search Trees
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 2
* Description: This is header for binary nodes
*/
class BinaryNode
{
	public:
		void setItem(const int item);
		int getItem() const;
		void setLeftChild(BinaryNode* leftChild);
		BinaryNode* getLeftChild() const;
		BinaryNode*& getLeftChildRef() ;
		void setRightChild(BinaryNode* rightChild);
		BinaryNode* getRightChild() const;
		BinaryNode*& getRightChildRef() ;
		
	private:
		BinaryNode();
		BinaryNode(const int nodeItem, BinaryNode* left = NULL,BinaryNode* right = NULL);
		
		int item;
		BinaryNode* leftChildPtr;
		BinaryNode* rightChildPtr;
		friend class BinarySearchTree;
};
#endif
