// priority_bucket_sort.cpp

#include<iostream>
#include<vector>

#include "sorting_lib.h"

using namespace std;

//applies bucket-sort to elements of arr
void bucketSortUtil(vector<int> &arr, int maxValue, int numBuckets);
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

	int div = ceil(static_cast<double>(maxValue)/numBuckets);

}


void bucketSort(vector<int> &arr, int maxValue);
{
	//
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

