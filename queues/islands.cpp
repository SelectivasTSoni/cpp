// You are given an 8×8 grid (2D array) representing a map where 1 represents land and 0 represents water. An island is defined as a contiguous landmass consisting of at least one fully connected 2×2 block of 1s. That is, a 2×2 subgrid must be entirely filled with 1s to be considered part of an island. Islands may be larger than 2×2 but must include at least one such fully connected block. Your task is to determine the total number of distinct islands in the given 8×8 grid.

// 5 islands

// grid = { 	{1, 1, 0, 0, 0, 1, 1, 0}, 
// 			{1, 1, 0, 0, 0, 1, 1, 0},
// 			{0, 0, 1, 1, 0, 0, 0, 0}, 
// 			{0, 0, 1, 1, 0, 0, 1, 1}, 
// 			{1, 0, 0, 1, 1, 0, 1, 1},
// 			{1, 0, 0, 1, 1, 0, 0, 0}, 
// 			{0, 0, 1, 1, 0, 0, 1, 1}, 
// 			{0, 0, 1, 1, 1, 0, 1, 1}
// 		};

#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<vector<int>> grid(N, vector<int>(N));

// Directions for DFS: left, right, up, down. 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool has2x2Block(int x, int y) {
    // Check if a 2x2 block starting at (x, y) is fully 1s
    return isValid(x + 1, y + 1) &&
           grid[x][y] == 1 && grid[x][y + 1] == 1 &&
           grid[x + 1][y] == 1 && grid[x + 1][y + 1] == 1;
}

void dfs(int x, int y, vector<vector<bool>>& visited) {
    // DFS to visit all connected land cells (1s) starting from (x, y)
    visited[x][y] = true;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny, visited);
        }
    }
}

int countDistinctIslands() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int islandCount = 0;
    
    // Scan through every 2x2 block in the grid
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            // If we find an unvisited 1 and it starts a valid 2x2 block, we start DFS
            if (grid[i][j] == 1 && !visited[i][j] && has2x2Block(i, j)) {
                dfs(i, j, visited);
                ++islandCount;  // Increment island count for every new valid island
            }
        }
    }
    
    return islandCount;
}



int main() {
    
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
    
    return 0;
}