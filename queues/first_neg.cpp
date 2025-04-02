// first_neg.cpp

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;  // Deque to store indices of potential negative numbers in the window

    for (int i = 0; i < arr.size(); i++) {
        // Remove elements from the front of the deque if they are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // If current element is negative, add its index to the deque
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // Once we've processed the first k elements, start adding the result for the sliding window
        if (i >= k - 1) {
            if (!dq.empty()) {
                result.push_back(arr[dq.front()]); // First negative number in the window
            } 
        }
    }
    return result;
}


int main() {
    std::vector<int> arr = {13, -2, -6, 10, -14, 50, 14, 21};
    int k = 3;

    vector<int> result = firstNegativeInWindow(arr, k);

    // Output the result
    cout << "First negative numbers in each sliding window of size k = " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}