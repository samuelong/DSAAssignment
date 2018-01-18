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
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

int main()
{
	std::cout << "Welcome to the Binary Search Tree Creator Application\n";
	int num = -1;
	while (num < 0)
	{
		std::cout << "Please provide a positive number for the creation of the BST: ";
		setIntVar(num, "Invalid input. Please provide a proper input value (Integer)\nInput:");
	}
	//Create BST.
	BST myBST = BST();
	myBST.populateAVLBT(num);

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "1: Search for a value\n";
		std::cout << "2: Add a value\n";
		std::cout << "3: Remove a value\n";
		std::cout << "4: Display values in ascending order\n";
		std::cout << "5: Display the node by index (from top to bottom)\n";
		std::cout << "6: Display the Binary Tree\n";
		std::cout << "0: Exit\n";
		std::cout << "Input: ";
		setIntVar(choice, "Invalid input. Please provide an Integer\nInput: ");
		int value;
		switch (choice)
		{
		case 1:
			std::cout << "Provide a value to search: ";
			setIntVar(value, "Invalid input. Please provide an Integer\nInput: ");
			myBST.search(value);
			break;
		case 2:
			std::cout << "Provide a value to be added: ";
			setIntVar(value, "Invalid input. Please provide an Integer\nInput: ");
			myBST.insert(value);
			break;
		case 3:
			int nodeDelete;
			std::cout << "Enter value to be deleted: ";
			setIntVar(nodeDelete, "Invalid input. Please provide an Integer\nInput: ");
			myBST.deleteValue(nodeDelete);
			break;
		case 4:
			myBST.displayAsc();
			break;
		case 5:
			int nodeIndex;
			std::cout << "Enter your index: ";
			setIntVar(nodeIndex, "Invalid input. Please provide an index(Integer)\nInput: ");
			myBST.displayKNode(nodeIndex);
			break;
		case 6:
			myBST.displayBT();
			break;
		case 0:
			break;
		default:
			std::cout << "Please choose one of the options displayed";
			choice = -1;
			break;
		}
	}
    return 0;
}