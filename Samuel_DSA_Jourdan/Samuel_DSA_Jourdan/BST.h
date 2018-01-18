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

	//Adds a new BTNode into the BT with AVL Tree
	BTNode* avlAdd(BTNode* &node, ItemType item);
	//Returns the BTNode by Index
	BTNode getNode(int nodeIndex);
	//Search for the BTNode based on item
	string search(BTNode* node, ItemType item);
	//Get Node Height
	int getHeight(BTNode* node);
	//Count the number of nodes
	int countNode(BTNode* node);
	//Get Level By Level Queue of BT
	Queue* getLevelByLevel(BTNode* node);
	//Returns the height difference between 2 subtrees under the main tree
	int balance(BTNode* node);
	//Does Rotation if required.
	BTNode* avlRotate(BTNode* &node);
	//RotateLeft
	BTNode* rotateLeft(BTNode* node);
	//RotateRight
	BTNode* rotateRight(BTNode* node);
	//RotateLeft-Right
	BTNode* rotateLeftRight(BTNode* node);
	//RotateRight-Left
	BTNode* rotateRightLeft(BTNode* node);
	//Display spaces
	void displaySpaces(int no);
	//Display the Binary Tree
	void displayBT(BTNode* node);
	//Display the values in ascending order
	void displayAsc(BTNode* node);
	//Deletes a value
	bool deleteValue(BTNode* &node, ItemType item);

public:

	//Default Constructors
	BST();
	~BST();
	
	//ADD IN MORE OPERATIONS IF REQUIRED.
	//FOR MAIN FUNCTIONALITIES

	//Inserts a BTNode into the BST
	void insert(ItemType item);
	//Populate AVL BT by SUM of Nodes be larger or equal to Parameter at minimum
	void populateAVLBT(int sum);
	//Search for the BTNode based on item
	void search(ItemType item);
	//Deletes the BTNode based on item
	void deleteValue(ItemType item);
	//Display all items in Ascending order
	void displayAsc();
	//Display the kth node
	void displayKNode(int kNode);
	//Display the Binary Tree
	void displayBT();
};