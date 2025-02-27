// min_swaps.cpp

// Find the minimum number of swaps required to bring all elements less than a given value together at the start of the array.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




// takes index positions i and j and swaps the values those indices.
int swaps = 0;
void swap(vector<int> &arr, int i, int j) 
{
	int temp = arr[i];	// put value at i into temp
	arr[i] = arr[j];	// put value at j into i
	arr[j] = temp;		// put value at i into j

	swaps ++; 
}

/*
	To get all elements < given value to the front of any arry, we must:
		1. know what the given value is
		2. know it is an element in the array
		3. use it as our comparison for the swaps, the pivot
*/

//Lower and upper are index positions. pivot_value is the value we are sorting to the left of.
void minSwapsUtil(vector<int> &arr, int lower, int upper, int specified_value)
{
	// is lessThanValue in the array? 
	// https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
	if (find(arr.begin(), arr.end(), specified_value) == arr.end())
	{
		return; 
	} 
	
	// upper can't be less than lower
	if (upper <= lower)
	{
		return;
	}

	
	// set pivot to the given value
	int pivot_value = arr[lower];
	int start = lower;	
	int stop = upper;

	// until the lower index and upper index are the same
	// This implies lower and upper indices are moving towards each other, which is exactly what the nested while loops are doing.
	while (lower < upper)
	{	
		// "While the value at [lower] is less than or equal pivot_value, advance lower index..."
		while (arr[lower] <= pivot_value && lower < upper)
		// This loop breaks when arr[lower] is greater than the pivot_value
		{
			// lower advances until its VALUE is above pivot_value...
			lower++;
		}

		// "While the value at [upper] is greater then pivot_value, decrease the upper index..."
		while (arr[upper] > pivot_value && lower <= upper)
		// This loop breaks when arr[upper] is equal to the pivot_value
		{
			// upper decreases until its VALUE equals pivot_value...
			upper--;
		}

		// At this point, you have lower index at a VALUE above pivot_value, and upper index is at a VALUE equal to pivot_value and...

		// ... the VALUES switch places, so a value above the pivot_value moves to the left of the pivot_value.
		if (lower < upper)
		{	
			// In swap(), the VALUES are exchanged which is what accomplishes the sorting.
			swap(arr, upper, lower);
		}

		// this process continues until lower INDEX == upper INDEX and the outside While loop breaks, which implies [lower]==[upper].
	}

 	// Note that the function has not been called anywhere, so nothing has happened yet.

	// This executes when the outer While loop breaks for the first time.

	//At this point...then the VALUES of upper and lower switch, which sets upper as the pivot [?]. I don't understand why we would switch values when lower INDEX == upper INDEX which is what breaks the While loop... 

	// ...Yeah I do, its because the final swap in the outer loop puts lower above upper, which breaks the loop and advances the pivot INDEX to the right.
	swap(arr, upper, start); // upper is the pivot position

	// Are we done?
	if (pivot_value == specified_value)
	{
		return;
	}

	// and we call this function recursively on left sub-array... 
    minSwapsUtil(arr, start, upper - 1, specified_value); //pivot-1 is upper for left sub-array.
    
    // ...then right sub-array...
    minSwapsUtil(arr, upper + 1, stop, specified_value); //pivot+1 is lower for right sub-array.


    // I think we need a simple check and when the pivot == pivot_value, return. Basically, we have a quick-sort that stops when it reaches the specified value. YES! See line 96

    
}


void minSwapsSort(vector<int> &arr, int specified_value)
{
	int size = arr.size();
	minSwapsUtil(arr, 0, size - 1, specified_value);
}


int main()
{
	int specified_value = 5;
    vector<int> arr = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10};

    minSwapsSort(arr, specified_value);

    cout << "Sorted array: ";
    for (int i: arr)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << "specified_value : " << specified_value << endl;
	cout << "Number of swaps: " << swaps << endl; 
	
	return 0;
}



