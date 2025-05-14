// assignment_10_complete.cpp

#include <bitset>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

/*
    Design a number (ID) generator system that generates numbers between 0-99999999 (8-digits). The system should support two functions:
        a. int getNumber();
        b. boolean requestNumber ();
    The getNumber() function should find a number that is not assigned, mark it as assigned, and return it. 

    The requestNumber() function checks the number to see if it is assigned or not. If assigned, it returns false; otherwise, it is marked as assigned and returns true.
*/ 

const int MAX_IDS = 100000000; // 0 to 99999999
bitset<MAX_IDS> assigned;
int nextFree = 0;

// Finds the next unassigned number, marks it, and returns it.
int getNumber() 
{
    while (nextFree < MAX_IDS) 
    {
        if (!assigned[nextFree]) 
        {
            assigned[nextFree] = true;
            return nextFree++;  // post-increment: use value then increment
        }
        ++nextFree; // pre-increment: increment before using value
    }
    throw runtime_error("No available IDs left.");
}


// Attempts to assign a specific number. Returns true if successful.
bool requestNumber(int number) 
{
    // check if requested number is in range
    if (number < 0 || number >= MAX_IDS)
        throw invalid_argument("Number out of range.");

    // if the value at index number is already assigned, return
    if (assigned[number])
        return false;

    assigned[number] = true;

    if (number == nextFree) 
    {
        while (nextFree < MAX_IDS && assigned[nextFree]) 
        {
            ++nextFree;
        }
    }

    return true;
}

/*
    In a given large string, find the most occurring words in the string. What is the time complexity of the above solution? 

    Hint:
    Create a hash table which will keep track of word, frequency>. Iterate through the string and keep track of word frequency by inserting it into the hash table. When we have a new word, we will insert it into the hash table with frequency 1. We will increase the frequency of all repetitions of the word. We can keep track of the most occurring words. Whenever we increase the frequency, we can see if this is the most occurring word or not. Time complexity is O(n), where n is the number of words in the string, and space complexity is O(m), where m is the unique word in the string.
    
    USE the string: string text = "this is a sample text with some sample words and some repeated words words words"
*/

void mostFreqWords(const string& text) 
{
    unordered_map<string, int> freq;
    istringstream stream(text);
    string word;
    int maxFreq = 0;

    // Count frequency of each word
    while (stream >> word) 
    {
        ++freq[word];
        if (freq[word] > maxFreq) 
        {
            maxFreq = freq[word];
        }
    }

    // Collect all words with max frequency
    vector<string> mostFrequentWords;
    for (const auto& pair : freq) 
    {
        if (pair.second == maxFreq)
        {
            mostFrequentWords.push_back(pair.first);
        }
    }

    cout << "Most frequent word(s):" << endl;
    for (const auto& w : mostFrequentWords) 
    {
        cout << "  " << w << " (Frequency: " << maxFreq << ")" << endl;
    }
}


int main() 
{
    cout << endl;
    cout << "****************************" << endl;
    cout << " Problem 1: ID generator" << endl;
    cout << "****************************" << endl;
    // these call get number to get the first two available id's
    int id1 = getNumber();  // sets [0] to 1
    int id2 = getNumber();  // sets [1] to 1
    cout << "Assigned IDs: " << id1 << ", " << id2 << endl;
    // Can I have id 11?
    if (requestNumber(11)) 
    {
        cout << "ID 11 assigned successfully.\n";
    }
    // Can I have id 1? No, requestNumber() returns false
    if (!requestNumber(1)) 
    {
        cout << "ID 1 is already assigned.\n";
    }


    cout << endl;
    cout << "****************************" << endl;
    cout << " Problem 2a: word frequency" << endl;
    cout << "****************************" << endl;
    string text = "this is a sample text with some sample words and some repeated words words words";

    mostFreqWords(text);


    cout << endl;
    cout << "*************************************" << endl;
    cout << " Problem 2b: Complexity of Problem 1" << endl;
    cout << "*************************************" << endl;

    string answer1 = "From the the assigned reading: "; 

    string answer2 = " But what if there was a magic function that could tell us the exact index of the value in constant time, O(1)? This is essentially how a hash function works, making hash tables incredibly efficient for data retrieval. ";
    
    string answer3 = "Thus, the complexity of the solution to the problem above Problem 2 is: O(1). ";

    cout << answer1 << endl;
    cout << endl;
    cout << answer2 << endl;
    cout << endl;
    cout << answer3 << endl;
    cout << endl;

    return 0;
}