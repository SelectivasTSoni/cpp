// find_first_repeated.cpp

#include<iostream>
#include<vector>
#include<map>
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


int findFirstRepeated(vector<int> &arr)
{
	int size = arr.size();

	// maps an int key to an int value
	map<int, int> hash_map;

	// for each element in arr...
	for (int i = 0; i < size; i++)
	{
		// find() searches for a key
		if (hash_map.find(arr[i]) != hash_map.end())
		{	
			// if value is found assign value 2
			// this indicates a repeated value
			hash_map[arr[i]] = 2;
		}
		else
		{
			// if key is not found, add value of 1
			// this fills the map with keys and value 1
			hash_map[arr[i]] = 1;
		}
	}

	// loop again
	for (int i = 0; i < size; i++)
	{
		// as soon as we see a 2 value, return key 
		// this is the first repeated value
		if (hash_map[arr[i]] == 2)
		{
			return arr[i];
		}
	}

	return 0; 
}


int sumDistinct(vector<int> &vec)
{
	int size = vec.size();
	int sum = 0;
	map<int, int> hash_map;

	for (int i=0; i < size; i++)
	{
		if ( hash_map.find(vec[i]) == hash_map.end())
		{
			sum += vec[i];
			hash_map[vec[i]] = i;
		}
	}

	return sum;
}


void sepNegPos(vector<int> &arr)
{
	vector<int> pos;
	vector<int> neg;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
		{
			neg.push_back(arr[i]);
		}
		else if (arr[i] >= 0)
		{
			pos.push_back(arr[i]);
		}
	}

	cout << "Postive: ";
	for (int i; i < pos.size(); i++)
	{
		cout <<  pos[i] << " ";
	}
	cout << endl;

	cout << "Negative: ";
	for (int i; i < neg.size(); i++)
	{
		cout << neg[i] << " ";
	}
	cout << endl;
}


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


int main()
{
	cout << "******************" << endl;

	// 1
	cout << "Problem 1: " << endl;
	vector<int> arr1 = {12, 35, 1, 10, 34, 1};
	int second_largest_value = find_second_largest(arr1);	
	cout << "Second largest value: " << second_largest_value << endl;
	
	cout << "******************" << endl;

	// 2
	cout << "Problem 2: " << endl;
	vector<int> arr2 = {1, 2, 4, 5, 6, 3, 7, 2, 4, 6, 7};
	int repeated = findFirstRepeated(arr2);
	cout << "Method employed: Hash table " << endl;
	cout << "First repeated value in arr: " << repeated << endl;

	cout << "******************" << endl;

	// 3
	cout << "Problem 3: " << endl;
	vector<int> vec1 = {1, 2, 3, 2, 4, 3, 5, 6, 7, 7, 2, 4};
	int sum = sumDistinct(vec1);
	// should be 28
	cout << "Sum of distinct elements: " << sum << endl;

	cout << "******************" << endl;

	// 4
	cout << "Problem 4: " << endl;
	vector<int> vec2 = {1, -3, 2, -5, 6, -7, 4};
	sepNegPos(vec2);

	cout << "******************" << endl;

	// 5
	cout << "Problem 5: " << endl;
	int target = 14;
	vector<int> vec3 = {1, 3, 5, 7, 9, 11, 12, 13, 35, 67};
	insertSort(vec3, target);
	cout << "******************" << endl;



	return 0;
}



