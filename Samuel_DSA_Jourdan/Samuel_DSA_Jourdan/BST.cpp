#include "stdafx.h"
#include "BST.h"
#include <iostream>

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
	}}

bool BST::search(ItemType item)
{
	if (search(root, item) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

BTNode* BST::search(BTNode* node, ItemType item)
{
	if (node != nullptr)
	{
		if (item == node->item)
		{
			return node;
		}
		if (item < node->item)
		{
			return search(node->left, item);
		}
		else
		{
			return search(node->right, item);
		}
	}
	return nullptr;
}

void BST::insert(ItemType item)
{
	avlAdd(root, item);
}

BTNode* BST::avlAdd(BTNode* &node, ItemType item)
{
	if (node == nullptr)
	{
		node = new BTNode();
		node->item = item;
		if (root == nullptr)
		{
			root = node;
		}
		return node;
	}
	else
	{
		BTNode* temp;
		if (item < node->item)
		{
			temp = avlAdd(node->left, item);
			node = avlRotate(node);
			return temp;
		}
		else if (item == node->item)
		{
			return nullptr;
		}
		else
		{
			temp = avlAdd(node->right, item);
			node = avlRotate(node);
			return temp;
		}
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

BTNode* BST::avlRotate(BTNode* node)
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

BTNode* BST::rotateLeft(BTNode* node)
{
	BTNode* nodeC = node->right;
	node->right = nodeC->left;
	nodeC->left = node;
	return nodeC;
}

BTNode* BST::rotateRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = nodeC->right;
	nodeC->right = node;
	return nodeC;
}

BTNode* BST::rotateLeftRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = rotateLeft(nodeC);
	return rotateRight(node);
}

BTNode* BST::rotateRightLeft(BTNode* node)
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
	Queue* q = new Queue();
	Queue* tempQ = new Queue();
	BTNode* ptr = node;
	if (node != nullptr)
	{
		q->enqueue(ptr);
		// Loop through level 1 to the end
		for (int h = 1; h < getHeight(node); h++)
		{
			// Number of nodes in a height
			for (int n = 0; n < pow(2, h); n++)
			{
				// Node is nullptr, resulting in left and right child to be null;
				if (ptr->item == NULL)
				{
					tempQ->enqueue(new BTNode());
					tempQ->enqueue(new BTNode());
				}
				else
				{
					if (ptr->left != nullptr)
					{
						tempQ->enqueue(ptr->left);
					}
					else
					{
						tempQ->enqueue(new BTNode());
					}
					if (ptr->right != nullptr)
					{
						tempQ->enqueue(ptr->right);
					}
					else
					{
						tempQ->enqueue(new BTNode());
					}
				}
				tempQ->dequeue(ptr);
				q->enqueue(ptr);
			}
		}
		delete tempQ;
		return q;
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
		double space = pow(2, h-1);

		//Top level
		displaySpaces(((space / 2) - 0.5)*2);
		BTNode* temp = nullptr;
		q->getFront(temp);
		if (temp->item != NULL)
		{
			std::cout << std::setw(3) << std::setfill('*') << left << temp->item;
			q->dequeue(temp);
		}
		else
		{
			std::cout << std::setw(3) << std::setfill('*') << left << "";
			q->deleteItem();
		}
		displaySpaces(((space / 2) - 0.5)*2);
		std::cout << std::endl;

		//Every other level
		for (int i = h-2; i >= 0; i--)
		{
			space = pow(2, i);
			//Left Spaces
			displaySpaces(((space / 2) - 0.5)*2);

			//Number of Nodes per Level
			for (int n = 0; n < pow(2, h-i-1); n++ )
			{
				//Item in Node
				q->getFront(temp);
				if (temp->item != NULL)
				{
					std::cout << std::setw(3) << std::setfill('*') << left << temp->item;
					q->dequeue(temp);
				}
				else
				{
					std::cout << std::setw(3) << std::setfill('*') << left << "";
					q->deleteItem();
				}
				//Spaces in between Nodes
				displaySpaces(space*2-0.5);
			}
			std::cout << endl;
		}
		delete q;
	}
}

void BST::displaySpaces(int no)
{
	for (int i = 0; i < no; i++)
	{
		std::cout << std::setw(3) << std::setfill(' ') << left << " ";
	}
}

bool BST::deleteValue(ItemType item) 
{
	BTNode* currentNode = root;
	BTNode* parentNode = nullptr;
	bool checkLeft = false;
	bool found = false;

	while (!found && currentNode != nullptr)
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
				checkLeft = false;
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
		if (currentNode->right == nullptr && currentNode->left == nullptr)
		{
			//check to see if it's the root node being deleted
			if (currentNode == root)
			{
				delete currentNode;
				return true;
			}

			//not root node and is a left child
			else 
			{
				if (checkLeft)
				{
					parentNode->left = nullptr;
					delete currentNode;
					return true;
				}

				//not root node and is a right child
				else
				{
					parentNode->right = nullptr;
					delete currentNode;
					return true;
				}
			}
		}

		else
		{
			//deleted node has a left child
			if (currentNode->right == nullptr && currentNode->left != nullptr)
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
			else
			{
				if (currentNode->right != nullptr && currentNode->left == nullptr)
				{
					if (checkLeft)
					{
						parentNode->left = currentNode->right;
						delete currentNode;
						return true;
					}

					else
					{
						parentNode->right = currentNode->right;
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
					while (successorNode->right != nullptr)
					{
						successorNode = successorNode->right;
					}
					//store the successor's value
					int valueSuccessor = successorNode->item;
					//remove the successor
					deleteValue(valueSuccessor);
					//replace the value in the successorNode with the currentNode
					currentNode->item = valueSuccessor;
				}
			}
		}
	}
}

void BST::displayAsc() 
{
	displayItemAsc(root);
}

void BST::displayItemAsc(BTNode* node) 
{
	if (node != NULL) 
	{
		displayItemAsc(node->left);
		cout << node->item << endl;
		displayItemAsc(node->right);
	}
}

void BST::displayKNode(int kNode) 
{
	Queue* testQueue = new Queue();
	Queue* finalQueue = new Queue();
	
	if (root == nullptr)
	{
		std::cout << "There is nothing in the tree";
	}

	testQueue->enqueue(root);
	while (testQueue->isEmpty() == false) 
	{
		BTNode* node = NULL;
		testQueue->dequeue(node);
		finalQueue->enqueue(node);

		//Enqueue left child
		if (node->left != nullptr)
		{
			testQueue->enqueue(node->left);
		}

		//Enqueue right child
		if (node->right != nullptr)
		{
			testQueue->enqueue(node->right);
		}
	}

	BTNode* value = NULL;
	for (int i = 0; i <= kNode - 1; i++) 
	{
		finalQueue->dequeue(value);
	}

	cout << "The value is: " << value->item << endl;
}