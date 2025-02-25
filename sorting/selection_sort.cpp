// selection_sort.cpp

#include<iostream>
#include<vector>

#include "sorting_lib.h"

using namespace std;


int main()
{
	vector<int> arr = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90, 11, 22, 33, 44, 55};

	// selectionSort(arr); // has a weird error
	selectionSortV2(arr);

	for(int i:arr)
	{
		cout << i << ' ';
	}

	cout << endl;

	return 0;
}