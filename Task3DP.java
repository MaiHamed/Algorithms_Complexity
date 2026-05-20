import java.util.Scanner;

/**
 * Task 3 (Alternative) – Tower of Hanoi with 4 Pegs (Dynamic Programming)
 *
 * Computes the MINIMUM NUMBER OF MOVES required using a DP approach.
 * Does NOT print each move – focuses on counting only.
 *
 * Formula:  dp[i] = min over k in [1, i-1] of ( 2*dp[k] + 2^(i-k) - 1 )
 *
 * Time complexity: O(n²)
 */
public class Task3DP {

    public static void main(String[] args) {
        System.out.println("Enter number of discs:");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(hanoi4DP(n));
    }

    static int hanoi4DP(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1; // base case: one disk requires one move

        for (int i = 2; i <= n; i++) {
            dp[i] = Integer.MAX_VALUE; // initialize with a large number

            for (int k = 1; k < i; k++) { // try all possible values of k
                int moves = 2 * dp[k] + (int) Math.pow(2, i - k) - 1;
                dp[i] = Math.min(dp[i], moves); // choose the minimum number of moves
            }
        }

        return dp[n];
    }
}
