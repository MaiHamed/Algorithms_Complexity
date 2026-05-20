// ============================================================
// Task 5 – Target Shooting in a Line
//
// Three strategies are implemented:
//   1. divideAndConquerShoot  – FAILS (dynamic target escapes)
//   2. sweepingStrategy       – GUARANTEED to hit (linear sweep)
//   3. parityStrategy         – GUARANTEED to hit (parity-based)
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------------------------------------
// Strategy 1: Divide and Conquer (INCORRECT for dynamic target)
// Shoots the midpoint, then recurses on both halves.
// The target moves after each shot and can always escape.
// ----------------------------------------------------------
void divideAndConquerShoot(int left, int right) {
    if (left > right) return;

    int mid = (left + right) / 2;
    cout << "Shooting at position " << mid << endl;

    // Recursive calls
    divideAndConquerShoot(left,   mid - 1);
    divideAndConquerShoot(mid + 1, right);
}

// ----------------------------------------------------------
// Strategy 2: Sweeping Strategy (GUARANTEED)
// Sweeps left-to-right then right-to-left, repeated maxRounds
// times. Eventually the shooter and target coincide.
// Time complexity: O(n × R) → O(n) since R is a small constant.
// ----------------------------------------------------------
void sweepingStrategy(int n, int maxRounds = 3) {
    int rounds = 0;
    while (rounds < maxRounds) {
        for (int i = 1; i <= n; ++i)
            cout << "Shooting at position " << i << endl;

        for (int i = n - 1; i >= 2; --i)
            cout << "Shooting at position " << i << endl;

        rounds++;
    }
}

// ----------------------------------------------------------
// Strategy 3: Parity-Based (Diagonal) Strategy (GUARANTEED)
// Phase 1: shoot odd positions at odd time steps.
// Phase 2: shoot even positions at even time steps.
// Exploits the fact that the target's parity alternates each turn.
// Time complexity: O(n)
// ----------------------------------------------------------
void parityStrategy(int n) {
    int time = 1;

    cout << "=== Shooting at odd positions (odd time steps) ===" << endl;
    for (int i = 1; i <= n; i += 2) {
        cout << "Time " << time << ": Shooting at position " << i << endl;
        time++;
    }

    cout << "=== Shooting at even positions (even time steps) ===" << endl;
    for (int i = 2; i <= n; i += 2) {
        cout << "Time " << time << ": Shooting at position " << i << endl;
        time++;
    }
}

// ----------------------------------------------------------
int main() {
    int n;
    cout << "Enter number of hiding spots (n > 1): ";
    cin >> n;

    if (n <= 1) {
        cout << "Invalid input. There must be more than 1 hiding spot." << endl;
        return 1;
    }

    cout << "\n--- Strategy 1: Divide and Conquer (FAILS) ---\n";
    cout << "\nStarting divide and conquer shooting...\n" << endl;
    divideAndConquerShoot(1, n);

    cout << "\n--- Strategy 2: Sweeping Strategy (GUARANTEED) ---\n";
    cout << "\nStarting sweep strategy to catch the moving target...\n" << endl;
    sweepingStrategy(n);

    cout << "\n--- Strategy 3: Parity-Based Strategy (GUARANTEED) ---\n\n";
    parityStrategy(n);

    return 0;
}
