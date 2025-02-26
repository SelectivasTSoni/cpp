// Given an array of 0s and 1s, sort the array s.t. 1s come before 0s.

#include <iostream>
#include <vector>
#include <algorithm>

#include "sorting_lib.h"

using namespace std;


int binarySort(vector<int> &arr) 
{
    int size = arr.size();
    int left = 0;
    int right = size - 1;
    int swap_count = 0;

    // continue until left and right pointers meet
    while (left < right) 
    {
        // Slides have an error here. 
        // What follows is correct:
        //move left pointer right while encountering 1's
        while (left < right && arr[left] == 1) 
        {
            left += 1;
        }
        // move right pointer left while encountering 0's
        while (left < right && arr[right] == 0)
        {
            right -= 1;
        }

        // Swap the elements if left < right
        // Slides have (left <)
        if (left < right) 
        {
            swap(arr[left], arr[right]);
            swap_count++;
        }
    }

    return swap_count;
}


int main () {
    vector<int> arr = {0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1};
    
    int swap_count = binarySort(arr);

    cout << "Sorted array: " ;
    
    // output sorted array
    for (int i: arr)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Number of swaps: " << swap_count << endl;

    return 0;
}
