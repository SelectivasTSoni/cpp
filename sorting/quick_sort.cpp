// quick_sort.cpp

#include<iostream>
#include<vector>

#include "sorting_lib.h"

using namespace std;


int main()
{
    vector<int> arr = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10};

    quickSort(arr);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << i << '\n';
    }

   	cout << endl;

    return 0;
}