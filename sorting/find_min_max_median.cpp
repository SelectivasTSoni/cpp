// find_median.cpp

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

//#include "sorting_lib.h"

int findMax(vector<int> &arr)
{
	int max = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}


int findMin(vector<int> &arr)
{
	int min = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}


// Return true if value greater than candidate
int above(int value, int candidate)
{
	return value > candidate;
}


//return true if value less than candidate
int below(int value, int candidate)
{
	return value < candidate;
}


//finds median value in an unsorted array
int findMedian(vector<int> &arr)
{
	/*
	the median is the value with half the other values above it and the other half below it. Values equal to the candidate get ignored. This means our counts must only include values != candidate.

	Our array will not be sorted because we must use this function to sort it. 

	To do this, we can use an initial candidate value, then count how many values are above it and below it. Then we advance the index to the next candiate until the above and below counts are even.

	A key thing to remember is because our array in unsorted, we are looking for a value, not an index position! 
	*/

	int candidate = 0;
	int above_count = 0;
	int below_count = 0;
	
	// each element of the array as a candidate to be the median value
	for (int i = 0; i < arr.size()-1; i++)
	{
		candidate = arr[i];

		// check if other, non-candidate elements are above or below candidate, ignoring equal values
		for(int j = 0; j < arr.size()-1; j++)
		{ 	
			if (j != i && above(j, i))
			{
				above_count++;
			}

			if (j != i && below(j, i))
			{
				below_count++;
			}
		}

		// if above_count == below_count, arr[i] is the median.
		if (above_count == below_count)
		{
			int median = arr[i];
			return median;
		}

		// if the  number of values !candidate are odd in number, above_count will never equal below_count, the'll be different by 1. For now, we'll consider that the indicator of the median.
		int count_sum = above_count + below_count;
		if (count_sum % 2 == 1) // indicating odd number of elements
		{
			bool odd = true;

			if (odd && above_count % below_count == 1)
			{
				int median = arr[i];
				return median;
			} 
		}
	}

	return 0;
}



int main()
{
	vector<int> arr = {10, 3, 5, 2, 8, 7, 6};

	int min = findMin(arr);
	int max = findMax(arr);
	int median = findMedian(arr);

	for(int i=0; i < arr.size() - 1; i++)
	{
		cout << i << ' ';
	}
	cout << endl;

	cout << "The min is: " << min << endl;
	cout << "The max is: " << max << endl;
	cout << "The median is: " << median << endl;

	return 0;
}