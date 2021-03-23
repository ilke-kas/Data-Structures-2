#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H
#include "BinaryNode.h"
/*
* Title: Binary Search Trees
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 2
* Description: This is header for binary search trees
*/
class BinarySearchTree
{
	public: 
	//Constructors
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree& tree); 
	//Destructor
	~BinarySearchTree();
	//desired functions
	bool isEmpty();
	int getHeight(); 
	int getNumberOfNodes();
	bool add(const int newEntry);
	bool remove(const int anEntry);
	bool contains(const int anEntry);
	void preorderTraverse();
	void inorderTraverse();
	void postorderTraverse();
	void levelorderTraverse();
	int span(const int a, const int b);
	void mirror();
	private:
		BinaryNode* root;
		BinarySearchTree* leftSubtree;
		BinarySearchTree* rightSubtree;
		
		//helper functions
		BinarySearchTree& operator=(const BinarySearchTree& rhs);
		void insertItem(BinaryNode* &node, const int& item); 
		void deleteItem(BinaryNode* &node, int item);
		void deleteNodeItem(BinaryNode*& nodePtr);
		void processLeftmost(BinaryNode*& nodePtr, int& item);
		bool searchItem(BinaryNode* nodePtr, int searchedItem) const; 
		void preorder(BinaryNode* nodePtr);
		void inorder(BinaryNode* nodePtr);
		void postorder(BinaryNode* nodePtr);
		void destroyTree(BinaryNode* &nodePtr); 
		void copyTree(BinaryNode * nodePtr, BinaryNode *& newNodePtr) const;
		int getHeightRecursively(BinaryNode* nodePtr); 
		int getNumberOfNodesRecursively(BinaryNode* nodePtr);
		void mirrorHelper(BinaryNode* nodePtr);
		void printLevel(BinaryNode* nodePtr, int level);
		void spanRecursively(BinaryNode* nodePtr, const int a, const int b,int& count);
};
#endif
