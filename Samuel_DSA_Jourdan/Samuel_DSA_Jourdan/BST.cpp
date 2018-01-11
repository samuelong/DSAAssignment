#include "stdafx.h"
#include "BST.h"

BST::BST()
{

}

BST::~BST()
{
	//DELETE ALL NODES
}

void BST::populateAVLBT(int sum)
{
	int total = 0, current = 1;
	while (true)
	{
		if (total >= sum)
		{
			break;
		}
		total += current;
		avlAdd(root, current);
		current++;
	}
}

BTNode BST::search(ItemType item)
{

	return BTNode();
}

void BST::insert(ItemType item)
{
	avlAdd(root, item);
}

BTNode* BST::add(BTNode* &node, ItemType item)
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
			return add(node->left, item);
		}
		else
		{
			return add(node->right, item);
		}
	}
}

BTNode* BST::avlAdd(BTNode* &node, ItemType item)
{
	if (node == nullptr)
	{
		node = new BTNode();
		node->item = item;
		root = node;
		return node;
	}
	else
	{
		BTNode* temp;
		if (item < node->item)
		{
			temp = add(node->left, item);
		}
		else
		{
			temp = add(node->right, item);
		}
		if (node == root)
		{
			root = avlRotate(node);
		}
		else
		{
			avlRotate(node);
		}
		return temp;
	}
}

int BST::getHeight(BTNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

bool BST::isBalance()
{
	if (root != nullptr)
	{
		return isBalance(root);
	}
}

bool BST::isBalance(BTNode* node)
{
	if (node != nullptr)
	{
		if (abs(getHeight(node->left) - getHeight(node->right)) <= 1)
		{
			return true;
		}
	}
}

int BST::balance(BTNode* node)
{
	if (node != nullptr)
	{
		return getHeight(node->right) - getHeight(node->left);
	}
}

BTNode* BST::avlRotate(BTNode* &node)
{
	int balance = BST::balance(node);
	//Main Tree - Left Heavy
	if (balance < -1)
	{
		//Left SubTree - Right Heavy
		if (BST::balance(node->left) > 1)
		{
			return rotateLeftRight(node);
		}
		else
		{
			return rotateRight(node);
		}
	}
	//Main Tree - Right Heavy
	else if (balance > 1)
	{
		//Right SubTree - Left Heavy
		if (BST::balance(node->right) < -1)
		{
			return rotateRightLeft(node);
		}
		else
		{
			return rotateLeft(node);
		}
	}
	return node;
}

BTNode* &BST::rotateLeft(BTNode* &node)
{
	BTNode* nodeC = node->right;
	node->right = nodeC->left;
	nodeC->left = node;
	return nodeC;
}

BTNode* &BST::rotateRight(BTNode* &node)
{
	BTNode* nodeC = node->left;
	node->left = nodeC->right;
	nodeC->right = node;
	return nodeC;
}

BTNode* &BST::rotateLeftRight(BTNode* &node)
{
	BTNode* nodeC = node->left;
	node->left = rotateLeft(nodeC);
	return rotateRight(node);
}

BTNode* &BST::rotateRightLeft(BTNode* &node)
{
	BTNode* nodeC = node->right;
	node->right = rotateRight(nodeC);
	return rotateLeft(node);
}

int BST::countNode(BTNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(countNode(node->left), countNode(node->right));
}

Queue* BST::getLevelByLevel(BTNode* node)
{
	Queue q = Queue();
	Queue tempQ = Queue();
	Queue tempQ2 = Queue();
	BTNode* ptr = node;
	if (node != nullptr)
	{
		tempQ2.enqueue(node);
	}
	for (int h = 1; h < getHeight(node); h++)
	{
		tempQ = tempQ2;
		do
		{
			if (ptr != nullptr)
			{
				if (ptr->left != nullptr)
				{
					tempQ2.enqueue(ptr->left);
				}
				else
				{
					tempQ2.enqueue()
				}
			}
			else
			{
				tempQ2.enqueue()
			}
		} while (!tempQ.isEmpty());
	}
}

void BST::displayBT()
{
	displayBT(root);
}

void BST::displayBT(BTNode* node)
{
	if (node != nullptr)
	{
		Queue* q = getLevelByLevel(node);
		int h = getHeight(node);
		//Per level
		for (int i = h-1; i >= 0; i++)
		{
			double space = pow(2, i);
			//Left Spaces
			displaySpaces((space / 2) - 0.5);

			//Number of Nodes per Level
			for (int n = 0; n < h; n++ )
			{
				//Item in Node
				BTNode* temp = new BTNode();
				q->dequeue(temp);
				if (temp->item != NULL)
				{
					std::cout << temp->item;
				}
				else
				{
					std::cout << "--";
				}
				//Spaces in between Nodes
				displaySpaces(space);
			}
			std::cout << endl;
		}
	}
}

void BST::displaySpaces(int no)
{
	for (int i = 0; i < no; i++)
	{
		std::cout << " ";
	}
}

bool BST::deleteValue(ItemType item) 
{
	BTNode *currentNode = root;
	BTNode *parentNode = NULL;
	bool checkLeft = false;
	bool found = false;

	while (!found && currentNode != NULL)
	{
		if (item == currentNode->item) 
		{
			found = true;
		}

		else 
		{
			parentNode = currentNode;
			if (item > currentNode->item) 
			{
				currentNode = currentNode->right;
			}

			else 
			{
				currentNode = currentNode->left;
				checkLeft = true;
			}
		}
	}

	if (found) 
	{
		//if the deleted node has no children
		if (currentNode->right == NULL && currentNode->left == NULL) 
		{
			//check to see if it's the root node being deleted
			if (currentNode == root) 
			{
				delete currentNode;
				return true;
			}

			//not root node and is a left child
			else if (checkLeft) 
			{
				parentNode->left = NULL;
				delete currentNode;
				return true;
			}

			//not root node and is a right child
			else 
			{
				parentNode->right = NULL;
				delete currentNode;
				return true;
			}
		}

		else 
		{
			//deleted node has a left child
			if (currentNode->right == NULL && currentNode->left != NULL) 
			{
				//is deleted node a left child?
				if (checkLeft) 
				{
					parentNode->left = currentNode->left;
					delete currentNode;
					return true;
				}

				else 
				{
					parentNode->right = currentNode->left;
					delete currentNode;
					return true;
				}
			}

			//deleted node has a right child
			else if (currentNode->right != NULL && currentNode->left == NULL) 
			{
				if (checkLeft)
				{
					parentNode->left = currentNode->right;
					delete currentNode;
					return true;
				}

				else 
				{
					parentNode->right = currentNode->left;
					delete currentNode;
					return true;
				}
			}

			//deleted node has two children
			else 
			{
				//successor
				//go all the way to the currentNode's left
				BTNode* successorNode = currentNode->left;
				while (successorNode->right != NULL) 
				{
					successorNode = successorNode->right;
				}
				//store the successor's value
				int valueSuccessor = successorNode->item;
				//remove the successor
				delete successorNode;
				//replace the value in the successorNode with the currentNode
				currentNode->item = valueSuccessor;
			}
		}
	}
}

