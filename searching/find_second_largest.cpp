// find_second_largest.cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int find_second_largest(vector<int> &arr)
{
	// we sort first, no comparisons required
	int size = arr.size();

	int last_index = 0;
	for (int i = 0; i < size; ++i)
	{
		//cout << i << endl;
		last_index = i; 
	}

	sort(arr.begin(), arr.end());

	int second_largest_value = arr[last_index - 1];

	return second_largest_value;
}

int main(int argc, char const *argv[])
{
	vector<int> arr = {12, 35, 1, 10, 34, 1};
	int second_largest_value = find_second_largest(arr);	
	cout << "Second largest value: " << second_largest_value << endl;

	return 0;
}