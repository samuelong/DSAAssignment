// Samuel_DSA_Jourdan.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "BST.h"
#include "Queue.h"


void setIntVar(int &var, string output)
{
	std::cin >> var;
	while (std::cin.fail())
	{
		std::cout << output;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> var;
	}
}

int main()
{
	std::cout << "Welcome to the Binary Search Tree Creator Application\n";
	std::cout << "Please provide a positive number for the creation of the BST: ";
	int num;
	setIntVar(num, "Invalid input. Please provide a proper input value (Integer)\nInput:");
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
		std::cout << "5: Display the value in a specific Node by index using Level By Level Traversal\n";
		std::cout << "6: Display the Binary Tree\n";
		std::cout << "0: Exit\n";
		std::cout << "Input: ";
		setIntVar(choice, "Invalid input. Please provide an Integer\nInput: ");
		int value;
		switch (choice)
		{
		case 1:
			std::cout << "Provide a value to search :";
			setIntVar(value, "Invalid input. Please provide an Integer\nInput:");
			if (myBST.search(value))
			{
				std::cout << "Value found in Binary Tree\n";
			}
			else
			{
				std::cout << "Value not found in Binary Tree\n";
			}
			break;
		case 2:
			std::cout << "Provide a value to be added :";
			setIntVar(value, "Invalid input. Please provide an Integer\nInput:");
			myBST.insert(value);
			break;
		case 3:
			int nodeDelete;
			std::cout << "Enter value to be deleted: ";
			setIntVar(nodeDelete, "Invalid input. Please provide an Integer\nInput:");
			myBST.deleteValue(nodeDelete);
			break;
		case 4:
			myBST.displayAsc();
			break;
		case 5:
			int nodeIndex;
			std::cout << "Enter your index: ";
			setIntVar(nodeIndex, "Invalid input. Please provide an index(Integer)\nInput:");
			myBST.displayKNode(nodeIndex);
			break;
		case 6:
			myBST.displayBT();
			break;
		case 0:
			break;
		default:
			std::cout << "Please provide a valid input that is indicated";
			choice = -1;
			break;
		}
	}
    return 0;
}