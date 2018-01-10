#include "stdafx.h"
#include "BST.h"

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

void BST::Insert(ItemType item)
{
	AVLAdd(root, item);
}

BTNode* BST::Add(BTNode* &node, ItemType item)
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

BTNode* BST::AVLAdd(BTNode* &node, ItemType item)
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
			temp = Add(node->left, item);
		}
		else
		{
			temp = Add(node->right, item);
		}
		if (node == root)
		{
			root = AVLRotate(node);
		}
		else
		{
			AVLRotate(node);
		}
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

BTNode* BST::AVLRotate(BTNode* node)
{
	int balance = Balance(node);
	//Main Tree - Left Heavy
	if (balance < -1)
	{
		//Left SubTree - Right Heavy
		if (Balance(node->left) > 1)
		{
			return RotateLeftRight(node);
		}
		else
		{
			return RotateRight(node);
		}
	}
	//Main Tree - Right Heavy
	else if (balance > 1)
	{
		//Right SubTree - Left Heavy
		if (Balance(node->right) < -1)
		{
			return RotateRightLeft(node);
		}
		else
		{
			return RotateLeft(node);
		}
	}
}

BTNode* &BST::RotateLeft(BTNode* node)
{
	BTNode* nodeC = node->right;
	node->right = nodeC->left;
	nodeC->left = node;
	return nodeC;
}

BTNode* &BST::RotateRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = nodeC->right;
	nodeC->right = node;
	return nodeC;
}

BTNode* &BST::RotateLeftRight(BTNode* node)
{
	BTNode* nodeC = node->left;
	node->left = RotateLeft(nodeC);
	return RotateRight(node);
}

BTNode* &BST::RotateRightLeft(BTNode* node)
{
	BTNode* nodeC = node->right;
	node->right = RotateRight(nodeC);
	return RotateLeft(node);
}

int BST::CountNode(BTNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(CountNode(node->left), CountNode(node->right));
}

Queue* BST::GetLevelByLevel(BTNode* node)
{
	Queue* q = new Queue();
	Queue tempQ = Queue();
	if (node != nullptr)
	{
		tempQ.enqueue(node);
		q->enqueue(node);
		BTNode* nowNode = node;
		for (int i = 0; i < CountNode(node); i++)
		{
			if (nowNode->left != nullptr)
			{
				q->enqueue(nowNode->left);
				tempQ.enqueue(nowNode->left);
			}
			else
			{
				q->enqueue(nullptr);
			}
			if (nowNode->right != nullptr)
			{
				q->enqueue(nowNode->right);
				tempQ.enqueue(nowNode->right);
			}
			else
			{
				q->enqueue(nullptr);
			}
			tempQ.dequeue(nowNode);
		}
		return q;
	}
}

void BST::DisplayBT()
{
	DisplayBT(root);
}

void BST::DisplayBT(BTNode* node)
{
	if (node != nullptr)
	{
		Queue* q = GetLevelByLevel(node);
		int h = GetHeight(node);
		//Per level
		for (int i = h-1; i >= 0; i++)
		{
			double space = pow(2, i);
			//Left Spaces
			DisplaySpaces((space / 2) - 0.5);

			//Number of Nodes per Level
			for (int n = 0; n < h; n++ )
			{
				//Item in Node
				BTNode* temp = new BTNode();
				q->dequeue(temp);
				if (temp->item != NULL)
				{
					cout << temp->item;
				}
				else
				{
					cout << "--";
				}
				//Spaces in between Nodes
				DisplaySpaces(space);
			}
			cout << endl;
		}
	}
}

void BST::DisplaySpaces(int no)
{
	for (int i = 0; i < no; i++)
	{
		cout << " ";
	}
}

bool BST::Delete(ItemType item) 
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