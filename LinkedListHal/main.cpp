//
//  main.cpp
//  linkedlist
//
//  Created by Hal O'Connell on 2012-10-29.
//  Copyright (c) 2012 Hal O'Connell. All rights reserved.
//
//#include "stdafx.h"
#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node *next;

	Node() : next(NULL), data(-1) {}
};

class LinkedList
{
private:
	Node *first;

public:
	LinkedList() : first(NULL) {}

	virtual ~LinkedList()
	{
		Node *node = first;

		while (node != NULL)
		{
			Node *temp = node;

			node = node->next;

			delete temp;
		}
	}

	void Add(int num)
	{
		Node *node = new Node();
		node->data = num;

		if (first == NULL)
		{
			first = node;
		}
		else
		{
			Node *currNode = first;
			Node *prevNode = NULL;

			while (currNode != NULL)
			{
				prevNode = currNode;
				currNode = currNode->next;
			}

			if (prevNode != NULL)
			{
				prevNode->next = node;
			}
		}
	}

	void DeleteValue(int value)
	{
		Node *node = first;
		Node *prev = NULL;

		while (node != NULL)
		{
			if (node->data == value)
			{
				break;
			}

			prev = node;
			node = node->next;
		}

		if (node != NULL)
		{
			if (node == first)
			{
				first = node->next;
			}
			else
			{
				prev->next = node->next;
			}

			delete node;
		}
	}

	void DeleteNode(int nodenum)
	{
		int index = -1;

		Node *node = first;
		Node *prev = NULL;

		while (node != NULL)
		{
			index++;

			if (index == nodenum)
			{
				break;
			}

			prev = node;
			node = node->next;
		}

		if (index >= 0)
		{
			if (node == first)
			{
				first = node->next;
			}
			else
			{
				prev->next = node->next;
			}

			delete node;
		}
	}

	void InsertAfterValue(int value, int num)
	{
		Node *node = new Node();
		node->data = num;

		// search for node to insert after
		Node *prev = first;

		while (prev != NULL)
		{
			if (prev->data == value)
			{
				break;
			}

			prev = prev->next;
		}

		// insert node into list
		if (first == NULL)
		{
			first = node;
		}
		else
		{
			if (prev != NULL)
			{
				node->next = prev->next;
				prev->next = node;
			}
			else
			{
				// could not find the node to insert after
				// so defaulting to Add function
				Add(num);
			}
		}
	}

	friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list)
{
	Node *currNode = list.first;

	while (currNode != NULL)
	{
		output << "data = " << currNode->data << endl;

		currNode = currNode->next;
	}

	return output;
}


int main()
{
	// test 1: adding new nodes

	LinkedList list;

	list.Add(3);
	list.Add(5);
	list.Add(1);
	list.Add(7);
	list.Add(9);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	// test 2: delete a node

	cout << "\nDeleting...." << endl;

	list.DeleteValue(1);
	list.DeleteNode(2);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	// test 3: insert a node

	cout << "\nInserting...." << endl;

	// tests to insert after valid node
	list.InsertAfterValue(3, 10);
	// test to insert after non-existent node
	list.InsertAfterValue(11, 12);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	return 0;
}

















