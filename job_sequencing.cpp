// job_sequencing.cpp

// Given a set of jobs each with an ID, deadline, and profit, determine the maximum profit that can be earned by scheduling the jobs in such a way that the maximum number of jobs are completed within their respective deadlines.

// EACH JOB IS ASSUMED TO TAKE 1 UNIT OF DURATION
// deadlines are expressed in units of duration:
// a job with deadline 4 can be completed in time slot 1, 2, 3, or 4. A deadline two job can only be complete in time slot 1 or 2. 

// this is a greedy algorithm


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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


int main() {
    // Sample jobs: id, deadline, profit
    vector<Job> jobs = {
        {'1', 4, 20},
        {'2', 1, 10},
        {'3', 1, 40},
        {'4', 1, 30},
    
    };

    int maxProfit = scheduleJobs(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
