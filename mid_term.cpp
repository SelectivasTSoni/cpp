// mid_term.cpp

#include <iostream>
#include <vector>
#include <cmath>
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


// utility for 3) and 4)
double curve_function(double x)
{
	double y = 2 * pow(x, 4) - 3 * pow(x, 3) + 5 * pow(x, 2) - x + 7;
	return y;
}

// 3)
double derivative(double x)
{
	/* 
		slope, m = (y2 - y1) / (x2 - x1)
	*/

	// select x2 very near x1
	double x2 = x + 0.0000000001;
	
	double y1 = curve_function(x);
	double y2 = curve_function(x2);

	double m = (y2 - y1) / (x2 - x);

	cout << "Problem 3: "<< endl;
	cout << "-----------" << endl;
	cout << "The slope is : " << m << '\n';
	cout << endl;

	return m;
}


// 4)
double x;
double y;
double start;
double end;
double n_rectangles;
double width;
double areaUnderCurve;
double length;
double rectangleArea;
double area;

double integrate(double start, double end, double n_rectangles)
{
	/* 
		Area under the curve is the sum of the areas of the rectangles under the curve. More rectangles give closer approximation of the true area.

		Here, we consider x values to be the point at the middle of the rectangle. So if we have n rectangles, the x value evolves according to:

			w/2 + w+w/2 + 2w+w/2 + ... + nw+w/2

		so something like this

			for (int i=0; i<n_rectangles; ++i){
				x = i * width + width/2;
			}

		gives us values for x at the top center of each rectangle under the curve.

		Our y values come from the curve_function(x) which takes x as an argument.
	*/

	/* 
		The width of each rectangle is the width of the region under the curve divided by the number of rectangles. Start and end are values of x: 
	*/
	width = (end - start)/n_rectangles;

	/* 
		This is the accumulator. It aggregates the areas of the individual rectangles into the total area. We initialize it to 0.0.
	*/ 
	areaUnderCurve = 0.0;

	/* 
		For each rectangle:

		1. Get our x value
		2. Get our y value from curve_function()
		3. Calculate area of rectangle i
		4. Add area of i to the accumulator
	*/
	for (int i=0; i<n_rectangles; ++i)
	{
		x = (i * width) + (width/2);
		y = length = curve_function(x);
		rectangleArea = length * width;
		areaUnderCurve += rectangleArea;
	}

	cout << "Problem 4: "<< endl;
	cout << "-----------" << endl;
	cout << fixed << "Number of Rectangles: " << n_rectangles << endl;
	cout << fixed << "Rectangle width: " << width << endl;
	cout << fixed << "Area under the curve: " << areaUnderCurve << endl;
	cout << endl;

 
	return areaUnderCurve;
}


// 6) What is the time complexity of the function below? Explain
int time_complexity(int n)
{
	int iterations = 0;
	int i, j, m = 0;
	for (i = 1; i <= n; i *= 5) 
		{
			iterations++;

			for (j = 0; j <= i; j++) 
			{
				iterations++;
				m += 1;
			}
		}

		cout << "Problem 6: "<< endl;
		cout << "-----------" << endl;
		cout << "n =  " << n << endl;
		cout << "Number of interations: " << iterations << endl;
		cout << "Increments performed by inner loop: " << m << endl;
		cout << endl;

	return m;
}


// 7) Given the array of positive integers, {3, 2, 5, 10, 7}, find the maximum product under the constraint that no two elements should be adjacent. 10 points
int max_product_non_adjacent(vector<int> arr)
{
	/*
		Adjacent means i-1, i, or i+1 for each i
	*/

	int max = 0;
	int non_adjacent_product = 0;
	int iterations = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		iterations++;

		for (int j = 0; j < arr.size(); j++)
		{
			iterations++;

			if (j != i-1 && j != i && j != i+1)
			{
				non_adjacent_product = arr[i] * arr[j];

				if (non_adjacent_product > max)
				{
					max = non_adjacent_product;
				}
			}
		}
	}
	
	cout << "Problem 7: "<< endl;
	cout << "-----------" << endl;
	cout << "For n = " << arr.size() <<", this functions took " << iterations << " iterations" << '\n';
	cout << "Max product of non-adjacent integers: " << max << '\n';
	cout << endl;

	return max;
}


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
    quickSortUtil(arr, 0, size - 1);
}


int binarySearch(vector<int> &arr, int value)
{
	int size = arr.size();
	int low = 0;
	int high = size -1; 
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (arr[mid] == value)
		{
			// this returns the value
			//return arr[mid];
			//this returns the index position
			return mid;

		} 
		else if (arr[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid -1;
		}
	}

	return 0;
}


// 8) Given an array of integers, {12, 3, 5, 7, 19, 1}, write a C++ function that performs the following tasks: (a) Sort the array in ascending order using the Quick Sort algorithm. (b) After sorting, write a function to perform a binary search on the sorted array. The binary search should return the index of the element if found, or a message saying ”Element not found in the array” if the element is not in the array. 20 points
int prob_8 (vector<int> &arr, int value)
{
	// quick-sort array in place
	quickSort(arr);

	// use binary search, return index or "Element not found in the array."
	int index = binarySearch(arr, value);

	cout << "Problem 8: "<< endl;
	cout << "-----------" << endl;
	
	if (index == 0)
	{
		cout << "Index position of given value " << value<<": " << "Element not found in the array" << endl;
	}
	else
	{
		cout << "Index position of given value " << value<<": " << index << endl;
	}
	cout << endl;

	return 0;
}


