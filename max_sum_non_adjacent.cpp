//max_sum_non_adjacent.cpp

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int int_array[4];

int max_sum_non_adjacent(int int_array[4])
{
	/*
		Adjacent means i-1, i, or i+1 for each i
	*/

	int max = 0;
	int non_adjacent_sum = 0;
	int operations = 0;

	for (int i = 0; i < 4; i++)
	{
		operations++;

		for (int j = 0; j < 4; j++)
		{
			operations++;

			if (j != i-1 && j != i && j != i+1)
			{
				non_adjacent_sum = int_array[i] + int_array[j];

				if (non_adjacent_sum > max)
				{
					max = non_adjacent_sum;
				}
			}
		}
	}

	cout << "For n = 4, this functions took " << operations << " iterations" << '\n';

	return max;
}


int main()
{
	int int_array[4] = {3, 5, 10, 7};

	int max = max_sum_non_adjacent(int_array);

	cout << "Max sum of non-adjacent integers: " << max << '\n';

	return 0;

	
}


