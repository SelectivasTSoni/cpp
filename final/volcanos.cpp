// volcanos.cpp

// 1) A volcanologist is analyzing a stream of historical eruption data. Each data point represents the height of a volcanic eruption (in meters) over time. The most recent eruptions come first (i.e., the data stream is in reverse chronological order). Write a C++ program that identifies record-breaking eruptions — that is, eruptions that are taller than all eruptions that occurred before them in real time. Assume the: the input (in reverse chronological order) is: 
//  1100, 1050, 800, 1200, 1500, 1300, 1250, 1400, 1600, 1550, 1500

// Like stock-hike point in stacks assignment_6_stacks #2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find record-breaking eruption heights (from oldest to newest)
vector<int> find_records(const vector<int>& reverseData) {
    vector<int> records;
    
    // Reverse the input to simulate real-time order
    vector<int> data(reverseData.rbegin(), reverseData.rend());

    int maxSoFar = -1;

    for (int height : data) {
        if (height > maxSoFar) {
            records.push_back(height);  // Record-breaking
            maxSoFar = height;          // Update max
        }
    }

    return records;
}


int main() {
    // Most recent eruption first (reverse chronological order)
    vector<int> reverseData = {1100, 1050, 800, 1200, 1500, 1300, 1250, 1400, 1600, 1550, 1500};

    vector<int> records = find_records(reverseData);

    cout << "Record-breaking eruptions (oldest first):\n";
    for (int h : records) {
        cout << h << " ";
    }
    cout << endl;

    return 0;
}
