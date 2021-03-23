#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
/*
* Title: Binary Search Trees
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 2
* Description: This is implementation of binary search trees
*/
/*
* DEFAULT CONSTRUCTOR
*/
BinarySearchTree::BinarySearchTree(): root(NULL), leftSubtree(NULL), rightSubtree(NULL){
	
}
/*
*COPY CONSTRUCTOR
*/
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
{
	copyTree(tree.root, root);
}
/*
* Helper function to copy tree
*/
void BinarySearchTree::copyTree(BinaryNode* treePtr, BinaryNode *& newTreePtr) const{
	
	if(treePtr != NULL) //copy node
	{
		newTreePtr = new BinaryNode(treePtr->getItem(),NULL,NULL);
		copyTree(treePtr->getLeftChild(), newTreePtr->getLeftChildRef());
		copyTree(treePtr->getRightChild(), newTreePtr->getRightChildRef());	
	}
	else
		newTreePtr = NULL; //copy empty tree
}
/*
*DESTRUCTOR
*/
BinarySearchTree::~BinarySearchTree()
{
	destroyTree(root);
}
/*
* Helper function to destroy tree recursively
*@param node which is destroyed
*/
void BinarySearchTree::destroyTree(BinaryNode*& nodePtr)
{
	if(nodePtr != NULL){
		destroyTree(nodePtr->getLeftChildRef());
		destroyTree(nodePtr->getRightChildRef());
		delete nodePtr;
		nodePtr =NULL;
	}
}
/*
* Test whether BST is empty
*@return true if BST is empty; otherwise false
*/
bool BinarySearchTree::isEmpty()
{
	return (root == NULL);
}
/* Get the height of the BST
* @return the height of BST
*/
int BinarySearchTree::getHeight()
{
	 return getHeightRecursively(root);
}
/*
*Helper function to get height
* @param nodePtr 
* @return int as the height 
*/
int BinarySearchTree::getHeightRecursively(BinaryNode* nodePtr)
{
	if(nodePtr == NULL)
		return 0;
	else
		return 1 + max(getHeightRecursively(nodePtr->getLeftChild()),getHeightRecursively(nodePtr->getRightChild()));
}
/*Get the number of nodes
* @return the number of nodes in BST
*/
int BinarySearchTree::getNumberOfNodes()
{
	return getNumberOfNodesRecursively(root);
}
/*
*Helper function to get number of nodes
*@param nodePtr
*@return int as the number of nodes
*/
int BinarySearchTree::getNumberOfNodesRecursively(BinaryNode* nodePtr)
{
	if(nodePtr == NULL)
		return 0;
	else
		return 1 + getNumberOfNodesRecursively(nodePtr->getLeftChild()) + getNumberOfNodesRecursively(nodePtr->getRightChild());		
}
/*
*Adds a new node containing a given data item to the BST.
*If data item already exists in the current BST, then don't insert.
*@param newEntry as the new node item
*@return bool to check addition is succesful or not
*/
bool BinarySearchTree::add(const int newEntry)
{
	if( contains(newEntry) )
		return false;
	else
	{
		insertItem(root,newEntry);
		return true;
	}
}
/*
*Helper function to add item to tree
*@param node as the BinarNode pointer
*@param item as the wanted value to be added
*/
void BinarySearchTree::insertItem( BinaryNode*& node, const int & item)
{
	if(node == NULL)
	{
		node = new BinaryNode(item,NULL,NULL);
	}	
	else if(item < node->getItem())
		insertItem(node->getLeftChildRef(),item);
	else 
		insertItem(node->getRightChildRef(),item);
}
/* Removes the node containing the given data item from BST
*@param anEntry as the entry wanted to be removed
*@return bool to check remove operation is succesful or not
*/
bool BinarySearchTree::remove( const int anEntry)
{
	if(!contains(anEntry))
		return false;
	else
	{
		deleteItem(root, anEntry);
		return true;
	}
}
/*
*Helper function to remove item from tree
*@param node as the BinaryNode pointer
*@param item as the wanted value to be removed
*@return bool to indicate whether remove operation is succesful or not
*/
void BinarySearchTree::deleteItem(BinaryNode*& node, int item)
{
	if(node == NULL ) 
		return;
	else if( item == node->getItem())
	{
		deleteNodeItem(node);
	}
	else if (item < node->getItem())
		deleteItem(node->getLeftChildRef(), item);
	else
		deleteItem(node->getRightChildRef(),item);
}
/*
* This helper function will delete the node with no child, one child or two children
*@param nodePtr as
*/
void BinarySearchTree::deleteNodeItem(BinaryNode*& nodePtr)
{
	BinaryNode *delPtr;
	int replacementItem;
	//(1) Test for a leaf
	if((nodePtr->getLeftChild() == NULL) &&(nodePtr->getRightChild() == NULL))
	{
		delete nodePtr;
		nodePtr = NULL;
	}
	//(2) Test for no left child
	else if(nodePtr->getLeftChild() == NULL)
	{
		delPtr = nodePtr;
		nodePtr = nodePtr->getRightChild();
		delPtr->setRightChild(NULL);
		delete delPtr; 
	}
	//(3) Test for no right child
	else if(nodePtr->getRightChild() == NULL)
	{
		delPtr = nodePtr;
		nodePtr = nodePtr->getLeftChild();
		delPtr->setLeftChild(NULL);
		delete delPtr;
	}
	//(4) There are two children
	//Retrieve and delete the inorder successor
	else{
		processLeftmost(nodePtr->getRightChildRef(),replacementItem);
		nodePtr->setItem(replacementItem);
	}
}
/*
* Helper function for deletItemNode function
*@param nodePtr as BinaryNode pointer
*@param item as int to indicate replacement value
*/
void BinarySearchTree::processLeftmost(BinaryNode*& nodePtr, int& item)
{
	if(nodePtr->getLeftChild()==NULL)
	{
		item = nodePtr->getItem();
		BinaryNode* delPtr = nodePtr;
		nodePtr = nodePtr->getRightChild();
		delPtr->setRightChild(NULL);
		delete delPtr;
	}
	else
		processLeftmost(nodePtr->getLeftChildRef(),item);
}
/* This function test whether the given data item occurs in the BST.
* @param anEntry as the searched value
* @return bool 
*/
bool BinarySearchTree::contains(const int anEntry)
{
	return searchItem(root,anEntry);	
}
/*
*Helper function for contain function
*@param nodePtr as BinaryNode pointer
*@param searchedItem
*/
bool BinarySearchTree::searchItem(BinaryNode* nodePtr, int searchedItem) const
{
	if(nodePtr == NULL)
		return false;
	else if( searchedItem == nodePtr->getItem())
		return true;
	else if( searchedItem < nodePtr->getItem())
		return searchItem(nodePtr->getLeftChild(),searchedItem);
	else
		 return searchItem(nodePtr->getRightChild(),searchedItem);
}
/* Traverses the BST in preorder and prints data item values in tarversal order
*/
void BinarySearchTree::preorderTraverse()
{
	cout<<"Preorder Traverse: ";
	preorder(root);
	cout<<endl;
}
/*Helper function for preorder traversal
*@param nodePtr as BinaryNode pointer
*/
void BinarySearchTree::preorder(BinaryNode* nodePtr)
{
	if(nodePtr != NULL)
	{
		cout<<nodePtr->getItem()<<"\t";
		preorder(nodePtr->getLeftChild());
		preorder(nodePtr->getRightChild());
	}
}
/* Traverses the BST in inorder and prints data item values in tarversal order
*/
void BinarySearchTree::inorderTraverse()
{
	cout<<"Inorder Traverse: ";
	inorder(root);
	cout<<endl;
}
/*Helper function for inorder traversal
*@param nodePtr as BinaryNode pointer
*/
void BinarySearchTree::inorder(BinaryNode* nodePtr)
{
	if(nodePtr != NULL)
	{
		inorder(nodePtr->getLeftChild());
		cout<<nodePtr->getItem()<<"\t";
		inorder(nodePtr->getRightChild());
	}
}
/* Traverses the BST in postorder and prints data item values in tarversal order
*/
void BinarySearchTree::postorderTraverse()
{
	cout<<"Postorder Traverse: ";
	postorder(root);
	cout<<endl;
}
/*Helper function for inorder traversal
*@param nodePtr as BinaryNode pointer
*/
void BinarySearchTree::postorder(BinaryNode* nodePtr)
{
	if(nodePtr != NULL)
	{
		postorder(nodePtr->getLeftChild());
		postorder(nodePtr->getRightChild());
		cout<<nodePtr->getItem()<<"\t";
	}
}
/*Changes BST so that the roles of the left and right pointers
*are swapped at every node
*/
void BinarySearchTree::mirror()
{ 
	mirrorHelper(root);
}
/*Helper function for mirror function
*@param nodePtr as the BinaryNode pointer
*/
void BinarySearchTree::mirrorHelper(BinaryNode* nodePtr)
{
	if(nodePtr != NULL)
	{
		mirrorHelper(nodePtr->getLeftChild());
		mirrorHelper(nodePtr->getRightChild());
		BinaryNode* temp = nodePtr->getLeftChild();
		nodePtr->setLeftChild(nodePtr->getRightChild());
		nodePtr->setRightChild(temp);
	
	}
}
/*
*Operator overloading for BinarySearch Tree
*/
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs)
{
	if(this != &rhs )
	{
		destroyTree(root);
		copyTree(rhs.root,root);
	}
	return *this;
}
/* Traverses the BST in level-order and prints 
*data item values in traversal order. 
*/
void BinarySearchTree::levelorderTraverse()
{
	for(int i = 1; i <= getHeight(); i++)
	{
		printLevel(root,i);	
	}
}
/*Helper function for levelorderTraverse 
*Print every level of the BST
*@param nodePtr as BinaryNode pointer
*@param  level 
*/
void BinarySearchTree::printLevel(BinaryNode* nodePtr,int level)
{
	if(nodePtr == NULL)
		return;
	if(level == 1)
		cout<<nodePtr->getItem()<<" ";
	else if(level > 1)
	{
		printLevel(nodePtr->getLeftChild(),level-1);
		printLevel(nodePtr->getRightChild(), level-1);
	}
	
}
/*Returns the number of nodes in the BST with data values within
*a specific range such that a<=x<=b
*@param a as the lowest value
*@param b as the highest value
*@return count
*/

int BinarySearchTree::span(const int a, const int b)
{
	int count = 0;
	spanRecursively(root,a,b,count);
	return count;
}
/*Helper function for span 
*@param nodePtr as the BinaryNode pointer
*@param a as the lowest value
*@param b as the highest value
*@param count as  the number of nodes within the range 
*/
void BinarySearchTree::spanRecursively(BinaryNode* nodePtr, const int a, const int b, int& count)
{
	if(nodePtr != NULL)
	{
		if( nodePtr->getItem() == a )
		{
			count++;
			spanRecursively(nodePtr->getRightChild(),a,b,count);
			
		}
		else if( nodePtr->getItem() == b)
		{
			count++;
			spanRecursively(nodePtr->getLeftChild(),a,b,count);
			
		}
		else if( nodePtr->getItem() < a)
		{ 
			spanRecursively(nodePtr->getRightChild(),a,b,count);	
		}
		else if(  nodePtr->getItem() > b)
		{
			spanRecursively(nodePtr->getLeftChild(),a,b,count);
		
		}
		else
		{
			count++;
			spanRecursively(nodePtr->getLeftChild(),a,b,count);
			spanRecursively(nodePtr->getRightChild(),a,b,count);
		}
	}
}

