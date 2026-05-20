# README - Algorithms Project Documentation

## Project Overview

This repository contains implementations and analysis of six algorithmic tasks using divide-and-conquer, greedy algorithms, dynamic programming, and BFS techniques. The project explores classical computational problems including tromino tiling, knight's tours, Tower of Hanoi, and lattice covering.

## Table of Contents
- [Task 1: Tromino Tiling with Color Constraints](#task-1-tromino-tiling-with-color-constraints)
- [Task 2: Knight's Tour Problem](#task-2-knights-tour-problem)
- [Task 3: Tower of Hanoi with 4 Pegs](#task-3-tower-of-hanoi-with-4-pegs)
- [Task 4: Knight Swap Puzzle](#task-4-knight-swap-puzzle)
- [Task 5: Dynamic Target Shooting](#task-5-dynamic-target-shooting)
- [Task 6: Lattice Point Covering](#task-6-lattice-point-covering)
- [Research Contributions](#research-contributions)
- [Compilation and Usage](#compilation-and-usage)

---

## Task 1: Tromino Tiling with Color Constraints

**Problem:** Tile a $2^n \times 2^n$ board with one missing square using L-shaped trominoes of three colors such that adjacent trominoes share no edge.

**Algorithm:** Divide and Conquer
- Base case: 2×2 board with one missing square
- Recursively divide into four quadrants
- Place a central tromino covering three quadrants
- Recurse on each quadrant with appropriate color offsets

**Complexity:** O(n²) where n is board size (supports up to 128×128)

**Key Features:**
- Unique tile numbering incrementally
- Missing square marked as -1
- Guarantees no adjacent trominoes share colors

---

## Task 2: Knight's Tour Problem

**Problem:** Determine if a knight can visit every cell on an n×n chessboard exactly once and return to start (closed tour). Find minimum moves.

**Algorithm:** Warnsdorff's Rule (Greedy) + Backtracking alternative

**Key Findings:**
| Board Size | Open Tour | Closed Tour |
|------------|-----------|-------------|
| 1-4 | ❌ | ❌ |
| 5 | ✅ | ❌ |
| 6 | ✅ | ✅ |
| 7 | ✅ | ❌ |
| 8+ | ✅ | ✅ (even n) |

**Complexity:** O(n²) for greedy approach

---

## Task 3: Tower of Hanoi with 4 Pegs

**Problem:** Move 8 disks of different sizes from one peg to another using 4 pegs, never placing larger disks on smaller ones.

**Algorithm:** Frame-Stewart (Divide and Conquer)

**Strategy:**
1. Move k disks to auxiliary peg using 4 pegs
2. Move n-k disks to target peg using 3 pegs
3. Move k disks from auxiliary to target using 4 pegs

**Optimal k for 8 disks:** k = 4 → **33 moves** (vs 255 moves with 3 pegs)

**Complexity:** O(2^(√n))

**Alternative Approaches:** Dynamic Programming (O(n²)), Iterative approximation

---

## Task 4: Knight Swap Puzzle

**Problem:** Swap positions of 3 black knights and 3 white knights on a 4×3 board using only valid knight moves.

**Algorithm:** Breadth-First Search (BFS) - Optimal solution

**Board Representation:**
- 4 rows × 3 columns
- 'B' = Black knight, 'W' = White knight, '.' = Empty

**Complexity:** O(N) where N = number of states visited

**Alternative:** Greedy Manhattan distance heuristic (incomplete)

---

## Task 5: Dynamic Target Shooting

**Problem:** A target moves to an adjacent hiding spot after each shot. Design an algorithm that guarantees hitting the target.

**Why Divide and Conquer Fails:** Target's movement makes static space division ineffective; shooter always lags behind.

**Working Solution - Sweeping Strategy:**
- Move from position 1 → n (left to right)
- Then from n-1 → 2 (right to left)
- Repeat until target is hit

**Complexity:** O(n)

**Alternative - Parity Strategy:** Shoot odd positions at odd times, even positions at even times.

---

## Task 6: Lattice Point Covering

**Problem:** Cover all points of an n×n lattice using exactly 2n-2 connected straight lines without retracing.

**Algorithm:** Dynamic Programming

**DP State:** dp[i][j][k] = whether point (i,j) can be reached from origin using exactly k segments

**Complexity:** O(n³)

**Visualization:** ASCII grid with arrows (>, <, v) showing path

**Alternative:** Divide and Conquer (O(n²))

---

## Research Contributions

### 1. Partition Problem
Comprehensive analysis of 10 algorithms including:
- Brute-Force (O(2ⁿ))
- Dynamic Programming (O(n·sum))
- Greedy Algorithm (O(n log n))
- Karmarkar-Karp Heuristic
- Complete Karmarkar-Karp (CKK)
- Improved Limited Discrepancy Search (ILDS)
- BFS and Multi-Way Partitioning
- Quantum approaches and Bin Packing reduction

### 2. Hamiltonian Circuit Problem
Implementation of two algorithms:
- **Backtracking:** O(N!) time, O(N) space
- **Held-Karp (DP with Bitmasking):** O(N²·2^N) time, O(N·2^N) space

### 3. Bin-Packing Problem
Analysis of 10 algorithms including:
- Greedy (First-Fit, Best-Fit, Worst-Fit)
- Advanced heuristics (FFD, BFD, Next-Fit)
- Approximation (Multi-Fit, Harmonic)
- Exact (Branch and Bound, Dynamic Programming)

---

## Compilation and Usage

### Requirements
- C++11 or higher compiler
- Standard library only

### Compilation
```bash
g++ -std=c++11 task1.cpp -o task1
g++ -std=c++11 task2.cpp -o task2
# ... similarly for other tasks
```

### Running Examples
```bash
# Task 1 - Tromino Tiling (4x4 board, missing at position 1,2)
./task1

# Task 2 - Knight's Tour (6x6 board)
./task2

# Task 3 - Tower of Hanoi (8 disks, 4 pegs)
./task3

# Task 4 - Knight Swap Puzzle
./task4

# Task 5 - Target Shooting (n=5)
./task5

# Task 6 - Lattice Covering (n=4)
./task6
```

---

## File Structure
```
├── task1_tromino_tiling.cpp
├── task2_knights_tour.cpp
├── task3_hanoi_4pegs.cpp
├── task4_knight_swap.cpp
├── task5_target_shooting.cpp
├── task6_lattice_covering.cpp
├── research/
│   ├── partition_problem.cpp
│   ├── hamiltonian_circuit.cpp
│   └── bin_packing.cpp
└── README.md
```

---

## Complexity Summary Table

| Task | Algorithm | Time Complexity | Space Complexity |
|------|-----------|-----------------|------------------|
| 1 | Divide & Conquer | O(n²) | O(n²) |
| 2 | Warnsdorff's Rule | O(n²) | O(n²) |
| 3 | Frame-Stewart | O(2^√n) | O(n) |
| 4 | BFS | O(N) | O(N) |
| 5 | Sweeping | O(n) | O(n) |
| 6 | Dynamic Programming | O(n³) | O(n³) |

---

## Authors

- **Mohammed Magdy Taher** - Partition Problem
- **Basmala Hany Mohamed** - Hamiltonian Circuit
- **Mahmoud Hassan Mahmoud** - Hamiltonian Circuit
- **Omar Wael Galal** - Bin-Packing Problem
- **Mai Hamed Hussien** - Bin-Packing Problem
- **Maryam Hamdy Hassan** - Bin-Packing Problem

---

## References

- Introduction to Algorithms (CLRS), 3rd Edition
- GeeksforGeeks - Tromino Tiling, Knight's Tour, Tower of Hanoi
- Warnsdorff's Rule for Knight's Tour
- Frame-Stewart Algorithm for Multi-Peg Tower of Hanoi