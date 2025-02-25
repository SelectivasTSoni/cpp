// min_swaps.cpp

// Find the minimum number of swaps required to bring all elements less than a given value together at the start of the array.

#include<iostream>
#include<vector>
#include<algorithm>

#include "sorting_lib.h"

using namespace std;


// // using list intialization
// int swaps {0};
// int operations {0}; 

// // swaps values at indices i and j
// void swap(vector<int> &arr, int i, int j) 
// {
// 	int temp = arr[i];	// put value at i into temp
// 	arr[i] = arr[j];	// put value at j into i
// 	arr[j] = temp;		// put value at i into j

// 	swaps ++; 
// }

/*
	To get all elements < given value to the front of any arry, we must:
		1. know what the given value is
		2. know it is an element in the array
		3. use it as our comparison for the swaps, the pivot
*/

// Lower and upper are simply values that track index positions
// void minSwapsUtil(vector<int> &arr, int lower, int upper, int lessThanValue)
// {
// 	// is lessThanValue in the array? 
// 	// https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
// 	if(find(arr.begin(), arr.end(), lessThanValue) == arr.end())
// 	{
// 		return; 
// 	} 
	
// 	// upper can't be less than lower
// 	if (upper <= lower)
// 	{
// 		return;
// 	}

// 	// set pivot to the given value
// 	int pivot = lessThanValue;
// 	int start = lower;	
// 	int stop = upper;

// 	while (lower < upper)
// 	{	
// 		// This loop breaks when lower is above the pivot.
// 		while (arr[lower] <= pivot && lower < upper)
// 		{
// 			// this executes until arr[lower] is above pivot position...
// 			lower++;
			
// 		}
// 		// This loop breaks when upper is equal to the pivot
// 		while (arr[upper] > pivot && lower <= upper)
// 		{
// 			// upper advances until it is at the pivot position...
// 			upper--;
// 			// so you have the lower index above the pivot, and upper index is at the pivot, then..
// 		}
// 		//...so if lower is a smaller value than upper...
// 		if (lower < upper) 
// 		{	
// 			// the VALUES at upper and lower switch places...
// 			swap(arr, upper, lower);
// 			// In swap(), the VALUES are exchanged which is what accomplishes the sorting.
// 		}

// 		// this process continues until lower == upper...
// 	}

// 	// ...then the VALUES of upper and lower (==start) switch, which sets upper as the pivot [?]
// 	swap(arr, upper, start); // upper is the pivot position

// 	// and we call minSwapsUtil() on left sub-array... 
//     minSwapsUtil(arr, start, upper-1, lessThanValue); //pivot-1 is upper for left sub-array.
    
//     // ...then right sub-array...
//     minSwapsUtil(arr, upper+1, stop, lessThanValue); //pivot+1 is lower for right sub-array.
// }


// next we modifiy quickSort for the minSwaps task by using the given value as the pivot. The main difference is the lessThanValue parameter and a minor change to 
// void minSwapsSort(vector<int> &arr, int lessThanValue)
// {
// 	int size = arr.size();
// 	minSwapsUtil(arr, 0, size - 1, lessThanValue);
// }


int main()
{
	int lessThanValue = 5;
    vector<int> arr = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10};

    minSwapsSort(arr, lessThanValue);

    for (int i: arr)
        cout << i << '\n';

    cout << "lessThanValue: " << lessThanValue << endl;
	cout << "Number of swaps: " << swaps << endl; 
	
	return 0;
}