// 9) You are given a sorted array of integers, {10, 22, 35, 40, 45, 50, 55, 70, 80, 82, 85, 90}. Implement the Fibonacci Search algorithm in C++ to find the index of a target value in the array. The target value is 55. 15 points
int prob_9 (vector<int> &arr, int target)
{
	int index = fibonacciSearch(arr, target);
	cout << "Problem 9: "<< endl;
	cout << "-----------" << endl;	
	cout << "The index of the target value: " << index;
	cout << endl;

	return index;
}


// 10) You are given a singly linked list with values: 1 2 3 4 5. Your task is to reverse the list and print the reversed linked list. 10 points
int prob_10 (vector<int> arr)
{

	
	cout << "Problem 10: "<< endl;
	cout << "-----------" << endl;
	cout << endl;

	return 0;
}


class LinkedList 
{
	private:
	    struct Node 
	    {
	        int value;
			Node *next;
	        Node(int v, Node *n = nullptr);
	    };
		Node *head;
		int length;
	
	public:
	    LinkedList();

	    // method declarations
	    virtual int size();
	    virtual bool isEmpty();
	    virtual int peek();
	    virtual void addHead(int value);
	    virtual int removeHead();
	    
	    // Other linked list methods.
	    virtual bool find(int data);
	    virtual void addTail(int value);
	    virtual void print();
	    virtual void reverse();


};


// method definitions
LinkedList::Node::Node(int v, Node *n) 
{
	value = v;
	next = n; 
}


LinkedList::LinkedList()
{
    head = nullptr;
	length = 0; 
}


int LinkedList::size()
{
    return length;
}


bool LinkedList::isEmpty() 
{
    return length == 0;
}


int LinkedList::peek() 
{
    if (isEmpty()) 
    {
        throw("EmptyListException");
    }

    return head -> value;
}


void LinkedList::addHead(int value) 
{
    head = new Node(value, head);
    length++; 
}


int LinkedList::removeHead() 
{
    if (isEmpty()) {
        throw("EmptyListException");
    }
    
    Node *deleteMe = head;
    int value = head->value;
    head = head->next;
    length--;
    
    delete deleteMe;
    
    return value;
}


bool LinkedList::find(int data)
{
    Node *temp = head;
    while (temp != nullptr) 
    {
        if (temp->value == data) 
        {
            return true;
		}
        
        temp = temp->next;
    }

    return false;
}


void LinkedList::addTail(int value) 
{
    Node *newNode = new Node(value);
    Node *curr = head;
    if (head == nullptr)
    {
        head = newNode;
    }
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}


void LinkedList::print() 
{
    Node *temp = head;
    while (temp != nullptr) 
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}


void LinkedList::reverse() 
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    
    while (curr != nullptr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
	}
	
	head = prev; 
}


int main()
{
	// 1
	cout << "******************" << endl;
	cout << "Problem 1: "<< endl;
	cout << "-----------" << endl;
	cout << "Answered in .pdf " << endl;
	cout << endl;
	cout << "******************" << endl;
	cout << endl;


	// 2
	cout << "Problem 2: "<< endl;
	cout << "-----------" << endl;
	cout << "Answered in .pdf " << endl;
	cout << endl;
	cout << "******************" << endl;
	cout << endl;


	// 3
	double x = 2.0;
	double slope = derivative(x);
	cout << "******************" << endl;
	cout << endl;


	// 4
	double start = 2;
	double end = 6;
	int n_rectangles = 100000;
	double areaUnderCurve = integrate(start, end, n_rectangles);
	cout << "******************" << endl;
	cout << endl;

	// 5
	cout << "Problem 5: "<< endl;
	cout << "-----------" << endl;
	cout << "Answered in .pdf " << endl;
	cout << endl;
	cout << "******************" << endl;
	cout << endl;


	// 6 
	int n = 100;
	int m = time_complexity(n);
	cout << "******************" << endl;
	cout << endl;


	// 7
	vector<int> arr = {3, 2, 5, 10, 7};
	int max = max_product_non_adjacent(arr);
	cout << "******************" << endl;
	cout << endl;


	//8
	vector<int> arr2 = {12, 3, 5, 7, 19, 1};
	prob_8 (arr2, 19);
	cout << "******************" << endl;
	cout << endl;


	//9
	vector<int> arr3 = {10, 22, 35, 40, 45, 50, 55, 70, 80, 82, 85, 90};
	// int index = fibonacciSearch(arr, 55);
	prob_9(arr3, 55);
	cout << endl;
	cout << "******************" << endl;
	cout << endl;

	
	//10
	cout << "Problem 10: "<< endl;
	cout << "-----------" << endl;
	cout << endl;
	
	// instantiate a LinkedList object
	LinkedList *ll = new LinkedList();

	// call addHead method to add items
    ll->addHead(5);
    ll->addHead(4);
    ll->addHead(3);
    ll->addHead(2);
    ll->addHead(1);

    // call print method
    ll->print();

    //call reverse method
    ll->reverse();

    // call print to see reversed linked list
    ll->print();
	
	cout << "******************" << endl;
	cout << endl;


	return 0;
}
