// recursive function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

// this function will calculate the power of a number
int Pow(int n, int m) {
	if (m == 0) {
		return 1;
	}
	else
		return n * Pow(n, m - 1);
}

// this function will caculate the multiplication

int Mul(int n, int m) {

	if (n == 0 || m == 0) {
		return 0;
	}
	else
		return n + Mul(n, m - 1);
}

// this function will calculate the fibonacci series

int Fibo(int n) {
	if (n == 0||n==1) {
		return 1;
	}
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

// this function will calculate the series 

/*
     this a function in wgich first two numbers are multiple of third
	 and next number is sum if previous of tww numbers
*/

int Fun(int n) {

	if (n == 0||n==1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n % 2 != 0) {
		return Fun(n - 1) + Fun(n - 2);
	}
	else if (n % 2 == 0) {
		return Fun(n - 1)*Fun(n - 2);
	}
}
int main()
{
	cout << Mul(2, 3) << endl;
	cout << Pow(2, 3) << endl;
	int i = 0;
	while (i < 10)
	{
		//cout << Fibo(i)<<" " ;
		cout << Fun(i)<<" " ;
		i++;
	}
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
