#include <iostream>
#include <vector>
using namespace std;


// the & references the variable arr using memory location.
void swap(vector<int> &arr, int i, int j)
{
    // this just swaps i and j
    // i goes to temp, j goes to i, i (== temp) goes to j
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// upper and lower are array indices
void quickSortUtil(vector<int> &arr, int lower, int upper)
{
    if (upper <= lower)
    {
        return;
    }

    int pivot = arr[lower];
    int start = lower;
    int stop = upper;

    // The while loops move through the array indices
    while (lower < upper) {
        while (arr[lower] <= pivot && lower < upper) {
            lower++;
        }

        while (arr[upper] > pivot && lower <= upper) {
            upper--;
        }

        if (lower < upper) {
            swap(arr, upper, lower);
        }
    }

    swap(arr, upper, start); // upper is the pivot position
    quickSortUtil(arr, start, upper-1); //pivot-1 is upper for left sub-array.
    quickSortUtil(arr, upper+1, stop); //pivot+1 is lower for right sub-array.
}


void quicksort(vector<int> &arr) 
{
    // get the size of our array
    int size = arr.size();

    // take the array, first index, and last index position (size - 1)
    quickSortUtil(arr, 0, size - 1);
}


void minSwap(vector<int> &arr) {
    // get the size of our array
    int size = arr.size();

    // take the array, first index, and last index position (size - 1)
    quickSortUtil(arr, 0, size - 1);
}



int main()
{
    // make an array to sort
    vector<int> my_vector = {20, 1, 2, 5, 30, 40, 50, 7, 8, 9};

    // call quicksort() function
    quicksort(my_vector);

    // output a sorted array
    for (int i: my_vector)
        cout << i << '\n';

    return 0;
}



