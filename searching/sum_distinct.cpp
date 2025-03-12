// sum_distinct.cpp

#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
	This is a variation on findFirstRepeated(). 
	
*/

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


int main(int argc, char const *argv[])
{
	vector<int> vec = {1, 2, 3, 2, 4, 3, 5, 6, 7, 7, 2, 4};
	int sum = sumDistinct(vec);
	// should be 28
	cout << "Sum of distinct elements: " << sum << endl;

	return 0;
}