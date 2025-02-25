// Given an array of 0s and 1s, sort the array s.t. 1s come before 0s.

#include <iostream>
#include <vector>
#include <algorithm>

#include "sorting_lib.h"

using namespace std;


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
