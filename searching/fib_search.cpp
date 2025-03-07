// fib_search.cpp

#include<iostream>
#include<vector>

using namespace std;

int fibonacciSearch(vector<int> &arr, int target)
{
    /*
    	n is the number of elements in arr
    	target is the value to search for
    	
    	returns index of target or -1
    */   

    int n = arr.size();
    int fn2 = 0;
    int fn1 = 1;
    int fk = fn1 + fn2;

    // Find the greatest fk that is less than n
    while (fk <= n)
    {
    	fn2 = fn1;
        fn1 = fk;
        fk = fn1 + fn2;
    }
        

    int offset = -1;

    while (fn2 >= 0)
    {
        int index = min(offset + fn2, n - 1);

        if (arr[index] < target)
        {
        	// we search to left of fn2
            fk = fn1;
            fn1 = fn2;
            fn2 = fk - fn1;
            offset = index;
        }

        else if (arr[index] > target)
        {
        	// we search to right of fn2
            fk = fn2;
            fn1 = fn1 - fn2;
            fn2 = fk - fn1;
        }
            
        else
        {
        	// arr[index] == target so we return index
            return index;
        }
            
    }

    // Compare the last element of arr with target
    if (fn1 && arr[offset + 1] == target)
    {
    	return offset + 1;
    }

    // target not found in arr
    return -1;
}


int main()
{
	vector<int> arr = {10, 22, 35, 40, 45, 50, 55, 70, 80, 82, 85, 90};

	int rv = fibonacciSearch(arr, 55);

	cout << rv << endl;

	return 0;
}