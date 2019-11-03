// queue using linklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Queue {

	struct Node {
		int data;
		Node *next;
		Node(int value) {
			data = value;
			next = NULL;
		}
		
	};
public:

	Node *head;
	Queue() {
		head = NULL;
	}
	void Engue(int value) {
		Node *mynode = new Node(value);
		if (head == NULL) {
			head = mynode;
		}
		else {
			Node *ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = mynode;
		}
	}
	void Degue() {
		Node  *prev = head;
		head = head->next;
		prev->next = NULL;
		delete prev;
		
	
	}
	void Display() {
		Node *ptr = head;
		while (ptr != NULL) {
			cout << ptr->data << endl;
			ptr =ptr->next;
		}
	}
};
int main()
{
	Queue q;
	q.Engue(10);
	q.Engue(20);
	q.Engue(30);
	q.Engue(40);
	q.Degue();
	q.Degue();
	q.Degue();

	q.Display();
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
