// sliding_min_of_max.cpp

// 4) Given an array of integers, find the minimum of all the maximum values in the sliding windows of length k. Input: [11, 2, 75, 92, 59, 90, 55] and k = 3

// like assignment_7_queue #3

#include <iostream>
#include <deque>
#include <vector>
#include <limits.h>

using namespace std;

int min_of_max_sliding_window(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> max_values;
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        
        // Store max of current window
        if (i >= k - 1)
            max_values.push_back(nums[dq.front()]);
    }
    
    // Find the minimum among the max values of all windows
    int min_of_max = INT_MAX;
    for (int max_val : max_values)
        min_of_max = min(min_of_max, max_val);
    
    return min_of_max;
}

int main() {
    std::vector<int> nums = {11, 2, 75, 92, 77, 86, 59, 90, 55};
    int k = 3;
    cout << "Minimum of all maximums in sliding windows of length k = " << k << ": " << min_of_max_sliding_window(nums, k) << endl;
    return 0;
}