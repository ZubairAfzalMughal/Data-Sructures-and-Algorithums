// queue using array list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Queue {

public:
	int *arr;
	int size;
	int front, rear;
	//front will point the first index and 
	// rear will point the current index value
	Queue(int s) {
		size = s;
		arr = new int[size];
		front = rear = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = -1;
		}
	}
	bool IsFull() {
		if (rear == size) { // when rear and size are equal than it willfull
			rear = front = 0;
			return true;
		}
		else
			return false;
	}
	bool IsEmpty() {
		if (front == size) {
			return true;
		}
		else
			return false;
	}
	// Engue is like a push function
	void Engue(int s) {

		if (!IsFull()) {
			arr[rear] = s;
			rear++;
		}
		else
			cout << "your list is full \n";
	}
	// Degue is like a pop function 
	int Degue() {

		if (!IsEmpty()) {
			int i = arr[front];
			arr[front] = -1;
			front++;
			return i;
		}
		else
			cout << "list is empty \n";
	}
	void Display() {
		for (int i = 0; i < rear; i++) {
			cout << arr[i]<<" ";
		
		}
		cout << endl;
	}
};
int main()
{
	// car on left road
	Queue q_left(3);
    q_left.Engue(10);
    q_left.Engue(20);
    q_left.Engue(30);
  //car on rigth road

	Queue q_right(3);
	q_right.Engue(40);
	q_right.Engue(50);
	q_right.Engue(60);
	// car on left road

	cout << "Car On Left Road ";
	q_left.Display();

	// Car on rogth road
	cout << "Car On rigth road ";
	q_right.Display();
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
