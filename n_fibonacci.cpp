// n_fibonacci.cpp

// Given n elements, display the Fibonacci series with n elements using both top-down and bottom-up approaches.

// top-down: recursion + memorization (dynamic programming with cache)

// bottom-up: iterative tabulation


#include <iostream>
#include <vector>
using namespace std;

// Version 1
// int fibTopDown(int n, vector<int>& memo) {
//     if (n <= 1) 
//     	return n;
//     // in main, vector elements are initialized to the -1.
//     // This is a sentinel value meaning: "this number has not been computed yet."
//     if (memo[n] != -1) 		// if there is value in memo[n]
//     	return memo[n];		// return it
//     // if not calculate and assign to memo[n]
//     memo[n] = fibTopDown(n - 1, memo) + fibTopDown(n - 2, memo);
//     return memo[n];
// }


// Internal helper with memo passed as reference
int fibTopDownHelper(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibTopDownHelper(n - 1, memo) + fibTopDownHelper(n - 2, memo);
    return memo[n];
}

// Public interface: self-contained version
void fibTopDown2(int n) {
    if (n == 0) return;

    vector<int> memo(n, -1);
    cout << "Top-Down Fibonacci:\n";
    for (int i = 0; i < n; ++i) {
        cout << fibTopDownHelper(i, memo) << " ";
    }
    cout << endl;
}


void fibBottomUp(int n) {
    if (n == 0) 
    	return;
    vector<int> dp(n);
    dp[0] = 0;
    if (n > 1) 
    	dp[1] = 1;

    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Bottom-Up Fibonacci:\n";
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
}


int main()
{
	// required for Version 1
	// int n = 10;
	// vector<int> memo(n, -1);
	// cout << "Top-Down Fibonacci:\n";
	// for (int i = 0; i < n; ++i) {
	// 	cout << fibTopDown(i, memo) << " ";
	// }
	// cout << endl;

	int n;
    cout << "Enter number of Fibonacci elements: " << endl;
    cout << "Integer overflow occurs for n > 46 " << endl;
    cin >> n;

    fibTopDown2(n);
	fibBottomUp(n);

	return 0;
}