#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;

const int ROWS = 4;  // 4 rows
const int COLS = 3;  // 3 columns

// Knight movement directions
const int dr[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
const int dc[8] = { 1,  2,  2,  1, -1, -2, -2, -1};

// Check if position is inside the board
bool isValid(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

// Convert index to (row, col)
void indexToCoord(int idx, int& r, int& c) {
    r = idx / COLS;
    c = idx % COLS;
}

// Convert (row, col) to index
int coordToIndex(int r, int c) {
    return r * COLS + c;
}

// Print board in 4×3 grid format
void printBoard(const string& board) {
    for (int i = 0; i < ROWS * COLS; ++i) {
        cout << board[i] << ' ';
        if ((i + 1) % COLS == 0)
            cout << endl;
    }
    cout << "--------------" << endl;
}

// Reconstruct and print the path from start to goal
void showPath(unordered_map<string, string>& parent,
              const string& goal, const string& start) {
    stack<string> path;
    string current = goal;
    while (current != start) {
        path.push(current);
        current = parent[current];
    }
    path.push(start);

    int step = 0;
    while (!path.empty()) {
        cout << "Step " << step++ << ":\n";
        printBoard(path.top());
        path.pop();
    }
}

// BFS to find the shortest path
int bfs(const string& start, const string& goal) {
    unordered_set<string> visited;
    unordered_map<string, string> parent;
    queue<pair<string, int>> q;

    visited.insert(start);
    q.push({start, 0});

    while (!q.empty()) {
        string current = q.front().first;
        int steps       = q.front().second;
        q.pop();

        if (current == goal) {
            cout << "\nSolution found in " << steps << " moves.\n\n";
            showPath(parent, goal, start);
            return steps;
        }

        // Explore all knight positions
        for (int i = 0; i < ROWS * COLS; ++i) {
            if (current[i] == '.') continue; // skip empty spaces

            int r, c;
            indexToCoord(i, r, c);

            // Try all 8 possible knight moves
            for (int d = 0; d < 8; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (!isValid(nr, nc)) continue;

                int ni = coordToIndex(nr, nc);
                if (current[ni] != '.') continue; // can only swap with empty space

                string next = current;
                swap(next[i], next[ni]); // swap knight with empty cell

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    parent[next] = current;
                    q.push({next, steps + 1});
                }
            }
        }
    }

    cout << "No solution found." << endl;
    return -1;
}

int main() {
    // Start: B's on top row, W's on bottom row
    string start = "BBB......WWW";
    // Goal:  swap positions
    string goal  = "WWW......BBB";

    if (start.size() != ROWS * COLS || goal.size() != ROWS * COLS) {
        cout << "Error: Start or Goal configuration has invalid size!" << endl;
        return -1;
    }

    bfs(start, goal);

    return 0;
}
