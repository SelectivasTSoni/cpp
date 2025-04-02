// queues_complete.cpp

#include <deque>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>




using namespace std;

//islands
////////////////
const int N = 8;
vector<vector<int>> grid(N, vector<int>(N));

// Directions for DFS: left, right, up, down. 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) 
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool has2x2Block(int x, int y) 
{
    // Check if a 2x2 block starting at (x, y) is fully 1s
    return isValid(x + 1, y + 1) &&
           grid[x][y] == 1 && grid[x][y + 1] == 1 &&
           grid[x + 1][y] == 1 && grid[x + 1][y + 1] == 1;
}

void dfs(int x, int y, vector<vector<bool>>& visited) 
{
    // DFS to visit all connected land cells (1s) starting from (x, y)
    visited[x][y] = true;
    
    for (int i = 0; i < 4; ++i) 
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1)
        {
            dfs(nx, ny, visited);
        }
    }
}

int countDistinctIslands() 
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int islandCount = 0;
    
    // Scan through every 2x2 block in the grid
    for (int i = 0; i < N - 1; ++i) 
    {
        for (int j = 0; j < N - 1; ++j) 
        {
            // If we find an unvisited 1 and it starts a valid 2x2 block, we start DFS
            if (grid[i][j] == 1 && !visited[i][j] && has2x2Block(i, j))
            {
                dfs(i, j, visited);
                ++islandCount;  // Increment island count for every new valid island
            }
        }
    }
    
    return islandCount;
}


// min_of_max
//////////////
int min_of_max_sliding_window(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> max_values;
    
    for (int i = 0; i < nums.size(); ++i) 
    {
        // Remove elements out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        
        // Store max of current window
        if (i >= k - 1)
            max_values.push_back(nums[dq.front()]);
    }
    
    // Find the minimum among the max values of all windows
    int min_of_max = INT_MAX;
    for (int max_val : max_values)
        min_of_max = min(min_of_max, max_val);
    
    return min_of_max;
}

// first_neg
/////////////
vector<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;  // Deque to store indices of potential negative numbers in the window

    for (int i = 0; i < arr.size(); i++) 
    {
        // Remove elements from the front of the deque if they are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) 
        {
            dq.pop_front();
        }

        // If current element is negative, add its index to the deque
        if (arr[i] < 0) 
        {
            dq.push_back(i);
        }

        // Once we've processed the first k elements, start adding the result for the sliding window
        if (i >= k - 1) 
        {
            if (!dq.empty()) 
            {
                result.push_back(arr[dq.front()]); // First negative number in the window
            } 
        }
    }
    return result;
}


// x_to_y
/////////////
int convertXY(int src, int dst) 
{
    std::queue<int> que;
    std::vector<int> arr(100);
    
    int steps = 0;
    int index = 0;
    int value;
    
    que.push(src);
    
    std::cout << "Path: ";
    while (que.size() != 0) 
    {
        value = que.front();
        que.pop();
        arr[index++] = value;
        if (value == dst) 
        {
            std::cout << "\n" << "Steps count: " << steps << std::endl;
            return steps;
        }
        
        steps++;
        if (value < dst)
            que.push(value * 2);
        else
            que.push(value - 1);

        std::cout << que.back() << ' ';
	}
	
	return -1; 
}


int main() {
    
    // islands
    cout << "Islands: " << endl;
    cout << "********************" << endl;
    grid = {{1, 1, 0, 0, 0, 1, 1, 0}, 
			{1, 1, 0, 0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 0, 0, 1, 1}, 
			{1, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 0, 1, 1, 0, 0, 0}, 
			{0, 0, 1, 1, 0, 0, 1, 1}, 
			{0, 0, 1, 1, 1, 0, 1, 1}
		};

    int result = countDistinctIslands();
    cout << "Total distinct islands: " << result << endl;
    cout << endl;


    // x_to_y
    cout << "x_to_y: " << endl;
    cout << "********************" << endl;
    convertXY(5, 27);
    cout << endl;


    // min_of_max
    cout << "min_of_max: " << endl;
    cout << "********************" << endl;
    std::vector<int> nums = {11, 2, 75, 92, 59, 90, 55};
    int k = 3;
    cout << "Minimum of all maximums in sliding windows of length k = " << k << ": " << min_of_max_sliding_window(nums, k) << endl;
     cout << endl;
    
    // first_neg
    cout << "first_neg: " << endl;
    cout << "********************" << endl;
    std::vector<int> arr = {13, -2, -6, 10, -14, 50, 14, 21};
    int l = 3;
    vector<int> first_negs = firstNegativeInWindow(arr, l);
    cout << "First negative numbers in each sliding window of size k = " << k << ": ";
    for (int num : first_negs) 
    {
        cout << num << " ";
    }
    cout << endl;


    

    
    return 0;
}