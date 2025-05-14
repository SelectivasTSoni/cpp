// max_heap_k_largest.cpp

// 8) Find the Kth largest element in an unsorted array using a max-heap. Hint: Create a max-heap from the input array. Then we call remove() operation K-1 times, and the element at the top of the heap is kth largest. Time complexity O(n.log(n)). Assume k=2 and the array: {3, 2, 1, 5, 7, 6, 4}

// see cpp/heap/heapify.cpp for max-heap creations

#include <iostream>
#include <vector>
#include <queue>  // for priority_queue
using namespace std;

int findKthLargest(const vector<int>& nums, int k) {
    // max-heap by default in priority_queue
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    // Remove k-1 elements
    for (int i = 1; i < k; ++i) {
        maxHeap.pop();
    }

    return maxHeap.top(); // k-th largest element
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 7, 6, 4};
    int k = 2;

    int kthLargest = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}
