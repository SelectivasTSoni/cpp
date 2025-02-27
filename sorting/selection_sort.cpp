// selection_sort.cpp

#include<iostream>
#include<vector>

using namespace std;


void selectionSortV2(vector<int> &arr) 
{
	int size = arr.size();
	int i, j, min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j; 
			}
		}

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}


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