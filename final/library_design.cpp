// library_design.cpp

#include <bitset>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

// 9) Design a system to track library books where each book is assigned a unique ID number. The system should support two functions: int getBookID(): This function generates and returns the next available unique book ID. The ID numbers should range from 1 to 99 (2-digit). boolean checkAvailability(): This function checks if there are available IDs to assign to new books. It returns true if there are available IDs, and false if all IDs have been used.

// Similar but not exactly like 1 in assignment_10_hash_tble
const int MAX_IDS = 100; // Need 100 bits: index 0 to 99
bitset<MAX_IDS> assigned;  // We will ignore assigned[0]
int nextFree = 1;

// Finds the next unassigned number, marks it, and returns it.
int getBookID() 
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
bool checkAvailability(int number) 
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




int main() 
{
    // cout << endl;
    // cout << "****************************" << endl;
    // cout << " Problem 1: ID generator" << endl;
    // cout << "****************************" << endl;
    // these calls get the first two available id's
    int id1 = getBookID();  // sets [0] to 1
    int id2 = getBookID();  // sets [1] to 1
    cout << "Previously sssigned IDs: " << id1 << ", " << id2 << endl;
    // Can I have id 11?
    if (checkAvailability(11)) 
    {
        cout << "ID 11 assigned successfully.\n";
    }
    // Can I have id 1? No, checkAvailability() returns false
    if (!checkAvailability(1)) 
    {
        cout << "ID 1 is already assigned.\n";
    }

    return 0; 
}