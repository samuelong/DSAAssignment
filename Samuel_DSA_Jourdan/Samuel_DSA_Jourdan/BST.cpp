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
	// Check for Empty
	if (root == nullptr)
	{
		return "Tree is Empty";
	}
	else if (node != nullptr)
	{
		// Check for Root Item
		if (node == root)
		{
			if (root->item == item)
			{
				return "Root";
			}
		}
		string str = "";
		// Found. Adds "<- Path to Value" at the End of the string
		if (node->item == item)
		{
			return "<- Path to Value";
		}
		//Adds string onto Left / Right Route.
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
		// Not Found
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
	//Creates a Node when Leaf is Empty
	if (node == nullptr)
	{
		node = new BTNode();
		node->item = item;
		//Checks for Root
		if (root == nullptr)
		{
			root = node;
		}
		return node;
	}
	else
	{
		//Compare Values. Calls this method to traverse Left / Right
		BTNode* temp;
		if (item < node->item)
		{
			temp = avlAdd(node->left, item);
			avlRotate(node);
			return temp;
		}
		//Ensures Unique value in tree.
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
	BTNode* nodeC = node->right;
	node->right = nodeC->left;
	nodeC->left = node;
	node = nodeC;
}

void BST::rotateRight(BTNode* &node)
{
	BTNode* nodeC = node->left;
	node->left = nodeC->right;
	nodeC->right = node;
	node = nodeC;
}

void BST::rotateLeftRight(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->left;
	rotateLeft(nodeC);
	temp->left = nodeC;
	rotateRight(node);
}

void BST::rotateRightLeft(BTNode* &node)
{
	BTNode* temp = node;
	BTNode* nodeC = temp->right;
	rotateRight(nodeC);
	temp->right = nodeC;
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
				// Node is nullptr. Adds Empty Child Nodes to Queue.
				if (ptr->item == NULL)
				{
					tempQ->enqueue(new BTNode());
					tempQ->enqueue(new BTNode());
				}
				else
				{
					// Adds Empty Child Node if Child is Empty.
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
				//Creates the Main Queue
				tempQ->dequeue(ptr);
				q->enqueue(ptr);
			}
		}
		//Clears memory. Returns Main Queue.
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

		//Displays Root Level
		//Display Spaces Required at start
		displaySpaces(((space / 2) - 0.5)*2);
		BTNode* temp = nullptr;
		q->getFront(temp);
		//Displays the Leaf. Empty results in ***
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
			//Display Spaces Required at start
			displaySpaces(((space / 2) - 0.5)*2);

			//Number of Nodes per Level
			for (int n = 0; n < pow(2, h-i-1); n++ )
			{
				//Item in Node
				q->getFront(temp);
				//Displays the Leaf. Empty results in ***
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
	//For each integer no, 3 spaces will be added.
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
		cout << "Tree is empty\n";
	}
}

