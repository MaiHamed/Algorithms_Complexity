/**
 * Task 3 (Iterative Approximation) – Tower of Hanoi with 4 Pegs
 *
 * Uses a non-recursive mathematical formula to ESTIMATE the total number
 * of moves. Does NOT produce the actual move sequence.
 * Assumes k = n/2 as the splitting point.
 *
 * Time complexity: O(1)
 *
 * NOTE: This yields a non-optimal approximation (e.g., 45 for 8 disks
 * instead of the optimal 33). It is useful for quick estimation only.
 */
public class Task3Iterative {

    public static void main(String[] args) {
        int n = 8; // number of disks
        int totalMoves = iterativeHanoi4(n);
        System.out.println("Total moves (non-optimal iterative, 4 pegs): " + totalMoves);
    }

    public static int iterativeHanoi4(int n) {
        // Assume k = n/2 for splitting disks (approximated)
        int k = n / 2;

        // Moves to transfer k disks to an auxiliary peg using 4 pegs
        int moves1 = (int) Math.pow(2, k) - 1;

        // Moves to transfer remaining n-k disks using 3 pegs (exact)
        int moves2 = (int) Math.pow(2, n - k) - 1;

        // Move the k disks from auxiliary to destination (again 4 pegs, approx)
        int moves3 = (int) Math.pow(2, k) - 1;

        return moves1 + moves2 + moves3;
    }
}
