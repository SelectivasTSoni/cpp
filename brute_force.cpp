// brute_force.cpp

// Write a brute force algorithm to generate all permutations of a given string. For example, given the input ABC, the algorithm should generate ABC, ACB, BAC, BCA, CAB, and CBA

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// generate("ABC", 0, 2)
// │
// ├─ swap(0,0) → "ABC"
// │  └─ generate("ABC", 1, 2)
// │     ├─ swap(1,1) → "ABC"
// │     │  └─ generate("ABC", 2, 2) → [ABC]
// │     └─ swap(1,2) → "ACB"
// │        └─ generate("ACB", 2, 2) → [ACB]
// │     ↳ backtrack → "ABC"
// │
// ├─ swap(0,1) → "BAC"
// │  └─ generate("BAC", 1, 2)
// │     ├─ swap(1,1) → "BAC"
// │     │  └─ generate("BAC", 2, 2) → [BAC]
// │     └─ swap(1,2) → "BCA"
// │        └─ generate("BCA", 2, 2) → [BCA]
// │     ↳ backtrack → "BAC"
// │
// └─ swap(0,2) → "CBA"
//    └─ generate("CBA", 1, 2)
//       ├─ swap(1,1) → "CBA"
//       │  └─ generate("CBA", 2, 2) → [CBA]
//       └─ swap(1,2) → "CAB"
//          └─ generate("CAB", 2, 2) → [CAB]
//       ↳ backtrack → "CBA"


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// "left" is starting index of the current subproblem and 
// "right" is the boundary condiction for recurussion: the ending index of the str, (str.size()-1) . 
//It only controls the for-loop.
void generatePermutations(string& str, int left, const int right, vector<string>& results, size_t& counter) {
    if (left == right) {
        results.push_back(str);
        ++counter;

        // Optional: live feedback every million permutations
        if (counter % 1000000 == 0) {
            cout << counter << " permutations generated...\n";
        }
        return;
    }

    for (int i = left; i <= right; ++i) {
        swap(str[left], str[i]);
        generatePermutations(str, left + 1, right, results, counter);
        swap(str[left], str[i]);  // backtrack
    }
}


int main() {
    string input;
    cout << "Enter a string (keep it short!): ";
    getline(cin, input);

    vector<string> permutations;
    size_t counter = 0;

    generatePermutations(input, 0, input.size() - 1, permutations, counter);

    cout << "\nTotal permutations: " << counter << endl;

    // Optional: print first few results only
    cout << "First 10 permutations:\n";
    for (size_t i = 0; i < min(permutations.size(), size_t(10)); ++i) {
        cout << permutations[i] << endl;
    }

    return 0;
}

