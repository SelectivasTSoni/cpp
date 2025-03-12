// insert_sort.cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	Find a number, 14, in a sorted list. If found, return the index. If not found, insert it into the array. fin
*/


int insertSort(vector<int> &vec, int target)
{
	int size = vec.size();

	// use i=1 so we can go i-1 to start. See below
	for (int i = 1; i < size; i++)
	{
		// is target in vec?
		if (vec[i] == target)
		{
			cout << "Vector already contains target value: " << endl;
			for (int i; i < vec.size(); i++)
			{
				cout <<  vec[i] << " ";
			}
			cout << endl;

			return i;
		}

		// j stays one index behind i
		int j = i - 1; 

		// at each element, check i < than target
		if (vec[j] < target && vec[i] > target)
		{
			// int position = i;
			// this is used to print the position of the insert
			//int position = (vec.begin() + (i));

			// insert postion requires a constant
			// So this doesn't work:
			// vec.insert(position, target);
			// but this does:
			vec.insert((vec.begin() + (i)), target);
			// new element get inserted before position
			cout << "The value " << target << " was inserted at index: " << i << endl;
			
		}
	}	

	cout << "Vector: ";
	for (int i; i < vec.size(); i++)
	{
		cout <<  vec[i] << " ";
	}
	cout << endl;

	return 0;
}


int main(int argc, char const *argv[])
{
	int target = 14;
	vector<int> vec = {1, 3, 5, 7, 9, 11, 12, 13, 35, 67};
	insertSort(vec, target);

	return 0;
}