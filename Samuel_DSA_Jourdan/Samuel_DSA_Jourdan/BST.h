#pragma once

#include <minmax.h>
#include <math.h>
#include <iostream>
#include "Queue.h"
#include "BinaryNode.h"

//Binary Search Tree
class BST
{
private:
	
	//Binary Tree Node
	typedef int ItemType;

	BTNode* root;

	//Adds a new BTNode into the BT
	BTNode* Add(BTNode* &node, ItemType item);
	//Adds a new BTNode into the BT with AVL Tree
	BTNode* AVLAdd(BTNode* &node, ItemType item);
	//Returns the BTNode by Index
	BTNode GetNode(int nodeIndex);
	//Get Node Height
	int GetHeight(BTNode* node);
	//Check if Root Node is balanced
	bool IsBalance();
	//Check if Node is balanced
	bool IsBalance(BTNode* node);
	//Returns the height difference between 2 subtrees under the main tree
	int Balance(BTNode* node);
	//Does Rotation if required.
	BTNode* AVLRotate(BTNode* node);
	//RotateLeft
	BTNode* &RotateLeft(BTNode* node);
	//RotateRight
	BTNode* &RotateRight(BTNode* node);
	//RotateLeft-Right
	BTNode* &RotateLeftRight(BTNode* node);
	//RotateRight-Left
	BTNode* RotateRightLeft(BTNode* node);

public:

	//Default Constructors
	BST();
	~BST();
	
	//ADD IN MORE OPERATIONS IF REQUIRED.
	//FOR MAIN FUNCTIONALITIES

	//Inserts a BTNode into the BST
	void Insert(ItemType item);
	//Populate AVL BT by SUM of Nodes be larger or equal to Parameter at minimum
	void PopulateAVLBT(int sum);
	//Search for the BTNode based on item
	BTNode Search(ItemType item);
	//Adds a new BTNode into the BT
	BTNode* Add(BTNode* node, ItemType item);
	//Adds a new BTNode into the BT with AVL Tree
	BTNode* AVLAdd(BTNode* node, ItemType item);
	//Deletes the BTNode based on item
	bool Delete(ItemType item);
	//Display all items in Ascending order
	void DisplayItemAsc();
	//Display the Binary Tree
	void DisplayBT();
	void DisplayBT(BTNode* node);
};