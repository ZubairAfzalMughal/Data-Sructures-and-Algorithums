
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
	int size;
	int top;
	int *arr;
	stack() {
		top = 0;

	}
	stack(int s) {
		size = s;
		top = 0;
		arr = new int[size];
	}
	bool IsEmpty() {
		if (top == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool IsFull() {
		if (top == size) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void push(char val) {
		if (!IsFull()) {
			arr[top] = val;
			top++;
		}
		else {
			cout << "array is full \n";
		}
	}
	char pop() {

		if (!IsEmpty()) {
			char  i = arr[top - 1];
			arr[top - 1] = -1;
			top--;
			return i;
		}
		else {
			return -1;
		}
	}
	char Top()
	{
		if (!IsEmpty())
		{
			int i = arr[top - 1];
			return i;
		}
		else
		{
			return -1;
		}
	}
	void diplay() {
		for (int i =0; i<top; i++) {

			cout << arr[i];
		}
	}
};
// this class will calculate the sum of two large numbers using stack
class Add
{
private:
	int size;
public:
	Add(){
		size = 0;
	}

	// this function will push the value into the stack

	void Push_Value_To_stack(string value) {

		size = value.length();
		stack s(size);
		for (int i = 0; i < size; i++) {

			int num = value[i] - 48;
			s.push(num);
		}
		s.diplay();
	}

};

string findSum(string str1, string str2)
{
	//lebgth of string should be greater 
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result 
	string str = "";

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings 

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{

		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str += (sum % 10 + '0');
		// Calculate carry for next step 
		carry = sum / 10;
	}

	// Add remaining digits of larger number 
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		str += (sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry 
	if (carry)
		str.push_back(carry + '0');

	// reverse resultant string 
	reverse(str.begin(), str.end());

	return str;
}

int main()
{
	string str1;
	string str2;
	cout << "Enter first number \n";
	cin >> str1;
	cout << "Enter second number \n";
	cin >> str2;
	string add_str="";
	add_str=findSum(str1, str2);
	Add a;
	a.Push_Value_To_stack(add_str);
}