// quick_sort.cpp

#include<iostream>
#include<vector>

using namespace std;

// swaps values at indices i and j
void swap(vector<int> &arr, int i, int j) 
{
    int temp = arr[i];  // put value at i into temp
    arr[i] = arr[j];    // put value at j into i
    arr[j] = temp;      // put value at i into j
}

// Lower and upper are simply values that track index positions
void quickSortUtil(vector<int> &arr, int lower, int upper)
{
    // upper can't be less than lower, because all the condition 
    // checks assume is higher. Our experiement with upper > lower 
    // resulted in ...
    if (upper <= lower)
    {
        return;
    }

    int pivot = arr[lower];
    int start = lower;  
    int stop = upper;

    while (lower < upper)
    {   
        // This loop breaks when lower is above the pivot.
        while (arr[lower] <= pivot && lower < upper)
        {
            // this executes until arr[lower] is above pivot position...
            lower++;
            
        }
        // This loop breaks when upper is equal to the pivot
        while (arr[upper] > pivot && lower <= upper)
        {
            // upper advances until it is at the pivot position...
            upper--;
            // so you have the lower index above the pivot, and upper index is at the pivot, then..
        }
        //...so if lower is a smaller value than upper...
        if (lower < upper) 
        {   
            // the VALUES at upper and lower switch places...
            swap(arr, upper, lower);
            // In swap(), the VALUES are exchanged which is what accomplishes the sorting.
        }

        // this process continues until lower == upper...
    }
    // ...then the VALUES of upper and lower (==start) switch, which sets upper as the pivot
    swap(arr, upper, start); // upper is the pivot position

    // and we call quickSortUtil() on left sub-array... 
    quickSortUtil(arr, start, upper - 1); //pivot-1 is upper for left sub-array.
    // ...then right sub-array...
    quickSortUtil(arr, upper + 1, stop); //pivot+1 is lower for right sub-array.

}


void quickSort(vector<int> &arr)
{
    int size = arr.size();
    //quickSortUtil(arr, 0, size - 1);
    quickSortUtil(arr, 0, size - 1);
}


int main()
{

    vector<int> arr = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10, 13};

    cout << "Original Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    quickSort(arr);

    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
   	cout << endl;

    return 0;
}