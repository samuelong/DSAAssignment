#include "stdafx.h"
#include "Queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::enqueue(ItemType* newItem)
{
	Node* newNode = new Node();
	newNode->item = newItem;
	newNode->next = nullptr;
	if (isEmpty())
	{
		frontNode = newNode;
	}
	else
	{
		backNode->next = newNode;
	}
	backNode = newNode;
	return true;
}

bool Queue::Delete()
{
	if (!isEmpty())
	{
		Node* tempptr = frontNode;
		if (frontNode == backNode)
		{
			backNode = nullptr;
		}
		frontNode = frontNode->next;
		delete tempptr;
		return true;
	}
	return false;
}

bool Queue::dequeue(ItemType* item)
{
	if (!isEmpty())
	{
		Node* tempptr = frontNode;
		if (frontNode == backNode)
		{
			backNode = nullptr;
		}
		frontNode = frontNode->next;
		item = tempptr->item;
		return true;
	}
	return false;
}

void Queue::getFront(ItemType* item)
{
	if (!isEmpty())
	{
		item = frontNode->item;
	}
}

bool Queue::isEmpty()
{
	if (frontNode == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}