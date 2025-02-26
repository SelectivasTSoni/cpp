// sorting_lib.cpp

/*
	This file contains fuction definitions.
	Function prototypes are in sorting_lib.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

// I'm not sure if this goes here or not.
#include "sorting_lib.h"

using namespace std;


/**************************
 * Utility functions
**************************/

int aXSquared(int a, int b, int e)
{	
	int y = a * pow(b, e);
	return y;
}


//applies bucket-sort to elements of arr
void bucketSortUtil(vector<int> &arr, int maxValue, int numBuckets)
{
	int length = arr.size();

	if (length == 0)
	{
		return;
	}
	
	//create empty buckets
	vector<vector<int>> buckets(numBuckets);

	for (int i = 0; i < numBuckets; i++)
	{
		buckets.push_back(vector<int>());
	}

	int div = ceil(static_cast<double>(maxValue) / numBuckets);

	//add elements into the buckets
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0 || arr[i] > maxValue)
		{
			cout << "Value out of range." << endl;
			return;
		}

		int bucketIndex = (arr[i] / div);

		// Maximum value will be assigned to last bucket
		if (bucketIndex >= numBuckets)
		{
			bucketIndex = numBuckets - 1;
		}
		
		buckets[bucketIndex].push_back(arr[i]);
	}

	// sort the elements of each bucket.
	for (int i = 0; i < numBuckets; i++)
	{
		sort(buckets[i].begin(), buckets[i].end());
	}

	// Populate output from the sort subarray
	int index = 0;
	int count;

	for (int i = 0; i < numBuckets; i++)
	{
		vector<int> temp = buckets[i];
		count = temp.size();

		for (int j = 0; j < count; j++)
		{
			arr[index++] = temp[j];
		}
	}
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


int findMedian(vector<int> &arr)
{
	/*
		the median is the value with half the other values above it and the other half below it. Our array will not be sorted because we must use this function to sort it.

		to do this, we can use an initial candidate value, then count how many values are above it and below it. Then we advance the index to the next candiate until the above and below counts are even.
	*/

	int size = arr.size();
	int range = size - 1;

	//check for even or odd
	if (size % 2 == 0)
	{
		bool even = true;
	}
	else
	{
		bool even = false;
	}

	int candidate = 0;
	int above_count = 0;
	int below_count = 0;
	int equal_count = 0;

	// set each element of the array as a candidate
	for (int i = 0; i < range; i++)
	{
		candidate = arr[i];

		// compare the candidate to every other element and count those above, below, and equal
		for (int j = 0; j < range; j++)
		{
			if (i > candidate)
			{
			above_count++; 
			}
			else if (i < candidate)
			{
			below_count++;
			}
			else
			{
			equal_count++;
			}
		}

		// once every element has been compared to the candidate, half of arr.size() should be above and half below. I think if we just ignore equal_count, we can use above_count == below_count as the test. So, after every element has been checked against a candidate, if above_count == below_count, the the candidate is the median value. This isn't perfect, but may serve for now.

		// what if their array contains values equal to the candidate? 

		//check the counts
		if (above_count == below_count)
		{
			return candidate;
		}

	}


	// for some insight, see:
	// https://stackoverflow.com/questions/1719070/what-is-the-right-approach-when-using-stl-container-for-median-calculation/1719155#1719155

	// size_t n = v.size() / 2;
    // nth_element(v.begin(), v.begin()+n, v.end());
    // return v[n];


	// Don't be pedantic!! We define median to be element k = n/2, which in this case works fine

	int middle = arr.size() / 2;
	//int partition = nth_element(arr.begin(), arr.begin() + middle, arr.end());

	
	// the median is the value with half the other values above it and the other half below it. 

	int count = 0;
	int sum = 0;
	
	for(int i = 0; i < arr.size() - 1; i++)
	{
		sum += i;
	}
	int median = sum / arr.size();
	return median;
}


// swaps values at indices i and j
int swap(vector<int> &arr, int i, int j) 
{
	int swaps = 0;

	int temp = arr[i];	// put value at i into temp
	arr[i] = arr[j];	// put value at j into i
	arr[j] = temp;		// put value at i into j

	swaps++; 

	return swaps;
}


