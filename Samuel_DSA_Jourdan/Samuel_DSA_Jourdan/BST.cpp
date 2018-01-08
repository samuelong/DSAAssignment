#include "stdafx.h"
#include "BST.h"
#include <minmax.h>
#include <math.h>
#include <iostream>

BST::BST()
{

}

BST::~BST()
{
	//DELETE ALL NODES
}

void BST::PopulateAVLBT(int sum)
{
	int total = 0, current = 1;
	while (true)
	{
		if (total >= sum)
		{
			break;
		}
		total += current;
		AVLAdd(root, current);
		current++;
	}
}

BTNode BST::Search(ItemType item)
{

	return BTNode();
}

BTNode* BST::Add(BTNode* node, ItemType item)
{
	if (node == nullptr)
	{
		node = new BTNode();
		node->item = item;
		return node;
	}
	else
	{
		if (item < node->item)
		{
			return Add(node->left, item);
		}
		else
		{
			return Add(node->right, item);
		}
	}
}

BTNode* BST::AVLAdd(BTNode* node, ItemType item)
{
	if (node == nullptr)
	{
		node = new BTNode();
		node->item = item;
		return node;
	}
	else
	{
		BTNode* temp;
		if (item < node->item)
		{
			temp = Add(node->left, item);
		}
		else
		{
			temp = Add(node->right, item);
		}
		AVLRotate(node);
		return temp;
	}
}

int BST::GetHeight(BTNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(GetHeight(node->left), GetHeight(node->right));
}

bool BST::IsBalance()
{
	if (root != nullptr)
	{
		return IsBalance(root);
	}
}

bool BST::IsBalance(BTNode* node)
{
	if (node != nullptr)
	{
		if (abs(GetHeight(node->left) - GetHeight(node->right)) <= 1)
		{
			return true;
		}
	}
}

int BST::Balance(BTNode* node)
{
	if (node != nullptr)
	{
		return GetHeight(node->right) - GetHeight(node->left);
	}
}

bool BST::AVLRotate(BTNode* node)
{
	int balance = Balance(node);
	//Main Tree - Left Heavy
	if (balance < -1)
	{
		//Left SubTree - Right Heavy
		if (Balance(node->left) > 1)
		{
			RotateLeftRight(node);
		}
		else
		{
			RotateRight(node);
		}
		return true;
	}
	//Main Tree - Right Heavy
	else if (balance > 1)
	{
		//Right SubTree - Left Heavy
		if (Balance(node->right) < -1)
		{
			RotateRightLeft(node);
		}
		else
		{
			RotateLeft(node);
		}
		return true;
	}
	return false;
}

BTNode* BST::RotateLeft(BTNode* node)
{
	BTNode* nodeC = node->right;
	node->right = nodeC->left;
	nodeC->left = node;
	return nodeC;
}

BTNode* BST::RotateRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = nodeC->right;
	nodeC->right = node;
	return nodeC;
}

BTNode* BST::RotateLeftRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = RotateLeft(nodeC);
	return RotateRight(node);
}

BTNode* BST::RotateRightLeft(BTNode* node)
{
	BTNode* nodeC = node->right;
	node->right = RotateRight(nodeC);
	return RotateLeft(node);
}

void BST::DisplayBT()
{
	DisplayBT(root);
}

void BST::DisplayBT(BTNode* node)
{
	if (node != nullptr)
	{
		std::cout << "There is nothing to display"
	}
}