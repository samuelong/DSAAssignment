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
		std::cout << "0: Exit\n";
		std::cout << "Input: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			myBST.displayBT();
			break;
		case 2:
			myBST.insert(500);
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
		case 0:
			break;
		default:
			break;
		}
	}
    return 0;
}