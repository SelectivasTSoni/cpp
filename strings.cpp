// strings.cpp

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
	1. In a given string, find the longest substring without repeating characters. Use the string : abcabcbb
*/
string longestSubstring(const string& s) 
{
    unordered_map<char, int> lastIndex;
    
    int start = 0, maxLen = 0, maxStart = 0;

    for (int end = 0; end < s.length(); ++end) 
    {
        char c = s[end];

        // If character has been seen and is within the current window, move start
        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= start) 
        {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = end;

        if (end - start + 1 > maxLen) 
        {
            maxLen = end - start + 1;
            maxStart = start;
        }
    }

    return s.substr(maxStart, maxLen);
}


/*
	2. Write a code that finds if a string is a palindrome. It should also return true for the inputs below:
		Stella won no wallets.
		No, it is open in one position.
		Rise to vote, Sir.
		Won't lovers revolt now?
*/
int checkPalindrome(const string& s) 
{
    int i = 0, j = int(s.size()) - 1;
    while (i < j) 
    {
        // advance i to next alphabetic character
        while (i < j && !isalpha(static_cast<unsigned char>(s[i]))) 
        {
            ++i;
        }
        // advance j to previous alphabetic character
        while (i < j && !isalpha(static_cast<unsigned char>(s[j]))) 
        {
            --j;
        }
        // compare characters (case-insensitive)
        if (i < j) 
        {
        	cout << s[i] << " vs " << s[j] << "\n";

            if (tolower(static_cast<unsigned char>(s[i])) 
                != tolower(static_cast<unsigned char>(s[j]))) 
            {
                return 0;
            }

            ++i; 
            --j;
        }
    }
    return 1;
}


/*
	3. Write an expansion function that will take an input string like 1..5, 8, 11..14, 18, 20, 26..30 and will print
	1,2,3,4,5,8,11,12,13,14,18,20,26,27,28,29,30.
*/
vector<int> expandRanges(const string& input) 
{
    vector<int> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) 
    {
        // Remove leading/trailing whitespace
        size_t start = token.find_first_not_of(" \t");
        size_t end   = token.find_last_not_of(" \t");
        
        if (start == string::npos) 
        	continue;  // empty token
        
        string trimmed = token.substr(start, end - start + 1);

        // Find range delimiter ".."
        size_t dots = trimmed.find("..");
        if (dots != string::npos) 
        {
            int lo = stoi(trimmed.substr(0, dots));
            int hi = stoi(trimmed.substr(dots + 2));
            if (lo <= hi) 
            {
                for (int i = lo; i <= hi; ++i)
                	result.push_back(i);
            } else 
            {
                for (int i = lo; i >= hi; --i) 
                	result.push_back(i);
            }
        } 
        else 
        {
            result.push_back(stoi(trimmed));
        }
    }

    return result;
}

void printExpansion(const string& input) 
{
    vector<int> values = expandRanges(input);
    for (size_t i = 0; i < values.size(); ++i) 
    {
        cout << values[i];
        if (i + 1 < values.size()) 
        	cout << ",";
    }
    cout << "\n";
}


/*
	4. In given two strings A and B, find whether any anagram of string A is a substring of string B. For example: If A = xyz and B = afdgzyxsldfm then the program should return true.
*/
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



int main() 
{
	cout << "*******************************" << endl;
    cout << "Problem 1: " << endl;
    cout << "*******************************" << endl;
    string in = "abcabcbb";
    string res = longestSubstring(in);
    cout << "Longest substring without repeating characters is: " << res << endl;
    cout << endl;

    cout << "*******************************" << endl;
    cout << "Problem 2: " << endl;
    cout << "*******************************" << endl;

    vector<string> sentences = 
    {
        "Stella won no wallets.",
        "No, it is open in one position.",
        "Rise to vote, Sir.",
        "Won't lovers revolt now?"
    };

    for (const auto& s : sentences) 
    {
    	bool t = checkPalindrome(s);
    	if (t == 1)
    	{
        	cout << "String is a palindrome! " << endl;
    	}
    	else
    	{
    		cout << "Not palindrome! " << endl;
    	}
    }

    cout << "********************" << endl;
    cout << "debugging code below" << endl;
    string s = "No, it is open in one position";
    cout << checkPalindrome(s) << "\n";  // should print 1


    cout << "*******************************" << endl;
    cout << "Problem 3: " << endl;
    cout << "*******************************" << endl;
    string input = "1..5, 8, 11..14, 18, 20, 26..30";
    printExpansion(input);

    cout << endl;


    cout << "*******************************" << endl;
    cout << "Problem 4: " << endl;
    cout << "*******************************" << endl;

    string A = "xyz";
    string B = "afdgzyxsldfm";

    if (containsAnagram(A, B)) 
    {
        cout << "True\n";
    } 
    else 
    {
        cout << "False\n";
    }

    cout << endl;

    return 0;
}