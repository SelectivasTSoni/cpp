// min_heap.cpp

// 7) Given the sequence: 3, 9, 5, 4, 8, 1, 5, 2, 7, 6, construct a min-heap using the CreateHeap function.

// see cpp/heap/min_heap.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Heapify down from index i
void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;        // Start with current node
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // Compare with left child
    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    // Compare with right child
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    // If a smaller child was found, swap and recurse
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Create a min-heap from unsorted array
void createMinHeap(vector<int>& heap) {
    int n = heap.size();
    // Start from the last internal node and heapify down
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }
}


int main() {
    vector<int> heap = {3, 9, 5, 4, 8, 1, 5, 2, 7, 6};

    createMinHeap(heap);

    cout << "Min-heap array: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    return 0;
}
