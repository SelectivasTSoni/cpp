// heap_complete.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Heapify
void maxHeapify(vector<int>& arr, int n, int i) 
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
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Make a max-heap from an unsorted array
void buildMaxHeap(vector<int>& arr) 
{
    int n = arr.size();
    // Start from the last non-leaf node and heapify each one
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        maxHeapify(arr, n, i);
    }
}


// min_heap
void minHeapify(vector<int>& arr, int n, int i) 
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
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Make a min-heap from an unsorted array
void buildMinHeap(vector<int>& arr) 
{
    int n = arr.size();
    // Start from the last non-leaf node and heapify each one
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        minHeapify(arr, n, i);
    }
}


int main() {
	// Max
	cout << "*******************************" << endl;
    cout << "Apply heapify(): " << endl;
    cout << "*******************************" << endl;
    vector<int> arr = {3, 9, 5, 4, 8, 1, 5, 2, 7, 6};
    buildMaxHeap(arr);
    cout << "Heapified array (max-heap): ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;


    //min
    cout << endl;
    cout << "*******************************" << endl;
    cout << "Construct min-heap: " << endl;
    cout << "*******************************" << endl;
    vector<int> arr2 = {3, 9, 5, 4, 8, 1, 5, 2, 7, 6};
    buildMinHeap(arr2);
    cout << "Min-heap array: ";
    for (int num : arr2) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
