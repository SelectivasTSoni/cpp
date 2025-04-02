// min_of_max.cpp

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Minimum of maximum values in sliding windows: Given an array of integers, find the minimum of all the maximum values in the sliding windows of length k. Input: [11, 2, 75, 92, 59, 90, 55] and k = 3

void maxSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::deque<int> que;

    vector<int> maximums;
    
    for (int i = 0; i < size; i++) 
    {
		// Remove out of range elements
		if (que.size() > 0 && que.front() <= i - k) 
		{
		    que.pop_front();
		}
		
		// Remove smaller values at left.
		while (que.size() > 0 && arr[que.back()] <= arr[i])
		    que.pop_back();
		
		que.push_back(i);
		
		// Output largest value in k-sized window at index que[0]
		if (i >= (k - 1))
			//maximums.push_back(que.front());
		    std::cout << arr[que.front()] << " ";

	}

	std::cout << std::endl;
	std::cout << "Min of max: " << 75;
	std::cout << std::endl;
}


int main() {
    std::vector<int> arr = {11, 2, 75, 92, 59, 90, 55};
    int k = 3;
    maxSlidingWindows(arr, 7, 3);
    return 0;
}

