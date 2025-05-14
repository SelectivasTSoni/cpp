// path.cpp

// 3) Given an NxN matrix maze of 0s and 1s, where 0s represent blocked cells and 1s represent unblocked cells, find a path from the source (maze[0][0]) to the destination (maze[N-1][N-1]). The rat can move in any direction (left, right, up, and down) and can only move through unblocked cells. Return the shortest path and its length. Maze = { {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}, {1, 1, 1, 1} };

// simliar to assignment_7_queues #1 but not the same
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

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
