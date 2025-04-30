// design_complete.cpp

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <tuple>
using namespace std;


//////////////////////////////////

// "left" is starting index of the current subproblem and 
// "right" is the boundary condiction for recurussion: the ending index of the str, index: str.size() - 1.  
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

//////////////////////////////////

// Structure to represent a job
struct Job {
    char id;       // Job ID (e.g., A, B, C)
    int deadline;  // Deadline (in time slots)
    int profit;    // Profit for completing before or at deadline
};

// Sort jobs in decreasing order of profit
bool compareProfit(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to schedule jobs and return maximum profit
int scheduleJobs(vector<Job>& jobs) {
    // Step 1: Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compareProfit);

    // Step 2: Find the maximum deadline to determine time slot range
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 3: Create a time slot array (1-based index)
    vector<bool> slot(maxDeadline + 1, false); // slot[0] is unused
    int totalProfit = 0;

    cout << "Scheduled jobs: ";

    for (const Job& job : jobs) {
        // Try to schedule the job at the latest possible time slot ≤ its deadline
        for (int t = job.deadline; t > 0; --t) {
            if (!slot[t]) {
                slot[t] = true;           // Mark slot as used
                totalProfit += job.profit;
                cout << job.id << " ";    // Track which jobs are scheduled
                break;
            }
        }
    }

    cout << "\n";
    return totalProfit;
}


//////////////////////////////////


// binary search for first/last occurrence of target
int binarySearch(const vector<int>& arr, int target, bool searchFirst) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            if (searchFirst)
                high = mid - 1; // search left
            else
                low = mid + 1;  // search right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}


//////////////////////////////////


// Helper function, memo passed as reference
int fibTopDownHelper(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibTopDownHelper(n - 1, memo) + fibTopDownHelper(n - 2, memo);
    return memo[n];
}

// Public interface: self-contained version
void fibTopDown2(int n) {
    if (n == 0) return;

    vector<int> memo(n, -1);
    cout << "Top-Down Fibonacci:\n";
    for (int i = 0; i < n; ++i) {
        cout << fibTopDownHelper(i, memo) << " ";
    }
    cout << endl;
}


void fibBottomUp(int n) {
    if (n == 0) 
    	return;
    vector<int> dp(n);
    dp[0] = 0;
    if (n > 1) 
    	dp[1] = 1;

    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Bottom-Up Fibonacci:\n";
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
}


//////////////////////////////////


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
    queue<vector<State>> q;
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


//////////////////////////////////


int main() {
	cout << endl;
	cout << "===============================" << endl;
    cout << "          Look Alive!          " << endl;
    cout << "       User input required     " << endl;
    cout << "===============================" << endl;


	cout << endl;
	cout << "*******************************" << endl;
    cout << "Problem 1: Brute Force " << endl;
    cout << "*******************************" << endl;
    string input;
    cout << "Enter a string (keep it short!): ";
    getline(cin, input);
    vector<string> permutations;
    size_t counter = 0;
    generatePermutations(input, 0, input.size() - 1, permutations, counter);
    cout << "\nTotal permutations: " << counter << endl;
    // Print first few results only
    cout << "First 10 permutations:\n";
    for (size_t i = 0; i < min(permutations.size(), size_t(10)); ++i) {
        cout << permutations[i] << endl;
    }


    cout << "*******************************" << endl;
    cout << "Problem 2: Job Sequencing " << endl;
    cout << "*******************************" << endl;
    vector<Job> jobs = {
        {'1', 4, 20},
        {'2', 1, 10},
        {'3', 1, 40},
        {'4', 1, 30}
    };
    int maxProfit = scheduleJobs(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;


    cout << endl;
    cout << "*******************************" << endl;
    cout << "Problem 3: First, Last Index" << endl;
    cout << "*******************************" << endl;
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int first = binarySearch(arr, target, true);
    int last  = binarySearch(arr, target, false);
    cout << "First occurrence of " << target << " at index: " << first << endl;
    cout << "Last occurrence of " << target << " at index: " << last << endl;

    
    cout << endl;
    cout << "*******************************" << endl;
    cout << "Problem 4: N Fibonacci" << endl;
    cout << "*******************************" << endl;
    int n;
    cout << "Enter number of Fibonacci elements: " << endl;
    cout << "Integer overflow occurs for n > 46 " << endl;
    cin >> n;
    fibTopDown2(n);
	fibBottomUp(n);

	
	cout << endl;
    cout << "*******************************" << endl;
    cout << "Problem 5: Monks and Demons" << endl;
    cout << "*******************************" << endl;
    printBoundingFunction();
    printInitialState();
    printFinalState();
    bfs();

    cout << endl;
    cout << "END." << endl;
    cout << endl;


    return 0;
}