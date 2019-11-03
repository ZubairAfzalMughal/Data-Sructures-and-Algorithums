// stack using linklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class stack {
private:
	struct Node
	{
		Node *next;
		int data;
		Node(int val) {
			data = val;
			next = NULL;
		}
	};
public:
	Node *head;
	stack() {
		head = NULL;
	}
	void push(int val) {
		Node *mynode = new Node(val);
		if (head == NULL) {
			head = mynode;
		}
		else {
			mynode->next = head;
			head = mynode;
		}
	}
	void pop() {

		if (head == NULL) {
			cout << "list is empty \n";
		}
		else {
			Node *ptr = head;
			head = head->next;
			ptr->next = NULL;
			delete ptr;
			ptr = head;
		}
	}
	void Dislay() {
		Node *ptr = head;
		while (ptr != NULL) {
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
};
int main()
{
	stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.pop();
	st.pop();
	st.pop();
	st.Dislay();

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
