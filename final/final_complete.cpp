// // final.cpp

// start: 1200 MST 5/13/2025 End: 1933 MST 5/13/2025

// start:  MST 5/14/2025 End: MST 5/14/2025

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <deque>
#include <optional>
#include <stack>
#include <utility>
using namespace std;


// 1) Given a binary tree, create a new tree that is a mirror image of the original tree. Use the tree: [5, 3, 8, 1, 4, null, 10]
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursively mirror the binary tree
TreeNode* mirror(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* mirrored = new TreeNode(root->val);
    mirrored->left = mirror(root->right);
    mirrored->right = mirror(root->left);
    return mirrored;
}

// Helper: print tree level-order
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    // Track when the last non-null node was seen
    bool hasMoreNodes = true;

    while (!q.empty() && hasMoreNodes) {
        int levelSize = q.size();
        hasMoreNodes = false; // Assume this is the last level

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                cout << cur->val << " ";
                q.push(cur->left);
                q.push(cur->right);

                // If any children are non-null, continue further levels
                if (cur->left || cur->right) {
                    hasMoreNodes = true;
                }
            } else {
                cout << "null ";
                q.push(nullptr); // Maintain structure
                q.push(nullptr);
            }
        }
    }

    cout << endl;
}

// Construct original tree from the given structure
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(10);
    return root;
}

// Print the tree in ASCII-art rotated format
void printAsciiTree(TreeNode* root, int space = 0, int indent = 5) {
	// base case of recursive function, prevents stack overflow
    if (!root) return;

    space += indent;

    // Print right child first (so it appears on top)
    printAsciiTree(root->right, space);

    // Print current node after spacing
    //cout << endl;
    for (int i = indent; i < space; ++i) cout << " ";
    cout << root->val << "\n";

    // Then print left child
    printAsciiTree(root->left, space);
}


//  						3, 9, 5, 4, 8, 1, 5, 2, 7, 6, 
// 2) Given the sequence: 	3, 9, 5, 4, 8, 1, 5, 2, 7, 6, construct a min-heap using the CreateHeap function.
// Heapify down from index i
void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;        // Start with current node
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // Compare with left child
    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    // Compare with right child
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    // If a smaller child was found, swap and recurse
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}


// Create a min-heap from unsorted array
void createMinHeap(vector<int>& heap) {
    int n = heap.size();
    // Start from the last internal node and heapify down
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }
}


// 3) A volcanologist is analyzing a stream of historical eruption data. Each data point represents the height of a volcanic eruption (in meters) over time. The most recent eruptions come first (i.e., the data stream is in reverse chronological order). Write a C++ program that identifies record-breaking eruptions — that is, eruptions that are taller than all eruptions that occurred before them in real time. Assume the: the input (in reverse chronological order) is: 1100, 1050, 800, 1200, 1500, 1300, 1250, 1400, 1600, 1550, 1500
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


// 4) Design a system to track library books where each book is assigned a unique ID number. The system should support two functions: 
//int getBookID(): This function generates and returns the next available unique book ID. The ID numbers should range from 1 to 99 (2-digit). 
// boolean checkAvailability(): This function checks if there are available IDs to assign to new books. It returns true if there are available IDs, and false if all IDs have been used.
class LibraryIDSystem {
private:
    static const int MAX_ID = 100;           // 0 to 99, we'll use 1–99
    bitset<MAX_ID> assigned;                 // bitset to track assigned IDs
    int nextFree = 1;                        // next candidate ID to try

public:
    // Generates and returns the next available unique book ID (1–99)
    int getBookID() {
        for (int i = nextFree; i < MAX_ID; ++i) {
            if (!assigned[i]) {
                assigned[i] = true;
                nextFree = i + 1;
                return i;
            }
        }

        // Try wraparound in case earlier IDs were released (not in this version)
        for (int i = 1; i < nextFree; ++i) {
            if (!assigned[i]) {
                assigned[i] = true;
                nextFree = i + 1;
                return i;
            }
        }

        throw runtime_error("No available IDs left.");
    }

    // Returns true if there are any unassigned IDs left
    bool checkAvailability() const {
        return assigned.count() < MAX_ID - 1; // skip index 0
    }
};


