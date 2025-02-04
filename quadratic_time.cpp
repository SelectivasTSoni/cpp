#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 100;
	int square = 0;
	int operations = 0;

	/*
		for n^2 means (n * n). We use (n + n) n times,
		Example: n = 3, so n^2 = 3 + 3 + 3 = 9 
		So for each n, we add n+n
	*/
	for (int i=0; i < n; ++i)
	{
		square += n;
		++operations;
	}

	cout << "The square of " << n << " is: " << square << '\n';
	cout << "This took " << operations << " operations" << '\n';
}