// Hashing Algorithum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
	//private does not access by main function

	int data;
	Node *next;
	Node *prev;

	Node(int value) {

		data = value;
		next =prev= NULL;
	}
};

// wrapper class of Node class here we will defined all the function etc

class LinkedList {

public:
	Node *head;
	Node *tail;
	LinkedList() {

		head =tail= NULL;
	}

	void InserstData(int value);
	Node *Search(int val);
	void delte(int val);
	void Display();
};
Node* LinkedList::Search(int val)
{
	Node *ptr = head;
	while (ptr!=NULL)
	{
		if (ptr->data == val)
		{
			cout << "Value is found\n";
			return ptr;
			break;
		}
		ptr = ptr->next;

	}
}
void LinkedList::delte(int val)
{
	Node *find=Search(val);
	if (find == head)
	{
		head = head->next;
		find->next = NULL;
		head->prev = NULL;
		delete find;
	}
	else if (find == tail)
	{
		tail = tail->prev;
		tail->next = NULL;
		delete find;
	}
	else
	{
		find->next->prev = find->prev;
		find->prev->next = find->next;
		find->next = NULL;
		find->prev = NULL;
		delete find;
	}
}
void LinkedList::InserstData(int value)
{
	// create a node first
	// make a pointer and called it like a constructor

	Node *mynode = new Node(value); // make temporary object

	if (head == NULL) {

		head =tail= mynode;
	}
	else {
		tail->next = mynode;
		mynode->prev = tail;
		tail = mynode;
	}


}
void LinkedList::Display() {


		Node *ptr = head;
		while (ptr != NULL) {

			cout << " --> " << ptr->data;
			ptr = ptr->next;


		}
}


class Hashing
{
public:
	int sizeHashTable; 
	LinkedList *Table;
	Hashing(int size)
	{
		sizeHashTable = size;
		Table = new LinkedList[sizeHashTable];

	}
	int HashFunction(int val);
	void insert_data(int val);
	void delete_Content(int val);
	void Display_Table_Content();

};
int Hashing::HashFunction(int key)
{
	if (key < 0)
	{
		return 0;
	}
	else
	{
		return key % this->sizeHashTable;
	}
}
void Hashing::insert_data(int val)
{
	int index = this->HashFunction(val); // maping 


	this->Table[index].InserstData(val); // inserting data into Hash table  
}
void Hashing::delete_Content(int val)
{
	int index = HashFunction(val);
	Table[index].delte(val);
}
void Hashing::Display_Table_Content()
{
	for (int i = 0; i < this->sizeHashTable; i++)
	{
		cout << i;
		Table[i].Display();
		cout << endl;
	}
}

int main()
{
	Hashing H(6);
	H.insert_data(10);
	H.insert_data(20);
	H.insert_data(30);
	H.insert_data(60);
	H.insert_data(40);
	H.insert_data(140);
	H.Display_Table_Content();
	H.delete_Content(10);
	cout << endl;
	H.Display_Table_Content();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

