// first_last.cpp

// Given a sorted array of integers, find the index of the first and last occurrence of a given value. Hint: Use binary search to find the element smaller than the searched key. Again, find the element greater than the given value. Use : arr = 1, 2, 2, 2, 3, 4, 5}; and target= 2

// We can use binary search because the array is sorted.

#include <iostream>
#include <vector>
using namespace std;

// Generalized binary search for first/last occurrence
int binarySearch(const vector<int>& arr, int target, bool searchFirst) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            if (searchFirst)
                high = mid - 1; // search left
            else
                low = mid + 1;  // search right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int first = binarySearch(arr, target, true);   // search for first
    int last  = binarySearch(arr, target, false);  // search for last

    cout << "First occurrence of " << target << " at index: " << first << endl;
    cout << "Last occurrence of " << target << " at index: " << last << endl;

    return 0;
}

