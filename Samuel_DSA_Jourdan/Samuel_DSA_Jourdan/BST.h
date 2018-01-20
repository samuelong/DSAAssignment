/* Group NoIdea
Samuel Ong S10171663K
Jourdan Lim S10166869D
*/
#pragma once

#include <minmax.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "Queue.h"
#include "BinaryNode.h"

//Binary Search Tree
class BST
{
private:
	
	//Binary Tree Node
	typedef int ItemType;

	BTNode* root;

	//Adds a new BTNode into the BT with AVL Tree and returns the New Node
	BTNode* avlAdd(BTNode* &node, ItemType item);
	//Returns the BTNode based on Index
	BTNode getNode(int nodeIndex);
	//Search for the BTNode based on item and returns a string that shows the route. "" if not found.
	string search(BTNode* node, ItemType item);
	//Get Node Tree Height
	int getHeight(BTNode* node);
	//Returns the number of Nodes in the Binary Tree.
	int countNode(BTNode* node);
	//Returns a Queue that contains every level of the Binary Tree. Starts from the root.
	Queue* getLevelByLevel(BTNode* node);
	//Returns the height difference between 2 subtrees under the Node.
	int balance(BTNode* node);
	//Rotates the Tree if the tree is not balanced.
	void avlRotate(BTNode* &node);
	//RotateLeft - Does a Left Rotation on a Node to balance
	void rotateLeft(BTNode* &node);
	//RotateRight - Does a Right Rotation on a Node to balance
	void rotateRight(BTNode* &node);
	//RotateLeft-Right - Does a Left Rotation and Right Rotation on a Node to balance
	void rotateLeftRight(BTNode* &node);
	//RotateRight-Left - Does a Right Rotation and Left Rotation on a Node to balance
	void rotateRightLeft(BTNode* &node);
	//Display variable "no" number of spaces
	void displaySpaces(int no);
	//Display the Binary Tree with node as root
	void displayBT(BTNode* node);
	//Display the values in ascending order
	void displayAsc(BTNode* node);
	//Deletes a value in the Binary Tree.
	bool deleteValue(BTNode* &node, ItemType item);

public:

	//Default Constructors
	BST();
	~BST();

	//Inserts a value into the BST
	void insert(ItemType item);
	//Populate AVL Binary Tree using SUM of Nodes larger or equal to Parameter
	void populateAVLBT(int sum);
	//Search for the BTNode based on item
	void search(ItemType item);
	//Deletes the BTNode based on item
	void deleteValue(ItemType item);
	//Display all items in Ascending order
	void displayAsc();
	//Display the kth node in the Binary Tree. Traversals through non-null Nodes. Starts from 1.
	void displayKNode(int kNode);
	//Display the Binary Tree
	void displayBT();
};