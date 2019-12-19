#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
public:
	string name;
	int id;
	float gpa;
	Student()
	{
		name = "";
		id = 0;
		gpa = 0.0;
	}
	void get_data()
	{
		cout << "Enter id \n";
		cin >> id;
		cout << "Enter student name\n";
		cin >> name;
		cout << "Enter gpa\n";
		cin >> gpa;
	}
};

class Node
{
public:
	//private does not access by main function

	Student data;
	Node *next;
	Node *prev;

	Node(Student value) {

		this->data = value;
		next = prev = NULL;
	}
};

// wrapper class of Node class here we will defined all the function etc

class LinkedList {

public:
	Node *head;
	Node *tail;
	LinkedList() {

		head = tail = NULL;
	}

	void InserstData(Student value);
	Node *Search(string val);
	void delte(string val);
	void Display();
};
Node* LinkedList::Search(string val)
{
	Node *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data.name == val)
		{
			cout << "Value is found\n";
			return ptr;
			break;
		}
		ptr = ptr->next;

	}
}
void LinkedList::delte(string name)
{
	Node *find = Search(name);
	if (find == head)
	{
		head = head->next;
		find->next = NULL;

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
void LinkedList::InserstData(Student value)
{
	// create a node first
	// make a pointer and called it like a constructor

	Node *mynode = new Node(value); // make temporary object

	if (head == NULL) {

		head = tail = mynode;
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

		cout << " --> " << ptr->data.id<<" "<<ptr->data.name<<" "<<ptr->data.gpa ;
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
	void insert_data(Student val);
	void delete_Content(string val);
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
void Hashing::insert_data(Student val)
{
	int index = this->HashFunction(val.name.length()); // maping 


	this->Table[index].InserstData(val); // inserting data into Hash table  
}
void Hashing::delete_Content(string val)
{
	int index = HashFunction(val.length());
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

// Heap Sorting Ascending Order

class Heap_Sort
{
public:
	int *arr;
	int size;
	int cap;

	Heap_Sort(int s)
	{
		size = s;
		cap = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = -1;
		}
	}
	void insert(int val);
	int left_child(int i)
	{

		if ((i * 2) > size)
		{
			return i;
		}
		else
		{
			return i * 2;
		}
	}
	int right_child(int i)
	{
		if ((i * 2) + 1 > size)
		{
			return 0;
		}
		else
		{
			return (i * 2) + 1;
		}
	}
	int parent(int i)
	{
		if ((i / 2) < size)
		{
			return 0;
		}
		else
		{
			return i / 2;
		}
	}
	void Heapify(int arr[], int i, int size);
	void Buildify();
	void HeapSort(int arr[], int size);
	void Display();

};
void Heap_Sort::insert(int val)
{
	if (cap < size &&cap >= 0)
	{
		arr[cap] = val;
		cap++;
	}
	else
	{
		cout << "Array is full\n";
	}
}
void Heap_Sort::Display()
{
	for (int i = 1; i < size; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void Heap_Sort::Heapify(int arr[], int i, int size)
{
	// sorting the element in Ascending order

	int max = i;
	int l = left_child(i);
	int r = right_child(i);

	// left child is Greater
	if (l < size && arr[l] > arr[max])
	{
		max = l;
	}
	// If right child is Greater 
	if (r < size && arr[r] > arr[max])
	{
		max = r;
	}
	// If largest is not root 
	if (max != i)
	{
		swap(arr[i], arr[max]);

		// Recursively heapify the affected sub-tree 
		Heapify(arr, i, max);
	}


}
void Heap_Sort::Buildify()
{
	for (int i = (size / 2); i >= 1; i--)
	{
		Heapify(arr, i, size);
	}
}
void Heap_Sort::HeapSort(int arr[], int size)
{
	Buildify();
	int j = 1;
	for (int i = size - 1; i >= 1; i--)
	{
		// Move current root to end 
		swap(arr[j], arr[i]);

		// call min heapify function
		Heapify(arr, j, i);
	}
}

// Union of BST

/*
		this class contain the Node operation
*/

class T_Node {
public:
	int data;
	T_Node *right;
	T_Node *left;
	T_Node *p;
	T_Node(int data) {
		this->data = data;
		right = NULL;
		left = NULL;
		p = NULL;
	}

};

/*
		this is wrapper class of Node Class
		this will contain the all possible that we eill defined
*/

class BST {
public:
	T_Node *root;
	int arr1[20];
	int arr2[20];
	int cap1;
	int cap2;

	BST() {
		root = NULL;
		cap1 = cap2 = 0;

	}
	void insert(int val);
	void Display(T_Node *temp);// recursion
	void Arr1(T_Node *tree1)
	{
		if (tree1 == NULL)
		{
			return;
		}
		else
		{
			arr1[cap1] = tree1->data;
			cap1++;
			Display(tree1->left);
			Display(tree1->right);

		}
		
	}
	void Arr2(T_Node *tree2)
	{
		if (tree2 == NULL)
		{
			return;
		}
		else
		{
			arr2[cap2] = tree2->data;
			cap1++;
			Display(tree2->left);
			Display(tree2->right);

		}

	}

	void Union(T_Node *tree1, T_Node *tree2);
};

void BST::Union(T_Node *tree1, T_Node *tree2)
{
	BST temp;
	if (tree1 == NULL)
	{
		return;
	}
	else
	{
		arr1[cap1] = tree1->data;
		cap1++;
		Display(tree1->left);
		Display(tree1->right);

	}

	if (tree2 == NULL)
	{
		return;
	}
	else
	{
		arr2[cap2] = tree2->data;
		cap2++;
		Display(tree2->left);
		Display(tree2->right);

	}
	
	for (int i = 0; i < cap1; i++)
	{
		
		for (int j = 0; j < cap2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				temp.insert(arr1[i]);
			}
			else
			{
				
				temp.insert(arr2[j]);
			}
		}
		temp.insert(arr1[i]);
	}
	

}
void BST::insert(int val)
{
	BST temp_b;

	T_Node *mynode = new T_Node(val);
	if (root == NULL) {
		root = mynode;
	}
	else
	{
		T_Node *temp = root;
		while (temp != NULL)
		{
			if (mynode->data > temp->data) // compare the values if greater than proceed
			{
				if (temp->right == NULL)
				{
					temp->right = mynode; // insert the value and break it
					mynode->p = temp;
					break;
				}
				else
				{
					temp = temp->right;

				}

			}
			else  // value is less as above is greater 
			{
				if (temp->left == NULL)
				{
					temp->left = mynode;
					mynode->p = temp;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
		}

	}
}

void BST::Display(T_Node *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		cout << temp->data << " ";
		Display(temp->left);
		Display(temp->right);
		// this will be pre order walk
	}

}


int main()
{
	BST b,b2,b3;
	b.insert(10);
	b.insert(20);
	b.insert(50);
	b.insert(15);
	b.insert(7);
	b.insert(9);
	b.insert(6);
	//b.Display(b.root);
	//cout << endl;

	b2.insert(20);
	b2.insert(17);
	b2.insert(40);
	b2.insert(60);
	b2.insert(30);
	b2.insert(6);
	b2.insert(19);
//	b2.Display(b2.root);

	//b2.Arr1(b2.root);
	b3.Union(b.root, b2.root);
	b3.Display(b3.root);
	cout << endl;
	/*cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	Heap_Sort s(7);
	s.insert(0);
	s.insert(10);
	s.insert(1);
	s.insert(7);
	s.insert(9);
	s.insert(8);
	s.insert(2);
	s.HeapSort(s.arr, 7);
	s.Display();
	cout << endl;
	cout << endl;
	cout << endl;
	*/
	Student S;
	Hashing H(2);
	for (int i = 0; i < 2; i++)
	{
		S.get_data();
		H.insert_data(S);
	}
	string name;
	cout << "Enter name to delte\n";
	cin >> name;
	H.delete_Content(name);
	H.Display_Table_Content();

}