// heapify.cpp

// Apply heapify to the list 3, 9, 5, 4, 8, 1, 5, 2, 7, 6

#include <iostream>
#include <vector>
#include <algorithm>


// This makes a max-heap by maintaining the heap property for a subtree rooted at index i. 
//'n' is the size of the heap
void maxHeapify(std::vector<int>& arr, int n, int i) 
{
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;     // left child index
    int right = 2 * i + 2;    // right child index

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not the root, swap and continue heapifying
    if (largest != i) 
    {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Make a max-heap from an unsorted array
void buildMaxHeap(std::vector<int>& arr) 
{
    int n = arr.size();
    // Start from the last non-leaf node and heapify each one
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        maxHeapify(arr, n, i);
    }
}

int main() {
    std::vector<int> arr = {3, 5, 1, 2, 4, 7, 6};
    buildMaxHeap(arr);

    std::cout << "Heapified array (max-heap): ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
