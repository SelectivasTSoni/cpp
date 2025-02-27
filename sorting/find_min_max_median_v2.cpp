// find_median.cpp

#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

//#include "sorting_lib.h"



/// shawn changes
//1. find min int min = 0 was not helping find a value
//2. Reordered main output to be more testable stepwise
//3. removed arr.size() - 1 in loops, i++ stops at 6 with it as is not 7 due to i++
//4. added what i think the sort is asking - QUESTION IS NOT EXACTLY THAT GREAT IN EXPLAINING
//5. I got rid of the & in the functions, i dont think you need them unless you are modifying
//  the variable in question which doesnt seem to be the case here

int findMax(vector<int> arr)
{
	int max = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}


int findMin(vector<int> arr)
{
	int min = 999999;     //you want to start with a large min and make it smaller
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < min)
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
int findMedian(vector<int> arr)
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
	for (int i = 0; i < arr.size(); i++)
	{
		candidate = arr[i];

		// check if other, non-candidate elements are above or below candidate, ignoring equal values
		for (int j = 0; j < arr.size(); j++)
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


void sort(int min, int max, int median, vector<int> arr, vector<int>& finalarr){

	vector<int> lower;   ///hold everything before median
	vector<int> upper;   ///hold everything including median and after

	for (int i = 0; i < 7; i++) {
		if (arr[i] >= min && arr[i] < median) {   //dont include median
			lower.push_back(arr[i]);             
		}
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] >= median && arr[i] <= max) {    //include median
			upper.push_back(arr[i]);
		}
	}

	sort(lower.begin(), lower.end());   //sort each part seperately
	sort(upper.begin(), upper.end());
	
	
	lower.insert(lower.end(), upper.begin(), upper.end()); ///combine results
	finalarr = lower; //store in finalarr


	
}


int main()
{
	vector<int> arr = { 10, 3, 5, 2, 8, 7, 6 };
	vector<int> finalarr;

	int min = findMin(arr);
	cout << "The min is: " << min << endl;

	int max = findMax(arr);
	cout << "The max is: " << max << endl;

	int median = findMedian(arr);
	cout << "The median is: " << median << endl;

	sort(min, max, median, arr, finalarr);
	
	//for (int i = 0; i < arr.size() - 1; i++)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;

	////final should be: 2, 3, 5, 6, 7, 8, 10

	//final output
	for (int i = 0; i < finalarr.size()-1; i++) {
		cout << finalarr[i] << ", " ;
	}
	cout << finalarr[6] << endl;  //get rid of comma on final output

	return 0;
}