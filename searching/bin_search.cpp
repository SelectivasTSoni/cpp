// bin_search.cpp

#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> &arr, int value)
{
	int size = arr.size();
	int low = 0;
	int high = size -1; 
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (arr[mid] == value)
		{
			//return arr[mid];
			return mid;

		} 
		else if (arr[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid -1;
		}
	}

	return 0;
}


int main()
{
	vector<int> arr = {12, 3, 5, 7, 19, 1};

	int find = 19;
	int one = binarySearch(arr, find);

	int find_2 = 1;
	int two = binarySearch(arr, 1);


	cout << "Index position of given value " << find <<": " << one << endl;

	// this is a hack
	if (two == 0)
	{
		cout << "Index position of given value " << find_2<<": " << "Element not found in the array" << endl;
	}
	else
	{
		cout << "Index position of given value " << find_2<<": " << two << endl;
	}

	return 0;
}



