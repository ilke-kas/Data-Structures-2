#include <iostream>
#include "BinaryNode.h"
/*
* Title: Binary Search Trees
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 2
* Description: This is implementation of binary nodes
*/
/*
* DEFAULT CONSTRUCTOR
*/
BinaryNode::BinaryNode():
	leftChildPtr(NULL),rightChildPtr(NULL) {}
	
/*
* CONSTRUCTOR with arguments
*/	
BinaryNode::BinaryNode(const int nodeItem, BinaryNode* left ,BinaryNode* right ):
	item(nodeItem), leftChildPtr(left),rightChildPtr(right){}
	
/*
*This function will get item in the node
* @return item as int
*/
int BinaryNode::getItem() const
{
	return item;
}
/*
*This function will set the item in the node
*@param nodeItem
*/
 void BinaryNode::setItem(const int nodeItem)
 {
 	item = nodeItem;
 }
 /*
 *This function will get the left children pointer of the node
 *@return leftChildPtr which is BinaryNode pointer
 */
 BinaryNode* BinaryNode::getLeftChild() const
 {
 	return leftChildPtr;
 }
 /*
 *This function will set the left children pointer to another pointer
 *@param leftChild as the BinaryNode pointer
 */
 void BinaryNode::setLeftChild(BinaryNode* leftChild)
 {
 	leftChildPtr = leftChild;
 }
  /*
 *This function will get the right children pointer of the node
 *@return rightChildPtr which is BinaryNode pointer
 */
  BinaryNode* BinaryNode::getRightChild() const
 {
 	return rightChildPtr;
 }
  /*
 *This function will set the right children pointer to another pointer
 *@param rightChild as the BinaryNode pointer
 */
 void BinaryNode::setRightChild(BinaryNode* rightChild)
 {
 	rightChildPtr = rightChild;
 }
 /*
 *This function will get the reference to the left children pointer
 */
BinaryNode*& BinaryNode::getLeftChildRef() 
 {
 	return  leftChildPtr;
 }
  /*
 *This function will get the reference to the right children pointer
 */
 BinaryNode*& BinaryNode::getRightChildRef() 
 {
 	return  rightChildPtr;
 }

