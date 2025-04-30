// monks_and_demons.cpp

// There are three monks and three demons on one side of a river. We want to move all of them to the other side using a small boat. The boat can carry only two persons at a time. If on any shore, the number of demons is more than the number of monks, then the demons will eat the monks. How can we move all these people to the other side of the river safely? Provide the bounding function, initial state, and final state for this problem. Hint: In this problem, the bounding function ensures that all the monks are safe. The initial state has all the monks and demons on one side. The final state has all the monks and demons on the other side of the river.

// Breadth First Search over define state-space
// valid states: M_left, D_left, BoatPos, M_right, D_right
// transitions are legal boat moves
// bounding function keeps monks safe


#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <tuple>
using namespace std;

// State: M_left, D_left, Boat(0=left,1=right), M_right, D_right
struct State {
    int M_left, D_left, boat, M_right, D_right;

    // the : is the "member initializer list"
    State(int ml, int dl, int b, int mr, int dr)
        : M_left(ml), D_left(dl), boat(b), M_right(mr), D_right(dr) {}

    bool isGoal() const {
        return M_left == 0 && D_left == 0 && M_right == 3 && D_right == 3 && boat == 1;
    }

    bool isValid() const {
        if (M_left < 0 || D_left < 0 || M_right < 0 || D_right < 0) return false;
        if (M_left > 0 && M_left < D_left) return false;
        if (M_right > 0 && M_right < D_right) return false;
        return true;
    }

    bool operator<(const State& other) const {
        return tie(M_left, D_left, boat, M_right, D_right) <
               tie(other.M_left, other.D_left, other.boat, other.M_right, other.D_right);
    }
};

// Possible boat moves (monks, demons)
const vector<pair<int, int>> moves = {
    {2, 0}, {0, 2}, {1, 1}, {1, 0}, {0, 1}
};


void printState(const State& s) {
    cout << "(ML=" << s.M_left << ", DL=" << s.D_left
         << ", Boat=" << (s.boat == 0 ? "L" : "R")
         << ", MR=" << s.M_right << ", DR=" << s.D_right << ")\n";
}


void bfs() {
    queue<vector<State>> q;  // Each path is a vector of states
    set<State> visited;

    State initial(3, 3, 0, 0, 0);
    q.push({initial});
    visited.insert(initial);

    while (!q.empty()) {
        vector<State> path = q.front();
        q.pop();

        State current = path.back();

        if (current.isGoal()) {
            cout << "Solution found:\n";
            for (const State& s : path) {
                printState(s);
            }
            return;
        }

        // Try all moves
        for (auto [monks, demons] : moves) {
            State next = current;

            if (current.boat == 0) {
                // Move from left to right
                next.M_left -= monks;
                next.D_left -= demons;
                next.M_right += monks;
                next.D_right += demons;
                next.boat = 1;
            } else {
                // Move from right to left
                next.M_left += monks;
                next.D_left += demons;
                next.M_right -= monks;
                next.D_right -= demons;
                next.boat = 0;
            }

            if (next.isValid() && visited.count(next) == 0) {
                visited.insert(next);
                vector<State> new_path = path;
                new_path.push_back(next);
                q.push(new_path);
            }
        }
    }

    cout << "No solution found.\n";
}


void printBoundingFunction() {
    cout << "Bounding Function:\n";
    cout << "A state (ML, DL, B, MR, DR) is valid if:\n";
    cout << "- 0 <= ML, DL, MR, DR <= 3\n";
    cout << "- (ML == 0 or ML >= DL) and (MR == 0 or MR >= DR)\n\n";
}

void printInitialState() {
    cout << "Initial State:\n";
    cout << "(ML = 3, DL = 3, B = 0, MR = 0, DR = 0)\n\n";
}

void printFinalState() {
    cout << "Final State:\n";
    cout << "(ML = 0, DL = 0, B = 1, MR = 3, DR = 3)\n\n";
}




int main() {
	printBoundingFunction();
    printInitialState();
    printFinalState();
    bfs();
    return 0;
}
