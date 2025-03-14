// sep_neg_pos.cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	In a given list of positive and negative numbers, write a program to separate -negative numbers from the
	positive numbers.
*/


void sepNegPos(vector<int> &arr)
{
	vector<int> pos;
	vector<int> neg;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
		{
			neg.push_back(arr[i]);
		}
		else if (arr[i] >= 0)
		{
			pos.push_back(arr[i]);
		}
	}

	cout << "Postive: ";
	for (int i=0; i < pos.size(); i++)
	{
		cout <<  pos[i] << " ";
	}
	cout << endl;

	cout << "Negative: ";
	for (int i=0; i < neg.size(); i++)
	{
		cout << neg[i] << " ";
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
	vector<int> arr = {1, -3, 2, -5, 6, -7, 4};
	sepNegPos(arr);

	return 0;
}