// 5) Given an array of integers, find the minimum of all the maximum values in the sliding windows of length k. Input: [11, 2, 75, 92, 77, 86, 59, 90, 55] and k = 3
int min_of_max_sliding_window(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> max_values;
    
    for (int i = 0; i < nums.size(); ++i) {
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


// 6) Given a binary tree, find the count of full nodes in it. A full node has non-null left and right children. Use the tree: [5, 3, 8, 9, 1, 4, null, 10]

// This is defined above.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// Builds a binary tree from level-order array with std::nullopt for nulls
TreeNode* buildTreeFromArray(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        ++i;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        ++i;
    }

    return root;
}

// Count full (2-child) nodes
int countFullNodes(TreeNode* root) {
    if (!root) return 0;
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->left && node->right) count++;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return count;
}


// 7) In given two strings A and B, find whether any anagram of string A is a substring of string B. For example: If A = ldf and B = afdgzyxksldfmdssdciowheo then the program should return True. If A = ldf, B = then the program should return False.
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


// 8) You need to find the next smaller element for each element in an array. For each element in the array, the next smaller element is the first element to its right that is smaller than the current element. If no such element exists, output -1 for that element. Use the following numbers as input: 4, 8, 5, 12, 1, 2, 25;
vector<int> nextSmallerElements(const vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> s;  // holds indices

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] >= nums[i]) {
            s.pop();  // pop larger or equal elements
        }

        if (!s.empty()) {
            result[i] = nums[s.top()];  // next smaller to the right
        }

        s.push(i);  // push current index
    }

    return result;
}


// 9) Find the Kth largest element in an unsorted array using a max-heap. Hint: Create a max-heap from the input array. Then we call remove() operation K-1 times, and the element at the top of the heap is kth largest. Time complexity O(n.log(n)). Assume k=2 and the array: {3, 2, 1, 5, 7, 6, 4}
int findKthLargest(const vector<int>& nums, int k) {
    // max-heap by default in priority_queue
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    // Remove k-1 elements
    for (int i = 1; i < k; ++i) {
        maxHeap.pop();
    }

    return maxHeap.top(); // k-th largest element
}


// 10) Given an NxN matrix maze of 0s and 1s, where 0s represent blocked cells and 1s represent unblocked cells, find a path from the source (maze[0][0]) to the destination (maze[N-1][N-1]). The rat can move in any direction (left, right, up, and down) and can only move through unblocked cells. Return the shortest path and its length. Maze = { {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}, {1, 1, 1, 1} };
struct Node {
    int x, y;
    vector<pair<int, int>> path;  // stores the path as a list of coordinates
};

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
    int N = maze.size();
    return x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && !visited[x][y];
}

pair<vector<pair<int, int>>, int> findShortestPath(const vector<vector<int>>& maze) {
    int N = maze.size();
    if (maze[0][0] == 0 || maze[N-1][N-1] == 0)
        return {{}, -1};

    queue<Node> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    q.push({0, 0, {{0, 0}}});
    visited[0][0] = true;

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        // Reached the destination
        if (curr.x == N - 1 && curr.y == N - 1)
            return {curr.path, (int)curr.path.size()};

        // Explore all 4 directions
        for (int d = 0; d < 4; ++d) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];

            if (isValid(nx, ny, maze, visited)) {
                visited[nx][ny] = true;
                vector<pair<int, int>> newPath = curr.path;
                newPath.push_back({nx, ny});
                q.push({nx, ny, newPath});
            }
        }
    }

    return {{}, -1}; // No path found
}


void printMaze(const vector<vector<int>>& maze) {
    int N = maze.size();

    cout << "Maze layout" << endl;
    cout << "(upper left is origin [Y=0][X=0], ++y moves down):\n\n";
    
    for (int row = 0; row < N; ++row) {
    	cout << "   ";
        for (int col = 0; col < N; ++col) {
            cout << maze[row][col] << " ";
        }
        cout << endl;
    }

    cout << "\nLegend: 1 = open path, 0 = wall/blocked\n";
    cout << endl;
}



