// find_first_repeated.cpp

#include<iostream>
#include<vector>
#include<map>

using namespace std;


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

int main(int argc, char const *argv[])
{
	vector<int> arr = {1, 2, 4, 5, 6, 3, 7, 2, 4, 6, 7};

	int repeated = findFirstRepeated(arr);

	cout << "First repeated value in arr: " << repeated << endl;

	return 0;
}



