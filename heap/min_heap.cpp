// min_heap.cpp

// Write a simple C++ program to construct a min-heap from the following sequence: 3, 9, 5, 4, 8, 1, 5, 2, 7, 6. Use the CreateHeap() function to build the min-heap.

#include <iostream>
#include <vector>
#include <algorithm>

// Maintain the min-heap property of tree rooted at index i
// 'n' is the size of the heap
void minHeapify(std::vector<int>& arr, int n, int i) 
{
    int smallest = i;        // Initialize smallest as root
    int left = 2 * i + 1;      // left child index
    int right = 2 * i + 2;     // right child index

    // If left child exists and is smaller than root
    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    // If right child exists and is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    // If smallest is not the root, swap and continue heapifying
    if (smallest != i) 
    {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Make a min-heap from an unsorted array
void buildMinHeap(std::vector<int>& arr) 
{
    int n = arr.size();
    // Start from the last non-leaf node and heapify each one
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        minHeapify(arr, n, i);
    }
}

int main() {
    std::vector<int> arr = {3, 5, 1, 2, 4, 7, 6};
    buildMinHeap(arr);

    std::cout << "Min-heap array: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}