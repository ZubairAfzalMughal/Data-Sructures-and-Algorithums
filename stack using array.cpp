// stack using array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Stack {
public:
	int size;
	int *arr;
	int top;
	Stack(int s) {
		size = s;
		top = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = -1;
		}
	}
	bool IsEmpty() {
		if (top == 0) {
			return true;
		}
		else
			return false;
	}
	bool IsFull() {
		if (top == size) {
			return true;
		}
		else
			return false;
	}
	int push(int val) {
		if (!IsFull()) {
			/*
			in this function we have to push the value and
			increase the top position
			*/
			arr[top] = val;
			top++;
		}
		else
			return -1;
	}
	int pop() {
		if (!IsEmpty()) {

			int i = arr[top - 1];
			arr[top - 1] = -1;
			top--;
			return i;
		}

		else
			return -1;
	}
	int Top() {
		if (!IsEmpty()) {
			int i = arr[top - 1];
			return i;
		}
		else
			return false;
	}
	void Display() {
		for (int i = 0; i < top; i++) {
			cout << arr[i] << endl;
		}
	}
};
int main()
{
	Stack st(6);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.Display();
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
