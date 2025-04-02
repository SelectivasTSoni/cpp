// first_neg.cpp

#include <iostream>
#include <queue>


// First negative in sliding windows: Given an array of integers, find the first negative number in all sliding windows of length k. Input: Arr = [13, -2, -6, 10, -14, 50, 14, 21], k = 3

// using force
void maxSlidingWindowsForce(std::vector<int> &arr, int size, int k) 
{
	// until i is size - k, at the last window
	// this gets us through the array
    for (int i = 0; i < size - k + 1; i++) 
    {
        //int max = arr[i];
        int first_neg;
        
        // until j == k...
        // this loops through each k sized window.
        for (int j = 1; j < k; j++) 
        {
        	// get the max in the the window
        	// max = std::max(max, arr[i + j]);

        	// get the first negative in the window
        	if (j < 0)
        	{
        		first_neg = j;
        		break; // exit inner for-loop
        	}
        	
		}
        
        // outputs the max in each window
        // std::cout << max << " ";

        // outputs first negative in window
        std::cout << first_neg << " ";
    }
    std::cout << std::endl;
}


// using a double ended queue
void firstNegSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::deque<int> que;
    
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
		
		// Largest value in window of size k is at index que[0]
		// It is displayed to the screen.
		if (i >= (k - 1))
		    std::cout << arr[que.front()] << " ";

	}
	std::cout << std::endl;
}


int main() {
    std::vector<int> arr = {13, -2, -6, 10, -14, 50, 14, 21};
    int k = 3;
    firstNegSlidingWindows(arr, 8, 3);

    
    return 0;
}