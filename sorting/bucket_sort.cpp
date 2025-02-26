// priority_bucket_sort.cpp

#include<iostream>
#include<vector>

//#include "sorting_lib.h"

using namespace std;

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


void bucketSort(vector<int> &arr, int maxValue)
{
	int numBuckets = 5;
	bucketSortUtil(arr, maxValue, numBuckets);
}


int main()
{
	//vector<int> array = { 1, 34, 7, 99, 5, 23, 45, 88, 77, 19, 91, 100 };

	vector<string> array = {"Low", "Mid", "High", "Low", "High", "Mid", "Low", "High"};

	// output original array
	cout << "Original array: ";
	for (int i = 0; i < array.size(); i++)
	{
		 cout<< array[i] << " ";
	}
	cout << endl;

	// translate string values to numeric values so we can use the already-written bucketSort function
	vector<int> numeric;
	for (int i = 0; i < array.size(); i++)
	{
		if(array[i] == "Low")
		{
			numeric.push_back(3);
		} 
		else if(array[i] == "Mid")
		{
			numeric.push_back(2);
		}
		else if(array[i] == "High")
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
	
	return 0;
}