bool BST::deleteValue(BTNode* &node, ItemType item)
{
	if (search(node, item) != "")
	{

		if (node->item == item) // check to see if it's a root
		{
			BTNode* deleteNode = node;
			if (node->left == nullptr && node->right == nullptr) // leaf
			{
				delete node;
				node = nullptr;
			}

			else if (node->left != nullptr && node->right == nullptr) // one child (left)
			{
				node = node->left;
				delete deleteNode;
				avlRotate(node);
			}

			else if (node->left == nullptr && node->right != nullptr) // one child (right)
			{
				node = node->right;
				delete deleteNode;
				avlRotate(node);
			}

			else // two children
			{
				BTNode* successorNode = deleteNode->left;
				while (successorNode->right != nullptr)
				{
					successorNode = successorNode->right;
				}
				int valueSuccessor = successorNode->item;
				deleteValue(node, valueSuccessor);
				deleteNode->item = valueSuccessor;
				avlRotate(node);
			}
		}
		else // node to delete is not a root
		{
			if (node->item > item) // check to see if target is to the left
			{
				if (node->left->item == item) // if node->left is the targer
				{
					BTNode* deleteNode = node->left;
					if (deleteNode->left == nullptr && deleteNode->right == nullptr) // leaf
					{
						node->left = nullptr;
						delete deleteNode;
					}

					else if (deleteNode->left != nullptr && deleteNode->right == nullptr) // one child (left)
					{
						node->left = node->left->left;
						delete deleteNode;
						avlRotate(node->left);
					}

					else if (deleteNode->left == nullptr && deleteNode->right != nullptr) // one child (right)
					{
						node->left = node->left->right;
						delete deleteNode;
						avlRotate(node->left);
					}

					else // two children
					{
						BTNode* successorNode = deleteNode->left;
						while (successorNode->right != nullptr)
						{
							successorNode = successorNode->right;
						}
						int valueSuccessor = successorNode->item;
						deleteValue(node->left, valueSuccessor);
						deleteNode->item = valueSuccessor;
						avlRotate(node->left);
					}

				}

				else // recursive to the left (if node->left is not target)
				{
					deleteValue(node->left, item);
				}
			}

			else // node is to the right
			{
				if (node->right->item == item) // if node->right is the target
				{
					BTNode* deleteNode = node->right;
					if (deleteNode->left == nullptr && deleteNode->right == nullptr) // leaf
					{
						node->right = nullptr;
						delete deleteNode;
					}

					else if (deleteNode->left != nullptr && deleteNode->right == nullptr) // one child (left)
					{
						node->right = node->right->left;
						delete deleteNode;
						avlRotate(node->right);
					}

					else if (deleteNode->left == nullptr && deleteNode->right != nullptr) // one child (right)
					{
						node->right = node->right->right;
						delete deleteNode;
						avlRotate(node->right);
					}

					else // two children
					{
						BTNode* successorNode = deleteNode->left;
						while (successorNode->right != nullptr)
						{
							successorNode = successorNode->right;
						}
						int valueSuccessor = successorNode->item;
						deleteValue(node->right, valueSuccessor);
						deleteNode->item = valueSuccessor;
						avlRotate(node->right);

					}
				}

				else // recursive to the right (if node->right is not target)
				{
					deleteValue(node->right, item);
				}
			}
		}
		avlRotate(node);
		return true;
	}

	else  // if the value isn't found
	{
		std::cout << "Value is not found" << endl;
	}
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

void BST::displayAsc(BTNode* node) // from smallest to biggest (ascending order)
{
	if (node != nullptr) 
	{
		displayAsc(node->left); // recursive to the left
		cout << node->item << endl;
		displayAsc(node->right); // recursive to the right
	}
}

void BST::displayKNode(int kNode) 
{
	Queue* testQueue = new Queue();
	Queue* finalQueue = new Queue();
	int count = 0; // used to check the max amount of nodes in a queue (so if node isn't found, won't crash)

	if (root == nullptr)
	{
		std::cout << "Tree is empty\n";
	}
	else
	{
		testQueue->enqueue(root); // starts by adding node
		while (testQueue->isEmpty() == false)
		{
			BTNode* node = nullptr;
			testQueue->dequeue(node); // dequeue the node and store it
			finalQueue->enqueue(node); // enqueue the node into anothe queue (this queue saves every node)
			count++; // adds one to count after every enqueue in finalQueue

			// enqueue left child
			if (node->left != nullptr) // dequeued node's left
			{
				testQueue->enqueue(node->left);
			}

			// enqueue right child
			if (node->right != nullptr) // dequeued node's right
			{
				testQueue->enqueue(node->right);
			}
		}

		BTNode* value = nullptr;
		if (kNode > count) // check to see if the node index exist
		{
			std::cout << "The node doesn't exist" << endl;
		}

		else  // if it does, check it in the finalQueue (which has every node) --> not testQueue
		{
			for (int i = 0; i <= kNode - 1; i++)
			{
				finalQueue->dequeue(value); // dequeue till the indexed node
			}
			cout << "The value is: " << value->item << endl; // print out the value 
		}
	}
	delete finalQueue; // delete the queues and re-create them
	delete testQueue;
}