# CSE245 – Advanced Algorithms & Complexity  
## Team 19 Project – Ain Shams University

> Faculty of Engineering – Computer and Artificial Intelligence Engineering Department  
> Submitted to: Dr. Gamal Abdel Shafy Ebrahim & Eng. Sally Shaker  
> May 2025

---

## Team Members

| Name | ID | Task |
|---|---|---|
| Mohammed Magdy Taher | 23P0083 | Task 1 |
| Mai Hamed Hussien | 23P0261 | Task 2 |
| Maryam Hamdy Hassan | 23P0260 | Task 3 |
| Mahmoud Hassan Mahmoud | 23P0104 | Task 4 |
| Basmala Hany Mohamed | 23P0008 | Task 5 |
| Omar Wael Galal | 23P0190 | Task 6 |

---

## Repository Structure

```
.
├── task1_tromino_tiling/
│   └── tromino_tiling.cpp          C++ – Divide & Conquer
├── task2_knights_tour/
│   └── KnightsTourGreedy.java      Java – Greedy (Warnsdorff's Rule)
├── task3_tower_of_hanoi/
│   ├── Task3.java                  Java – Divide & Conquer (Frame–Stewart)
│   ├── Task3DP.java                Java – Dynamic Programming (move count)
│   └── Task3Iterative.java         Java – Iterative approximation
├── task4_knight_swap/
│   ├── knight_swap_bfs.cpp         C++ – BFS (optimal, guaranteed)
│   └── knight_swap_iterative.cpp   C++ – Greedy Manhattan heuristic
├── task5_target_shooting/
│   └── target_shooting.cpp         C++ – D&C (fails) + Sweep + Parity
└── task6_lattice_lines/
    └── lattice_lines.cpp           C++ – DP + Divide & Conquer
```

---

## Task Descriptions

### Task 1 – Tromino Tiling  `task1_tromino_tiling/`

**Problem:** Tile a 2ⁿ × 2ⁿ board (with one missing square) using right-trominoes, colouring them with 3 colours so no two adjacent trominoes share a colour.

**Technique:** Divide & Conquer  
**Time Complexity:** O(n²)

**How to compile & run:**
```bash
g++ tromino_tiling.cpp -o tromino
./tromino
```
Edit `n`, `missingRow`, `missingCol` inside `main()` to change the board size and missing-tile position.

---

### Task 2 – Knight's Tour  `task2_knights_tour/`

**Problem:** Find a *closed* Knight's Tour on an n×n chessboard (visit every cell exactly once and return to the start in one legal move).

**Technique:** Greedy (Warnsdorff's Rule) – tries every (startX, startY) × first-move combination.  
**Time Complexity:** O(n²)

**How to compile & run:**
```bash
javac KnightsTourGreedy.java
java KnightsTourGreedy
```
Enter the board size when prompted (e.g., `6` for a 6×6 board).

**Board size results:**

| n | Open Tour | Closed Tour |
|---|---|---|
| 1–4 | ❌ | ❌ |
| 5 | ✅ | ❌ |
| 6 | ✅ | ✅ |
| 7 | ✅ | ❌ |
| 8+ | ✅ | ✅ (even n only) |

---

### Task 3 – Tower of Hanoi (4 Pegs)  `task3_tower_of_hanoi/`

**Problem:** Move 8 disks from peg 1 to peg 3 using 4 pegs in the minimum number of moves.

Three implementations are provided:

| File | Approach | Complexity | Moves for n=8 |
|---|---|---|---|
| `Task3.java` | D&C Frame–Stewart | O(2^√n) | 33 (optimal) |
| `Task3DP.java` | Dynamic Programming | O(n²) | 33 (optimal) |
| `Task3Iterative.java` | Mathematical formula | O(1) | 45 (approximate) |

**How to compile & run (D&C version):**
```bash
javac Task3.java
java Task3
# Enter: 8 1 3   (8 disks, start peg 1, end peg 3)
```

---

### Task 4 – Knight Swap Puzzle  `task4_knight_swap/`

**Problem:** On a 4×3 board, swap 3 black knights (top row) with 3 white knights (bottom row) using valid knight moves in the minimum number of steps.

Two implementations:

| File | Approach | Complexity | Optimal? |
|---|---|---|---|
| `knight_swap_bfs.cpp` | BFS | O(|S|) where S = state space | ✅ Yes |
| `knight_swap_iterative.cpp` | Greedy Manhattan distance | O(T·N·M) | ❌ Not guaranteed |

**How to compile & run (BFS):**
```bash
g++ knight_swap_bfs.cpp -o knight_bfs
./knight_bfs
```

**How to compile & run (Iterative):**
```bash
g++ knight_swap_iterative.cpp -o knight_iter
./knight_iter
```

---

### Task 5 – Target Shooting  `task5_target_shooting/`

**Problem:** n hiding spots in a line. A target moves one step each turn. Design an algorithm guaranteed to hit it.

**Three strategies in one file:**

| Strategy | Guaranteed? | Complexity | Notes |
|---|---|---|---|
| Divide & Conquer | ❌ No | O(n log n) | Target escapes dynamically |
| Sweeping | ✅ Yes | O(n) | Left-to-right + right-to-left sweep |
| Parity-Based | ✅ Yes | O(n) | Odd positions first, then even |

**How to compile & run:**
```bash
g++ target_shooting.cpp -o shooting
./shooting
# Enter n > 1
```

---

### Task 6 – Lattice Line Coverage  `task6_lattice_lines/`

**Problem:** Cross out all n×n lattice points using exactly 2n−2 straight connected lines without retracing.

Two approaches in one file:

| Approach | Complexity |
|---|---|
| Dynamic Programming | O(n³) |
| Divide & Conquer | O(n²) |

Both produce the same result. A shared serpentine path visualizer is included.

**How to compile & run:**
```bash
g++ lattice_lines.cpp -o lattice
./lattice
# Enter n between 3 and 10
```

---

## Build Requirements

| Language | Requirement |
|---|---|
| C++ | `g++` with C++11 or later (`-std=c++11`) |
| Java | JDK 8 or later |

Quick compile-all script (Linux/macOS):
```bash
# C++ tasks
g++ -std=c++11 task1_tromino_tiling/tromino_tiling.cpp       -o task1
g++ -std=c++11 task4_knight_swap/knight_swap_bfs.cpp          -o task4_bfs
g++ -std=c++11 task4_knight_swap/knight_swap_iterative.cpp    -o task4_iter
g++ -std=c++11 task5_target_shooting/target_shooting.cpp      -o task5
g++ -std=c++11 task6_lattice_lines/lattice_lines.cpp          -o task6

# Java tasks
javac task2_knights_tour/KnightsTourGreedy.java
javac task3_tower_of_hanoi/Task3.java
javac task3_tower_of_hanoi/Task3DP.java
javac task3_tower_of_hanoi/Task3Iterative.java
```

---

## Algorithm Summary

| Task | Problem | Primary Technique | Complexity |
|---|---|---|---|
| 1 | Tromino Tiling | Divide & Conquer | O(n²) |
| 2 | Knight's Tour | Greedy (Warnsdorff) | O(n²) |
| 3 | Tower of Hanoi (4 pegs) | Divide & Conquer | O(2^√n) |
| 4 | Knight Swap | BFS | O(\|S\|) |
| 5 | Target Shooting | Sweeping / Parity | O(n) |
| 6 | Lattice Coverage | Dynamic Programming | O(n³) |