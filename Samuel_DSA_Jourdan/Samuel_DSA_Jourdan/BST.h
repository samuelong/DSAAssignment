#pragma once

struct BTNode
{
	int item;
	BTNode* left;
	BTNode* right;
};

class BST
{
private:
	BTNode* root;

public:
	//Default Constructors
	BST();
	~BST();
	
	//ADD IN MORE OPERATIONS IF REQUIRED. Reduce Coupling and Cohesion.
	//FOR MAIN FUNCTIONALITIES

	//Search for the BTNode based on item
	BTNode Search(int value);
	//Adds a new BTNode into the BT
	bool Add(int value);
	//Deletes the BTNode based on value
	bool Delete(int value);
	//Display all values in Ascending order
	void DisplayValueAsc();
	//Returns the BTNode by Index
	BTNode GetNode(int nodeIndex);

	//FOR AVL TREE

	//Check if Root Node is balanced
	bool IsBalance();
	//Check if Node is balanced
	bool IsBalance(BTNode node);
	//RotateLeft
	BTNode RotateLeft(BTNode node);
	//RotateRight
	BTNode RotateRight(BTNode node);
	//RotateLeft-Right
	BTNode RotateLeftRight(BTNode node);
	//RotateRight-Left
	BTNode RotateRightLeft(BTNode node);
};