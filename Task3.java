import java.util.Scanner;

/**
 * Task 3 – Tower of Hanoi with 4 Pegs (Frame–Stewart Algorithm)
 *
 * Solves the 8-disk, 4-peg Tower of Hanoi in the optimal 33 moves
 * using a divide-and-conquer strategy.
 *
 * Time complexity: O(2^(√n))
 */
public class Task3 {

    static int moveCount = 0;

    public static void main(String[] args) {
        System.out.println("Enter n, start, end:");
        Scanner scanner = new Scanner(System.in);
        int n     = scanner.nextInt();   // number of disks  (e.g. 8)
        int start = scanner.nextInt();   // starting peg     (1-4)
        int end   = scanner.nextInt();   // destination peg  (1-4)

        // Find the two auxiliary pegs (out of 1,2,3,4) that are NOT start or end
        int aux1 = 0, aux2 = 0;
        int count = 0;
        for (int i = 1; i <= 4; i++) {
            if (i != start && i != end) {
                if (count == 0) aux1 = i;
                else            aux2 = i;
                count++;
            }
        }

        hanoi4(n, start, end, aux1, aux2);
        System.out.println("Total moves: " + moveCount);
    }

    /** Classic 3-peg Tower of Hanoi */
    static void hanoi(int n, int start, int end, int aux) {
        if (n == 0) return;
        hanoi(n - 1, start, aux, end);
        printmove(start, end);
        hanoi(n - 1, aux, end, start);
    }

    /** 4-peg Tower of Hanoi using Frame–Stewart split (k = n/2) */
    static void hanoi4(int n, int start, int end, int aux1, int aux2) {
        if (n == 0) return;
        if (n == 1) { printmove(start, end); return; }

        int k = n / 2;  // k = n/2 is most efficient (found by trial and error)

        hanoi4(k,     start, aux1, aux2, end);   // Step 1: move top k disks to aux1
        hanoi (n - k, start, end,  aux2);          // Step 2: move remaining disks to end (3-peg)
        hanoi4(k,     aux1,  end,  aux2, start);  // Step 3: move k disks from aux1 to end
    }

    /** Prints a move and increments the counter */
    static void printmove(int start, int end) {
        System.out.println(start + " => " + end);
        moveCount++;
    }
}
