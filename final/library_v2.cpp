// library_v2.cpp

#include <bitset>
#include <stdexcept>
#include <iostream>
using namespace std;

class LibraryIDSystem {
private:
    static const int MAX_ID = 100;     // IDs range from 1 to 99
    bitset<MAX_ID> assigned;           // Index 1 to 99 track assigned status
    int nextFree = 1;                  // Start checking at ID = 1

public:
    // Assign and return the next available ID (1–99), or throw error if none
    int assignID() {
        if (!checkAvailability()) {
            throw runtime_error("No available IDs left.");
        }

        // First pass: try forward from nextFree
        for (int i = nextFree; i < MAX_ID; ++i) {
            if (!assigned[i]) {
                assigned[i] = true;
                nextFree = i + 1;
                return i;
            }
        }

        // Second pass: wrap around to check from 1 up to nextFree
        for (int i = 1; i < nextFree; ++i) {
            if (!assigned[i]) {
                assigned[i] = true;
                nextFree = i + 1;
                return i;
            }
        }

        // This line should never be reached due to checkAvailability()
        throw runtime_error("No available IDs (unexpected fallback).");
    }

    // Returns true if any IDs are still available
    bool checkAvailability() const {
        return assigned.count() < MAX_ID - 1;  // exclude index 0
    }
};

int main() {
    LibraryIDSystem library;

    try {
        int id = library.assignID();
        cout << "Assigned Book ID: " << id << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
