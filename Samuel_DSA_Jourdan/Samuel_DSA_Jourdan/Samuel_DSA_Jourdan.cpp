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
	myBST.PopulateAVLBT(30);

	while (true)
	{
		system("CLS");
		std::cout << "1: Search for a value\n";
		std::cout << "2: Add a value\n";
		std::cout << "3: Remove a value\n";
		std::cout << "4: Display values in Ascending order\n";
		std::cout << "5: Display the value in a specific Node by index using Level By Level Traversal\n\n";
		std::cout << "0: Exit";
		std::cout << "Input: ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			myBST.DisplayBT();
			break;
		case 2:
			myBST.Insert(500);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			
		default:
			break;
		}
	}
    return 0;
}