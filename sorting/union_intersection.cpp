// union_intersection.cpp

#include<iostream>
#include<vector>

using namespace std;


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


// swaps values at indices i and j
void swap(vector<int> &arr, int i, int j) 
{
	int temp = arr[i];	// put value at i into temp
	arr[i] = arr[j];	// put value at j into i
	arr[j] = temp;		// put value at i into j
}


// sort functions. placed here to avoid compilation 
// and linking of multiple .cpp files
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


void quickSort(vector<int> &arr)
{
	int size = arr.size();
	quickSortUtil(arr, 0, size - 1);
}



int main() {
  
    vector<int> arr1 = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90, 11, 22, 33, 44, 55};

	vector<int> arr2 = {55, 66, 77, 88, 99, 10, 22, 44, 66, 21, 43, 65, 87, 32, 54};

	// sort the arrays
	quickSort(arr1);
	quickSort(arr2);

	// get union
   	vector<int> union_set = getUnion(arr1, arr2);

    // get intersection
    vector<int> intersection_set = getIntersection(arr1, arr2);

    
    cout << "Union of arr1 and arr2: " << endl;
    for (int i : union_set) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Intersection of arr1 and arr2: " << endl;
    for (int i : intersection_set) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