int main() {
	cout << "******************************" << endl;
	cout << "**  Problem 1 *" << endl;
	cout << "******************************" << endl;

    TreeNode* original = buildSampleTree();
    cout << "Original Tree: ";
    printLevelOrder(original);
    cout << "Original Tree ASCII:\n";
    printAsciiTree(original);               // Print ASCII art

    TreeNode* mirrored = mirror(original);
    cout << "Mirrored Tree: ";
    printLevelOrder(mirrored);
    cout << "Mirrored Tree ASCII:\n";
    printAsciiTree(mirrored);               // Print ASCII art

   
    cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 2 *" << endl;
	cout << "******************************" << endl;

	vector<int> heap = {3, 9, 5, 4, 8, 1, 5, 2, 7, 6};
    createMinHeap(heap);
    cout << "Min-heap array: ";
    for (int val : heap) cout << val << " ";
    cout << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 3 *" << endl;
	cout << "******************************" << endl;

	// Most recent eruption first (reverse chronological order)
    vector<int> reverseData = {1100, 1050, 800, 1200, 1500, 1300, 1250, 1400, 1600, 1550, 1500};
    vector<int> records = find_records(reverseData);
    cout << "Record-breaking eruptions (oldest first):\n";
    for (int r : records) {
        cout << r << " ";
    }
    cout << endl;


    cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 4 *" << endl;
	cout << "******************************" << endl;

	// instantiate the system object
	LibraryIDSystem system;

	// while there are ids available print them
    while (system.checkAvailability()) {
        int id = system.getBookID();
        cout << "Assigned book ID: " << id << endl;
    }

    // once all ids are gone, print this
    cout << "All IDs have been assigned.\n";


    cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 5 *" << endl;
	cout << "******************************" << endl;

	std::vector<int> nums = {11, 2, 75, 92, 77, 86, 59, 90, 55};
    int k = 3;
    cout << "Minimum of all maximums in sliding windows of length k = " << k << ": " << min_of_max_sliding_window(nums, k) << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 6 *" << endl;
	cout << "******************************" << endl;

	vector<optional<int>> input = {5, 3, 8, 9, 1, 4, nullopt, 10};
    TreeNode* root = buildTreeFromArray(input);
    cout << "Full node count: " << countFullNodes(root) << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 7 *" << endl;
	cout << "******************************" << endl;
	cout << "***********************************************" << endl;
	cout << "An anagram is any rearrangement of all the letters" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "string A = ldf" << endl;
	cout << "string B = afdgzyxksldfmdssdciowheo" << endl;
	cout <<	"Anagram substring!" << endl;
	cout << "Output should be true." << endl;

	string A = "ldf";
	string B = "afdgzyxksldfmdssdciowheo";
    if (containsAnagram(A, B)) 
    {
        cout << "True\n";
    } 
    else 
    {
        cout << "False\n";
    }

    cout << "However" << endl;
	cout << endl;
	cout << "string A = ldf"<< endl;
	cout << "string B = " << endl;
	cout <<	"No anagram substring!" << endl;
	cout << "Output should be False." << endl;

    string a = "LDF";
    string b = "";
    if (containsAnagram(a, b)) 
    {
        cout << "True\n";
    } 
    else 
    {
        cout << "False\n";
    }


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 8 *" << endl;
	cout << "******************************" << endl;

	vector<int> nums2 = {4, 8, 5, 12, 1, 2, 25};
    vector<int> result = nextSmallerElements(nums2);
    cout << "Next smaller elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 9 *" << endl;
	cout << "******************************" << endl;

	vector<int> nums3 = {3, 2, 1, 5, 7, 6, 4};
    int k2 = 2;
    int kthLargest = findKthLargest(nums3, k2);
    cout << "The " << k2 << "th largest element is: " << kthLargest << endl;


	cout << endl;
	cout << "******************************" << endl;
	cout << "* Problem 10 *" << endl;
	cout << "******************************" << endl;

	vector<vector<int>> maze = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    printMaze(maze);

    auto [path, length] = findShortestPath(maze);

    if (length == -1) {
        cout << "No path found.\n";
    } else {
        cout << "Shortest path length: " << length << endl;
        cout << "Path:\n";
        for (auto [x, y] : path) {
            cout << "(" << x << ", " << y << ") ";
        }
        cout << endl;
    }


    return 0;
}

