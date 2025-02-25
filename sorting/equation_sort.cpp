// equation_sort.cpp

// sort an array according to a*x^2, use {3, -2, 1, -4, 0}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#include "sorting_lib.h"

using namespace std;


int main()
{
	int a = 10;
	int e = 2; 
	
	vector<int> arr = {3, -2, 1, -4, 0};

	cout << "Let a = 10" << endl;

	//for each element in arr, apply the function and assign
	for (int i = 0; i < arr.size() - 1; i++)
	{	
		cout << "Index: " << i;
		arr[i] = aXSquared(a, i, e);
		cout << " Value after a * pow(x, 2): " << arr[i];
		cout << endl;
	}
	
	// sort, but this doesn't seem to be doing anything
	selectionSort(arr);

	return 0;
}