void minSwapsUtil(vector<int> &arr, int lower, int upper, int lessThanValue)
{
	// is lessThanValue in the array? 
	// https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
	if(find(arr.begin(), arr.end(), lessThanValue) == arr.end())
	{
		return; 
	} 
	
	// upper can't be less than lower
	if (upper <= lower)
	{
		return;
	}

	// set pivot to the given value
	int pivot = lessThanValue;
	int start = lower;	
	int stop = upper;

	while (lower < upper)
	{	
		// This loop breaks when lower is above the pivot.
		while (arr[lower] <= pivot && lower < upper)
		{
			// this executes until arr[lower] is above pivot position...
			lower++;
			
		}
		// This loop breaks when upper is equal to the pivot
		while (arr[upper] > pivot && lower <= upper)
		{
			// upper advances until it is at the pivot position...
			upper--;
			// so you have the lower index above the pivot, and upper index is at the pivot, then..
		}
		//...so if lower is a smaller value than upper...
		if (lower < upper) 
		{	
			// the VALUES at upper and lower switch places...
			swap(arr, upper, lower);
			// In swap(), the VALUES are exchanged which is what accomplishes the sorting.
		}

		// this process continues until lower == upper...
	}

	// ...then the VALUES of upper and lower (==start) switch, which sets upper as the pivot [?]
	swap(arr, upper, start); // upper is the pivot position

	// and we call minSwapsUtil() on left sub-array... 
    minSwapsUtil(arr, start, upper-1, lessThanValue); //pivot-1 is upper for left sub-array.
    
    // ...then right sub-array...
    minSwapsUtil(arr, upper+1, stop, lessThanValue); //pivot+1 is lower for right sub-array.
}


// Lower and upper are simply values that track index positions
void quickSortUtil(vector<int> &arr, int lower, int upper)
{
	// upper can't be less than lower, because all the condition 
	// checks assume is higher. Our experiement with upper > lower 
	// resulted in ...
	if (upper <= lower)
	{
		return;
	}

	int pivot = arr[lower];
	int start = lower;	
	int stop = upper;

	while (lower < upper)
	{	
		// This loop breaks when lower is above the pivot.
		while (arr[lower] <= pivot && lower < upper)
		{
			// this executes until arr[lower] is above pivot position...
			lower++;
			
		}
		// This loop breaks when upper is equal to the pivot
		while (arr[upper] > pivot && lower <= upper)
		{
			// upper advances until it is at the pivot position...
			upper--;
			// so you have the lower index above the pivot, and upper index is at the pivot, then..
		}
		//...so if lower is a smaller value than upper...
		if (lower < upper) 
		{	
			// the VALUES at upper and lower switch places...
			swap(arr, upper, lower);
			// In swap(), the VALUES are exchanged which is what accomplishes the sorting.
		}

		// this process continues until lower == upper...
	}
	// ...then the VALUES of upper and lower (==start) switch, which sets upper as the pivot
	swap(arr, upper, start); // upper is the pivot position

	// and we call quickSortUtil() on left sub-array... 
    quickSortUtil(arr, start, upper-1); //pivot-1 is upper for left sub-array.
    // ...then right sub-array...
    quickSortUtil(arr, upper+1, stop); //pivot+1 is lower for right sub-array.

    // Its hella confusing!
}


/**************************
 * sorting functions
**************************/

int binarySort(vector<int> &arr) 
{
    int size = arr.size();
    int left = 0;
    int right = size - 1;
    int swap_count = 0;

    // continue until left and right pointers meet
    while (left < right) 
    {
        // Slides have an error here. 
        // What follows is correct:
        //move left pointer right while encountering 1's
        while (left < right && arr[left] == 1) 
        {
            left += 1;
        }
        // move right pointer left while encountering 0's
        while (left < right && arr[right] == 0)
        {
            right -= 1;
        }

        // Swap the elements if left < right
        // Slides have (left <)
        if (left < right) 
        {
            swap(arr[left], arr[right]);
            swap_count++;
        }
    }

    return swap_count;
}


void bucketSort(vector<int> &arr, int maxValue)
{
	int numBuckets = 5;
	bucketSortUtil(arr, maxValue, numBuckets);
}


void quickSort(vector<int> &arr, int lessThanValue)
{
	int size = arr.size();
	minSwapsUtil(arr, 0, size - 1, lessThanValue);
}


// has a logic error somewhere
// puts the 12th element at [0]
// ...weird. 
void selectionSort(vector<int> &arr) 
{
	int size = arr.size();
	int i, j, max, temp;

	//for (i = 0; i < size - 1; i++)
	for(int i: arr)
	{
		max = 0;
		// this moves the pointer left so 
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}

		//this is just swap()
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[max];
		arr[max] = temp;
	}
}


// Works great.
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

