// ============================================================
// Task 6 – n×n Lattice Point Coverage with (2n−2) Lines
//
// Two approaches:
//   1. can_cover_lattice_dp   – Dynamic Programming  O(n³)
//   2. can_cover_lattice_dc   – Divide and Conquer   O(n²)
//
// Both determine whether it is possible to cross out all n×n
// lattice points using exactly 2n−2 straight connected lines.
// A shared visualize_path function shows the serpentine path.
// ============================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_N = 10;

// ----------------------------------------------------------
// Approach 1: Dynamic Programming
// dp[i][j][k] = true  iff point (i,j) can be reached from
// (0,0) using exactly k line segments.
// Time  complexity: O(n³)
// Space complexity: O(n³)
// ----------------------------------------------------------
bool can_cover_lattice_dp(int n) {
    bool dp[MAX_N][MAX_N][2 * MAX_N - 1] = { false };
    dp[0][0][0] = true; // base case

    for (int k = 1; k < 2 * n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool from_horizontal = false;
                bool from_vertical   = false;

                if (i > 0)
                    from_horizontal = dp[i - 1][j][k - 1];
                else if (i == 0 && k == 1)
                    from_horizontal = true;

                if (j > 0)
                    from_vertical = dp[i][j - 1][k - 1];
                else if (j == 0 && k == 1)
                    from_vertical = true;

                dp[i][j][k] = from_horizontal || from_vertical;
            }
        }
    }
    return dp[n - 1][n - 1][2 * n - 2];
}

// ----------------------------------------------------------
// Approach 2: Divide and Conquer
// Recursively checks whether every 1×1 sub-lattice can be
// covered (trivially true as a base case).
// Time  complexity: O(n²)
// ----------------------------------------------------------
bool can_cover_lattice_dc(int n, int startX, int startY,
                                  int endX,   int endY) {
    // Base case: 1×1 sub-lattice can always be covered
    if (endX - startX <= 1 && endY - startY <= 1)
        return true;

    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;

    bool topLeft     = can_cover_lattice_dc(n, startX, startY, midX,  midY);
    bool topRight    = can_cover_lattice_dc(n, startX, midY,   midX,  endY);
    bool bottomLeft  = can_cover_lattice_dc(n, midX,   startY, endX,  midY);
    bool bottomRight = can_cover_lattice_dc(n, midX,   midY,   endX,  endY);

    return topLeft && topRight && bottomLeft && bottomRight;
}

// ----------------------------------------------------------
// Shared visualization: serpentine (boustrophedon) path
// ----------------------------------------------------------
void visualize_path(int n) {
    cout << "\n Visualization:\n\n";

    // Allocate grid
    char** grid = new char*[n];
    for (int i = 0; i < n; i++) {
        grid[i] = new char[n];
        for (int j = 0; j < n; j++)
            grid[i][j] = '.';
    }

    grid[0][0] = '*';
    int x = 0, y = 0;
    bool going_right = true;

    for (int i = 0; i < n; i++) {
        if (going_right) {
            for (int j = 1; j < n; j++) { grid[i][j] = '>'; y = j; }
        } else {
            for (int j = n - 2; j >= 0; j--) { grid[i][j] = '<'; y = j; }
        }
        if (i < n - 1) { x = i + 1; grid[x][y] = 'v'; }
        going_right = !going_right;
    }

    // Print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if      (grid[i][j] == '*') cout << "*";
            else if (grid[i][j] == '>') cout << ">";
            else if (grid[i][j] == '<') cout << "<";
            else if (grid[i][j] == 'v') cout << "v";
            else                         cout << ".";
            cout << "   ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) delete[] grid[i];
    delete[] grid;
}

// ----------------------------------------------------------
int main() {
    int n;
    cout << "Enter the lattice size n (3 <= n <= 10): ";
    cin >> n;

    if (n < 3 || n > MAX_N) {
        cout << "Invalid input. n must be between 3 and " << MAX_N << "." << endl;
        return 0;
    }

    // --- DP approach ---
    bool result_dp = can_cover_lattice_dp(n);
    if (result_dp) {
        cout << "\n[DP] It is possible to cross out all points in a "
             << n << "x" << n << " lattice using "
             << 2 * n - 2 << " lines." << endl;
        visualize_path(n);
    } else {
        cout << "\n[DP] It is NOT possible to cross out all points using "
             << 2 * n - 2 << " lines." << endl;
    }

    // --- D&C approach ---
    bool result_dc = can_cover_lattice_dc(n, 0, 0, n, n);
    if (result_dc) {
        cout << "[D&C] It is possible to cross out all points in a "
             << n << "x" << n << " lattice using "
             << 2 * n - 2 << " lines." << endl;
    } else {
        cout << "[D&C] It is NOT possible to cross out all points using "
             << 2 * n - 2 << " lines." << endl;
    }

    return 0;
}
