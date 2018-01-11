#pragma once
//Queue.h - - Specification of Queue ADT (implemented using Pointers)

#include<string>
#include<iostream>
#include "BinaryNode.h"

using namespace std;

class Queue
{
private:
	typedef BTNode ItemType;

	struct Node
	{
		ItemType* item;	// item
		Node     *next;	// pointer pointing to next item
	};

	Node *frontNode;	// point to the first item
	Node *backNode;	// point to the first item


public:
	// constructor
	Queue();

	~Queue();

	// enqueue item at the back of queue
	bool enqueue(ItemType* newItem);

	// dequeue item from front of queue

	bool dequeue();

	// dequeue and retrieve item from front of queue
	bool dequeue(ItemType* item);


	// retrieve item from front of queue
	void getFront(ItemType* item);

	// check if the queue is empty
	bool isEmpty();

};
