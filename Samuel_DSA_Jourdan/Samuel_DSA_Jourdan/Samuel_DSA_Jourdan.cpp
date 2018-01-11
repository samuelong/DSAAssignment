// Samuel_DSA_Jourdan.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "BST.h"
#include "Queue.h"


int main()
{
	std::cout << "Welcome to the Binary Search Tree Creator Application\n";
	std::cout << "Please provide a positive number for the creation of the BST: ";
	int num;
	std::cin >> num;
	//Create BST.
	BST myBST = BST();
	myBST.populateAVLBT(num);

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "1: Search for a value\n";
		std::cout << "2: Add a value\n";
		std::cout << "3: Remove a value\n";
		std::cout << "4: Display values in Ascending order\n";
		std::cout << "5: Display the value in a specific Node by index using Level By Level Traversal\n\n";
		std::cout << "6: Display the Binary Tree\n";
		std::cout << "0: Exit\n";
		std::cout << "Input: ";
		std::cin >> choice;
		int value;
		switch (choice)
		{
		case 1:
			cout << "Provide a value to search :";
			cin >> value;
			if (myBST.search(value))
			{
				cout << "Value found in Binary Tree\n";
			}
			else
			{
				cout << "Value not found in Binary Tree\n";
			}
			break;
		case 2:
			cout << "Provide a value to be added :";
			cin >> value;
			myBST.insert(value);
			break;
		case 3:
			int userDelete;
			std::cout << "Enter value to be deleted: ";
			std::cin >> userDelete;
			myBST.deleteValue(userDelete);
			break;
		case 4:
			myBST.displayItemAsc();
			break;
		case 5:
			int userIndex;
			std::cout << "Enter your index: ";
			std::cin >> userIndex;
			myBST.displayKNode(userIndex);
			break;
		case 6:
			myBST.displayBT();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
    return 0;
}