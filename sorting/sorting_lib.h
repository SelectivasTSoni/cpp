// sorting_lib.h

/*
	Fuction prototypes.
	Function definitions are in sorting_lib.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**************************
 * Utility functions
**************************/

// the given equation for equation_sort()
int aXSquared(int a, int b, int e);


int findMin(vector<int> &arr); 


int findMax(vector<int> &arr);


int findMedian(vector<int> &arr);


// partitions array at lessThanValue with lower values to the left.
void minSwapsUtil(vector<int> &arr, int lower, int upper, int lessThanValue);


// applies quick-sort algorithm to arr
void quickSortUtil(vector<int> &arr, int lower, int upper);


// swaps values at indices i and j
int swap(vector<int> &arr, int i, int j);


//applies bucket-sort to elements of arr
void bucketSortUtil(vector<int> &arr, int maxValue, int numBuckets);




/**************************
 * sorting functions
**************************/

int binarySort(vector<int> &arr);

void bucketSort(vector<int> &arr, int maxValue)

void minSwapsSort(vector<int> &arr, int lessThanValue);

void quickSort(vector<int> &arr);

void selectionSort(vector<int> &arr);

void selectionSortV2(vector<int> &arr);



