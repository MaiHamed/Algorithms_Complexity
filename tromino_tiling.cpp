#include <iostream>
using namespace std;

const int MAX = 128; // Maximum board size (must be a power of 2, up to 128x128)
int board[MAX][MAX];
int currentTile = 1;

// Function to tile the board using divide and conquer
void tileBoard(int topRow, int leftCol, int missingRow, int missingCol, int size) {
    // Base case: fill the 2x2 board
    if (size == 2) {
        for (int i = 0; i < 2; i++) {        // for rows
            for (int j = 0; j < 2; j++) {     // for cols
                int r = topRow + i;
                int c = leftCol + j;
                if (r != missingRow || c != missingCol) {
                    board[r][c] = currentTile;
                }
            }
        }
        currentTile++;
        return;
    }

    int half = size / 2;
    int centerRow = topRow + half;
    int centerCol = leftCol + half;
    int quad = 0;

    if (missingRow < centerRow && missingCol < centerCol)        // top-left
        quad = 0;
    else if (missingRow < centerRow && missingCol >= centerCol)  // top-right
        quad = 1;
    else if (missingRow >= centerRow && missingCol < centerCol)  // bottom-left
        quad = 2;
    else                                                          // bottom-right
        quad = 3;

    // Place center tromino
    if (quad != 0) board[centerRow - 1][centerCol - 1] = currentTile;
    if (quad != 1) board[centerRow - 1][centerCol]     = currentTile;
    if (quad != 2) board[centerRow][centerCol - 1]     = currentTile;
    if (quad != 3) board[centerRow][centerCol]         = currentTile;

    currentTile++;

    // Recurse on 4 quadrants
    if (quad == 0)
        tileBoard(topRow, leftCol, missingRow, missingCol, half);
    else
        tileBoard(topRow, leftCol, centerRow - 1, centerCol - 1, half);

    if (quad == 1)
        tileBoard(topRow, centerCol, missingRow, missingCol, half);
    else
        tileBoard(topRow, centerCol, centerRow - 1, centerCol, half);

    if (quad == 2)
        tileBoard(centerRow, leftCol, missingRow, missingCol, half);
    else
        tileBoard(centerRow, leftCol, centerRow, centerCol - 1, half);

    if (quad == 3)
        tileBoard(centerRow, centerCol, missingRow, missingCol, half);
    else
        tileBoard(centerRow, centerCol, centerRow, centerCol, half);
}

// Function to print the board
void printBoard(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;           // Size of board (must be power of 2)
    int missingRow = 1;  // Missing tile row
    int missingCol = 2;  // Missing tile column

    // Initialize the board
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = 0;

    // Mark the missing square
    board[missingRow][missingCol] = -1;

    // Start tiling
    tileBoard(0, 0, missingRow, missingCol, n);

    // Print the board
    printBoard(n);

    return 0;
}
