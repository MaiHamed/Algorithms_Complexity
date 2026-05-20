#include <iostream>
#include <utility>
#include <climits>
using namespace std;

#define Row     4
#define Column  3
#define KNIGHTS 3

char board[Row][Column];

pair<int, int> moves[8] = {
    {-2, 1}, {-1, 2}, {2, 1}, {1, 2},
    {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
};

// Goal positions for each colour
pair<int, int> blackGoal[3] = {{0, 0}, {0, 1}, {0, 2}};
pair<int, int> whiteGoal[3] = {{3, 0}, {3, 1}, {3, 2}};

// Total Manhattan distance heuristic
int manhat_Distance() {
    int distance = 0;
    for (int r = 0; r < Row; r++) {
        for (int c = 0; c < Column; c++) {
            if (board[r][c] == 'W') {
                int minimum_dist = INT_MAX;
                for (int i = 0; i < KNIGHTS; i++) {
                    int d = abs(r - whiteGoal[i].first) + abs(c - whiteGoal[i].second);
                    if (d < minimum_dist) minimum_dist = d;
                }
                distance += minimum_dist;
            } else if (board[r][c] == 'B') {
                int minimum_dist = INT_MAX;
                for (int i = 0; i < KNIGHTS; i++) {
                    int d = abs(r - blackGoal[i].first) + abs(c - blackGoal[i].second);
                    if (d < minimum_dist) minimum_dist = d;
                }
                distance += minimum_dist;
            }
        }
    }
    return distance;
}

void printBoard() {
    for (int r = 0; r < Row; r++) {
        for (int c = 0; c < Column; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "--------------\n";
}

// Greedy local search using Manhattan distance
void move_On_Board() {
    int steps = 0;
    while (true) {
        int currentDistance = manhat_Distance();
        cout << "Current distance: " << currentDistance << endl;

        if (currentDistance == 0) {
            cout << "All knights reached their goals!\n";
            break;
        }

        pair<int, int> best_place_from = {-1, -1};
        pair<int, int> best_place_to   = {-1, -1};
        char K = '.';
        int  newManHat = currentDistance;

        for (int r = 0; r < Row; r++) {
            for (int c = 0; c < Column; c++) {
                if (board[r][c] == 'B' || board[r][c] == 'W') {
                    char currentK = board[r][c];
                    for (int move = 0; move < 8; move++) {
                        int row    = r + moves[move].first;
                        int column = c + moves[move].second;

                        if (row >= 0 && row < Row && column >= 0 &&
                            column < Column && board[row][column] == '.') {
                            // Temporarily make the move
                            board[r][c]         = '.';
                            board[row][column]  = currentK;

                            int tempDist = manhat_Distance();

                            // Undo
                            board[row][column] = '.';
                            board[r][c]        = currentK;

                            if (tempDist < newManHat) {
                                newManHat        = tempDist;
                                best_place_from  = {r, c};
                                best_place_to    = {row, column};
                                K                = currentK;
                            }
                        }
                    }
                }
            }
        }

        if (best_place_from.first == -1) {
            cout << "No improving move found!\n";
            break;
        }

        // Execute the best move
        board[best_place_from.first][best_place_from.second] = '.';
        board[best_place_to.first][best_place_to.second]     = K;

        steps++;
        cout << "Step " << steps << ":\n";
        cout << "Moving " << K << " from ("
             << best_place_from.first << "," << best_place_from.second
             << ") to ("
             << best_place_to.first  << "," << best_place_to.second << ")\n";
        printBoard();
    }
    cout << "Total steps: " << steps << endl;
}

int main() {
    // Initial setup – some knights not in goal positions
    char temp[Row][Column] = {
        {'W', 'W', 'W'},
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'B', 'B', 'B'}
    };

    for (int i = 0; i < Row; ++i)
        for (int j = 0; j < Column; ++j)
            board[i][j] = temp[i][j];

    cout << "Initial board:\n";
    printBoard();
    cout << "Initial distance: " << manhat_Distance() << endl;

    move_On_Board();

    cout << "Final board:\n";
    printBoard();

    return 0;
}
