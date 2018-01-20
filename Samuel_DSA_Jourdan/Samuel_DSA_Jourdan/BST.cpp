/* Group NoIdea
Samuel Ong S10171663K
Jourdan Lim S10166869D
*/
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
		// Compare Total with Sum to stop
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
	if (root == nullptr)
	{
		return "Tree is Empty";
	}
	else if (node != nullptr)
	{
		if (node == root)
		{
			if (root->item == item)
			{
				return "Root";
			}
		}
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
	if (avlAdd(root, item) == nullptr)
	{
		cout << "Unable to add value as it already exists\n";
	}
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
			avlRotate(node);
			return temp;
		}
		else if (item == node->item)
		{
			return nullptr;
		}
		else
		{
			temp = avlAdd(node->right, item);
			avlRotate(node);
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

void BST::avlRotate(BTNode* &node)
{
	int balance = BST::balance(node);
	//Main Tree - Left Heavy
	if (balance < -1)
	{
		balance = BST::balance(node->left);
		//Left SubTree - Right Heavy
		if (balance >= 1)
		{
			rotateLeftRight(node);
		}
		//Left SubTree - Left Heavy
		else
		{
			rotateRight(node);
		}
	}
	//Main Tree - Right Heavy
	else if (balance > 1)
	{
		balance = BST::balance(node->right);
		//Right SubTree - Left Heavy
		if (balance <= -1)
		{
			rotateRightLeft(node);
		}
		else
		{
			rotateLeft(node);
		}
	}
}

void BST::rotateLeft(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->right;
	temp->right = nodeC->left;
	nodeC->left = temp;
	node = nodeC;
}

void BST::rotateRight(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->left;
	temp->left = nodeC->right;
	nodeC->right = temp;
	node = nodeC;
}

void BST::rotateLeftRight(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->left;
	rotateLeft(nodeC);
	temp->left = nodeC;
	node = nodeC;
	rotateRight(node);
}

void BST::rotateRightLeft(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->right;
	rotateRight(nodeC);
	temp->right = nodeC;
	node = nodeC;
	rotateLeft(node);
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
	// search for the node to be deleted
	BTNode* current = node;
	BTNode* parent = NULL;
	bool isLeftChild = false;
	bool found = false;
	while ((!found) && (current != NULL))
	{
		if (item == current->item)
		{
			found = true;
		}
		else
		{
			parent = current;
			if (item < current->item)
			{
				current = current->left; // go to left subtree
				isLeftChild = true;
			}
			else
			{
				current = current->right; // go to right subtree
				isLeftChild = false;
			}
		}
	}
	// node found
	if (found)
	{
		// node is a leaf
		if (current->left == NULL && current->right == NULL)
		{
			if (current == node) // node to be deleted is a root
				node = NULL;
			else
				if (isLeftChild)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		// node has 1 children
		else if (current->left == NULL)
		{
			if (current == root)
				node = node->right;
			else if (isLeftChild)
				parent->left = current->right;
			else
				parent->right = current->right;;
		}
		else if (current->right == NULL)
		{
			if (current == root)
				node = node->left;
			else if (isLeftChild)
				parent->left = current->left;
			else
				parent->right = current->left;;
		}
		// node has 2 children
		else
		{
			// find the successor
			BTNode* successor = current->left;
			while (successor->right != NULL)
				successor = successor->right;
			// replace the node’s item with that of the successor
			int n = successor->item;
			// delete the successor (either case 1 or case 2)
			deleteValue(node, item);
			// replace the node’s item with that of the successor
			current->item = n;
		}
		// balance the tree
		cout << node->item << endl;
		balance(parent);
		balance(node);
		balance(node->left);
		balance(node->right);
	}
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
	int count = 0;

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
			count++;

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
		if (kNode > count) 
		{
			std::cout << "The node doesn't exist" << endl;
		}

		else 
		{
			for (int i = 0; i <= kNode - 1; i++)
			{
				finalQueue->dequeue(value);
			}
			cout << "The value is: " << value->item << endl;
		}
	}
	delete finalQueue;
	delete testQueue;
}