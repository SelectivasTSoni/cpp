// log_2.cpp

#include <iostream>
#include <cmath>
using namespace std;

int base;
int n;

int log_2(int base, int n)
{
	/*
		"To find a logarithm using a loop in C++, you can repeatedly divide the number by the base until it becomes less than or equal to 1, counting the number of divisions."
	*/

	double answer = 0;
	while (n >= 1)
	{
		n /= base;
		n--;
		answer++;
	}

	return answer;
}


int main()
{
	

	int base = 2;
	int n = 100;

	int answer = log_2(base, n);

	cout << "log_2(n) for n = " << n << " is " << answer << '\n';
	cout << "The answer from <cmath> function log2(n) is " << log2(n) << '\n';
	cout << "This took " << answer << " operations" << '\n';


}
