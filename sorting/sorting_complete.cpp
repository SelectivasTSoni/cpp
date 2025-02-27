// sorting_complete.cpp


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**************************
 * Utility functions
**************************/

int aXSquared(int a, int b, int e)
{	
	int y = a * pow(b, e);
	return y;
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


// finds the union of two sorted arrays
vector<int> getUnion(vector<int>& arr1, vector<int>& arr2) 
{
	/*
		Union is the set of elements in both arrays
	*/

    vector<int> new_set; 
    int n = arr1.size();
    int m = arr2.size();
  
    // while there are elements in both arr1 and arr2
    int i = 0;
    int j = 0;    
    while(i < n && j < m) 
    {
		
      	// if element in arr1 is LESS than element in arr2, 
      	// push element of arr1 to new_set, advance index of arr1
        if(arr1[i] < arr2[j]) 
        {
          	new_set.push_back(arr1[i]);
            i++;
        }
        // if element of arr1 is GREATER than element in arr2,
        // push element of arr2 to new_set, advance index of arr2
        else if(arr1[i] > arr2[j]) 
        {
          	new_set.push_back(arr2[j]);
            j++;
        }
      
        // If equal, push element to new_set, 
        // advance both indices of arr1 and arr2.
        else 
        {
            new_set.push_back(arr1[i]);
            i++;
            j++;
        }
    }
  	
  	// Add the remaining elements of arr1
  	while (i < n) \
  	{
      	new_set.push_back(arr1[i]);
      	i++;
    }
  
  	// Add the remaining elements of arr2
  	while (j < m) 
  	{
      	new_set.push_back(arr2[j]);
      	j++;
    }
    return new_set; 
}


// finds the intersection of two sorted arrays
vector<int> getIntersection(vector<int> arr1, vector<int> arr2)
{
	/*
		Intersection is the set of elements common to both arrays
	*/

	vector<int> new_set;
	int n = arr1.size();
    int m = arr2.size();
  
  	// while arr1 and arr2 have elements
  	int i=0;
  	int j=0;
  	while (i < n && j < m) {
      	
      	// if arr1[i] is less than arr2[j], 
      	// advance the index of arr1
      	if(arr1[i] < arr2[j]) {
          	i++;
        } 
      	
      	// if arr1[i] is GREATER than arr2[j], 
      	// advance index of arr2
      	else if (arr1[i] > arr2[j]) {
          	j++;
        } 
      	
      	// if arr1[i] == arr2[j], then this element is in common
      	// and part of the intersection set.
      	//add it to new_set array and move in both arrays
      	else {
          	new_set.push_back(arr1[i]);
          	i++; 
          	j++;
        }
    }
  
    return new_set;
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


void quickSort(vector<int> &arr)
{
    int size = arr.size();
    //quickSortUtil(arr, 0, size - 1);
    quickSortUtil(arr, 0, size - 1);
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


void minMaxMedianSort(int min, int max, int median, vector<int> arr, vector<int>& finalarr)
{

	vector<int> lower;   // hold everything before median
	vector<int> upper;   // hold everything including median and after

	for (int i = 0; i < 7; i++) {
		if (arr[i] >= min && arr[i] < median) {   //dont include median
			lower.push_back(arr[i]);             
		}
	}

	for (int i = 0; i < 7; i++) 
	{
		if (arr[i] >= median && arr[i] <= max) 
		{    //include median
			upper.push_back(arr[i]);
		}
	}

	sort(lower.begin(), lower.end());   // sort each part seperately
	sort(upper.begin(), upper.end());
	
	
	lower.insert(lower.end(), upper.begin(), upper.end()); // combine results
	finalarr = lower; // store in finalarr
}


void minSwapsSort(vector<int> &arr, int specified_value)
{
	int size = arr.size();
	minSwapsUtil(arr, 0, size - 1, specified_value);
}


/**************************
 * main function
**************************/
int main()
{
	cout << endl;
	cout << "******************************" << endl;
	cout << "Task 1: Minimum Swaps" << endl;
	cout << "******************************" << endl;
	
	int specified_value = 5;
    vector<int> arr1 = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10};

    minSwapsSort(arr1, specified_value);

    cout << "Sorted array: ";
    for (int i: arr1)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << "specified_value : " << specified_value << endl;
	cout << "Number of swaps: " << "Unavailable. See min_swap.cpp or min_swap.app" << endl; 
	
	
	cout << endl;
	cout << "******************************" << endl;
	cout << "Task 2: Equation sort" << endl;
	cout << "******************************" << endl;

	int a = 10;
	int e = 2; 
	
	vector<int> arr2 = {3, -2, 1, -4, 0};

	cout << "Let a = 10" << endl;

	//for each element in arr, apply the function and assign
	for (int i = 0; i < arr2.size() - 1; i++)
	{	
		cout << "Index: " << i;
		arr2[i] = aXSquared(a, i, e);
		cout << " Value after a * pow(x, 2): " << arr2[i];
		cout << endl;
	}
	
	selectionSortV2(arr2);

	// cout << endl;
	cout << "Sorted array : ";
	for (int i = 0; i < arr2.size(); i++)
    {
    	cout << arr2[i] << ' ';
    }
    cout << endl;

   	cout << endl;
	cout << "******************************" << endl;
	cout << "Task 3: Binary sort" << endl;
	cout << "******************************" << endl;

	vector<int> arr3 = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1};
    
    int swap_count = binarySort(arr3);

    cout << "Sorted array: " ;
    
    // output sorted array
    for (int i: arr3)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Number of swaps: " << swap_count << endl;


    cout << endl;
	cout << "******************************" << endl;
	cout << "Task 4: Min, max, median sort " << endl;
	cout << "******************************" << endl;

	vector<int> arr4 = { 10, 3, 5, 2, 8, 7, 6 };
	vector<int> finalarr;

	int min = findMin(arr4);
	cout << "The min is: " << min << endl;

	int max = findMax(arr4);
	cout << "The max is: " << max << endl;

	int median = findMedian(arr4);
	cout << "The median is: " << median << endl;

	cout << "Sorted array: ";
	minMaxMedianSort(min, max, median, arr4, finalarr);
	
	for (int i = 0; i < finalarr.size()-1; i++) {
		cout << finalarr[i] << ", " ;
	}
	cout << finalarr[6] << endl;  // get rid of comma on final output


	cout << endl;
	cout << "******************************" << endl;
	cout << "Task 5: Priority bucket" << endl;
	cout << "******************************" << endl;

	vector<string> arr5 = {"Low", "Mid", "High", "Low", "High", "Mid", "Low", "High"};

	// output original array
	cout << "Original array: ";
	for (int i = 0; i < arr5.size(); i++)
	{
		 cout<< arr5[i] << " ";
	}
	cout << endl;

	// translate string values to numeric values so we can use the already-written bucketSort function
	vector<int> numeric;
	for (int i = 0; i < arr5.size(); i++)
	{
		if(arr5[i] == "Low")
		{
			numeric.push_back(3);
		} 
		else if(arr5[i] == "Mid")
		{
			numeric.push_back(2);
		}
		else if(arr5[i] == "High")
		{
			numeric.push_back(1);
		}
	}

	// Output numeric translation/mapping
	cout << "Numeric translation: " ;
	for (int i = 0; i < numeric.size(); i++)
	{
		cout << numeric[i] << " ";
	}
	cout << endl;

	// sort them in place (numeric passed by reference)
	int maxValue = 3;
	bucketSort(numeric, maxValue);

	// translate it back to the string representations
	// This is totally a hack to meet the time dead-line!
	vector<string> named;
	for (int i = 0; i < numeric.size(); i++)
	{
		if (numeric[i] == 1)
		{
			named.push_back("High");
		}
	}

	for (int i = 0; i < numeric.size(); i++)
	{
		if (numeric[i] == 2)
		{
			named.push_back("Mid");
		}
	}
	
	for (int i = 0; i < numeric.size(); i++)
	{
		if (numeric[i] == 3) 
		{
			named.push_back("Low");
		}
	}

	// output sorted numeric translation
	cout << "Sorted numeric translation: ";
	for (int i = 0; i < numeric.size(); i++)
	{
		cout << numeric[i] << " ";
	}
	cout << endl;

	// output sorted original
	cout << "Translated back & sorted: ";
	for (int i = 0; i < named.size(); i++)
	{
		cout << named[i] << " ";
	}
	cout << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "Task 6: Union and intersection" << endl;
	cout << "******************************" << endl;

	vector<int> arr6 = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90, 11, 22, 33, 44, 55};

	vector<int> arr7 = {55, 66, 77, 88, 99, 10, 22, 44, 66, 21, 43, 65, 87, 32, 54};

	// sort the arrays
	quickSort(arr6);
	quickSort(arr7);

	// get union
   	vector<int> union_set = getUnion(arr6, arr7);

    // get intersection
    vector<int> intersection_set = getIntersection(arr6, arr7);

    
    cout << "Union of arr6 and arr7: " << endl;
    for (int i : union_set) 
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Intersection of arr6 and arr7: " << endl;
    for (int i : intersection_set) 
    {
        cout << i << " ";
    }
    cout << endl;

	return 0;
}












