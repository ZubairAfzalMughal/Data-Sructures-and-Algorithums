// problem no 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
template <class T>
class CircularQueue {
private:
	T *arr;
	int size;
	int front;
	int rear;
public:
	CircularQueue(int s);
	bool IsEmpty();
	bool IsFull();
	void Engue(T items);// recevie templete argument
	void Degue();
	void Display();

};
template <class T>
CircularQueue<T>::CircularQueue(int s) {

	arr = new T[s];
	size = s;
	rear = front = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = -1;
	}
}
template <class T>
bool CircularQueue<T>::IsEmpty() {
	if (front == rear) {
		rear = front = 0;
		return true;
	}
	else
		return false;
}
template <class T>
bool CircularQueue<T>::IsFull() {
	if (rear == size) {
		return true;
	}
	else
		return false;
}
template <class T>
void CircularQueue<T>::Engue(T value) {
	if (!IsFull()) {
		arr[rear] = value;
		rear++;
		rear = rear % size;// to bring the rear back to first index
	}
	else
		cout << "array is full \n";
}
template <class T>
void CircularQueue<T>::Degue() {

	if (!IsEmpty()) {

		T value= arr[front];
		arr[front] = -1;
		front++;
		front = front % size;

	}
}


template <class T>
void CircularQueue<T>::Display() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}
int main()
{  
	CircularQueue<string>c(5);  // create a queue
	c.Engue("A");
	c.Engue("A");
	c.Engue("A");
	c.Engue("A");
	c.Engue("A");
	c.Degue();
	c.Degue();
	c.Engue("B");
	c.Engue("B");
	
	c.Display();



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
