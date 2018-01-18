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

void BST::search(ItemType item)
{
	string str = search(root, item);
	if (str == "")
	{
		cout << "Value not found in Binary Tree\n";
	}
	else
	{
		cout << str << endl;
	}
}

string BST::search(BTNode* node, ItemType item)
{
	if (node == root)
	{
		if (root->item == item)
		{
			return "Root";
		}
	}
	if (root == nullptr)
	{
		return "Tree is Empty";
	}
	else if (node != nullptr)
	{
		string str = "";
		if (node->item == item)
		{
			return "<- Path to Value";
		}
		else if (node->item < item)
		{
			str = search(node->right, item);
			if (str != "")
			{
				str = "R|" + str;
			}
		}
		else
		{
			str = search(node->left, item);
			if (str != "")
			{
				str = "L|" + str;
			}
		}
		if (str == "")
		{
			return "";
		}
		else
		{
			return str;
		}
	}
	else
	{
		return "";
	}
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

int BST::balance(BTNode* node)
{
	if (node != nullptr)
	{
		return getHeight(node->right) - getHeight(node->left);
	}
	return NULL;
}

BTNode* BST::avlRotate(BTNode* node)
{
	int balance = BST::balance(node);
	//Main Tree - Left Heavy
	if (balance < -1)
	{
		balance = BST::balance(node->left);
		//Left SubTree - Right Heavy
		if (balance >= 1)
		{
			return rotateLeftRight(node);
		}
		//Left SubTree - Left Heavy
		else
		{
			return rotateRight(node);
		}
	}
	//Main Tree - Right Heavy
	else if (balance > 1)
	{
		balance = BST::balance(node->right);
		//Right SubTree - Left Heavy
		if (balance <= -1)
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
	return nullptr;
}

void BST::displayBT()
{
	if (root == nullptr)
	{
		cout << "Tree is empty\n";
	}
	else
	{
		displayBT(root);
	}
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

void BST::deleteValue(ItemType item) 
{
	if (root != nullptr)
	{
		deleteValue(root, item);
	}
	else
	{
		cout << "Tree is Empty\n";
	}
}

bool BST::deleteValue(BTNode* &node, ItemType item)
{
	if (node->item == item) // check to see if it's a root
	{
		BTNode* deleteNode = node;
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
			}

			else if (node->left != nullptr && node->right == nullptr)
			{
				node = node->left;
				delete deleteNode;
				node = avlRotate(node);
			}

			else if (node->left == nullptr && node->right != nullptr)
			{
				node = node->right;
				delete deleteNode;
				node = avlRotate(node);
			}

			else
			{
				BTNode* successorNode = deleteNode->left;
				while (successorNode->right != nullptr)
				{
					successorNode = successorNode->right;
				}
				int valueSuccessor = successorNode->item;
				deleteValue(deleteNode, valueSuccessor);
				deleteNode->item = valueSuccessor;
				node = avlRotate(node);
			}
	}
	else 
	{
		if (node->item > item)
		{
			if (node->left->item == item)
			{
				BTNode* deleteNode = node->left;
				if (deleteNode->left == nullptr && deleteNode->right == nullptr)
				{
					node->left = nullptr;
					delete deleteNode;
				}

				else if (deleteNode->left != nullptr && deleteNode->right == nullptr)
				{
					node->left = node->left->left;
					delete deleteNode;
					node->left = avlRotate(node->left);
				}

				else if (deleteNode->left == nullptr && deleteNode->right != nullptr)
				{
					node->left = node->left->right;
					delete deleteNode;
					node->left = avlRotate(node->left);
				}

				else
				{
					BTNode* successorNode = deleteNode->left;
					while (successorNode->right != nullptr)
					{
						successorNode = successorNode->right;
					}
					int valueSuccessor = successorNode->item;
					deleteValue(deleteNode, valueSuccessor);
					deleteNode->item = valueSuccessor;
					node->left = avlRotate(node->left);
				}
				
			}

			else
			{
				deleteValue(node->left, item);
			}
		}

		else
		{
			if (node->right->item == item)
			{
				BTNode* deleteNode = node->right;
				if (deleteNode->left == nullptr && deleteNode->right == nullptr)
				{
					node->right = nullptr;
					delete deleteNode;
				}

				else if (deleteNode->left != nullptr && deleteNode->right == nullptr)
				{
					node->right = node->right->left;
					delete deleteNode;
					node->right = avlRotate(node->right);
				}

				else if (deleteNode->left == nullptr && deleteNode->right != nullptr)
				{
					node->right = node->right->right;
					delete deleteNode;
					node->right = avlRotate(node->right);
				}

				else
				{
					BTNode* successorNode = deleteNode->left;
					while (successorNode->right != nullptr)
					{
						successorNode = successorNode->right;
					}
					int valueSuccessor = successorNode->item;
					deleteValue(deleteNode, valueSuccessor);
					deleteNode->item = valueSuccessor;
					node->right = avlRotate(node->right);
				}
				
			}

			else
			{
				deleteValue(node->right, item);
			}
		}
	}
	node = avlRotate(node);
	return true;
}

void BST::displayAsc() 
{
	if (root == nullptr)
	{
		cout << "Tree is empty\n";
	}
	else
	{
		displayAsc(root);
	}
}

void BST::displayAsc(BTNode* node) 
{
	if (node != nullptr) 
	{
		displayAsc(node->left);
		cout << node->item << endl;
		displayAsc(node->right);
	}
}

void BST::displayKNode(int kNode) 
{
	Queue* testQueue = new Queue();
	Queue* finalQueue = new Queue();
	
	if (root == nullptr)
	{
		std::cout << "Tree is empty\n";
	}
	else
	{
		testQueue->enqueue(root);
		while (testQueue->isEmpty() == false)
		{
			BTNode* node = nullptr;
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

		BTNode* value = nullptr;
		for (int i = 0; i <= kNode - 1; i++)
		{
			finalQueue->dequeue(value);
		}

		cout << "The value is: " << value->item << endl;
	}
	delete finalQueue;
	delete testQueue;
}