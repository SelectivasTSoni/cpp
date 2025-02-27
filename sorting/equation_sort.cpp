// equation_sort.cpp

// sort an array according to a*x^2, use {3, -2, 1, -4, 0}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int aXSquared(int a, int b, int e)
{	
	int y = a * pow(b, e);
	return y;
}


void selectionSortV2(vector<int> &arr) 
{
	int size = arr.size();
	int i, j, min, temp;

	for (i = 0; i < size; i++)
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
	
	selectionSortV2(arr);

	cout << endl;
	cout << "Sorted array : ";
	for (int i = 0; i < arr.size(); i++)
    {
    	cout << arr[i] << ' ';
    }
   	cout << endl;
   	cout << endl;

	return 0;
}



