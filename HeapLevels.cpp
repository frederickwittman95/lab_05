// Frederick Wittman
// Dr. Hill
// COSC 2030-01
// 25 March 2019

/*
* C++ Program to Implement Max Heap
*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
// For log function, include math
#include <math.h> 
// Include iomanip for formatting
#include <iomanip>
using namespace std;
void max_heapify(int *a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void build_maxheap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}

int main()
{   
	int num_elements, i, x;

	// I chose 8 elements for the test case.  It would be simple to modify the code to take an arbitrarily large number of values.
	num_elements = 8;
	int a[100];			//DO NOT USE THE ARRAY POSITION a[0]!!!

						// Allows user to specify heap elements
	cout << "Please specify eight numbers you would like added to the heap.";
	for (int j = 1; j <= num_elements; j++)
	{
		cin >> a[j];
	}

	build_maxheap(a, num_elements);
	cout << "Max Heap\n";

	// Prints heap with appropriate number of dashes.  Level 1 has 0 dashes, level 2 1 dash, and so on.
	for (i = 1; i <= num_elements; i++)
	{
		int tmp = floor(log2(i)) + 1;
		cout << setfill('-') << setw(tmp) << a[i] << endl;
	}
}

