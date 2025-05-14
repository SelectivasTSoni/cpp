// check_anagrams.cpp

// 10) In given two strings A and B, find whether any anagram of string A is a substring of string B. For example: If A = xyz and B = afdgzyxksldfm then the program should return True. If A = xyaz and B = afdgzyxksldfm then the program should return False.

// like assignmen_12_strings #4

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool containsAnagram(const string& A, const string& B)
{
	string anagram = A;
    sort(anagram.begin(), anagram.end());

    do {
        if (B.find(anagram) != string::npos) {
            return true;
        }
    } while (next_permutation(anagram.begin(), anagram.end()));

    return false;
}


int main() {
	cout << "***********************************************" << endl;
	cout << "An anagram is a rearrangement of all the letters" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "string A = ldf" << endl;
	cout << "string B = afdgzyxksldfmdssdciowheo" << endl;
	cout <<	"Anagram substring!" << endl;
	cout << "Output should be true." << endl;

	string A = "ldf";
	string B = "afdgzyxksldfmdssdciowheo";
    if (containsAnagram(A, B)) 
    {
        cout << "True\n";
    } 
    else 
    {
        cout << "False\n";
    }

    cout << "However" << endl;
	cout << endl;
	cout << "string A = ldf"<< endl;
	cout << "string B = " << endl;
	cout <<	"No anagram substring!" << endl;
	cout << "Output should be False." << endl;

    string a = "LDF";
    string b = "";
    if (containsAnagram(a, b)) 
    {
        cout << "True\n";
    } 
    else 
    {
        cout << "False\n";
    }
    return 0;
}