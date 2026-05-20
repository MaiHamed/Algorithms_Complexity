import java.util.Scanner;

/**
 * Task 2 – Knight's Tour (Greedy / Warnsdorff's Rule)
 *
 * Finds a CLOSED Knight's Tour on an n×n chessboard using a greedy algorithm
 * that tries every (startX, startY) × first-move combination.
 *
 * Time complexity: O(n²)
 */
public class KnightsTourGreedy {

    // Direction arrays for the 8 possible moves of a knight
    private static int[] knightMovesX = {-2, -1, 1, 2,  2,  1, -1, -2};
    private static int[] knightMovesY = { 1,  2, 2, 1, -1, -2, -2, -1};

    private static int[][] chessboard;
    private static int boardSize;

    // Check if the given position (x, y) is valid (inside the board and unvisited)
    private static boolean isValidMove(int x, int y) {
        return x >= 0 && y >= 0 && x < boardSize && y < boardSize && chessboard[x][y] == -1;
    }

    // Get the number of valid moves from a given position (x, y) – Warnsdorff's rule
    private static int getMoveDegree(int x, int y) {
        int validMoves = 0;
        for (int i = 0; i < 8; i++) {
            int newX = x + knightMovesX[i];
            int newY = y + knightMovesY[i];
            if (isValidMove(newX, newY)) {
                validMoves++;
            }
        }
        return validMoves;
    }

    /**
     * Perform a greedy knight's tour starting from (startX, startY),
     * with (firstMoveX, firstMoveY) as the first move.
     */
    private static boolean performGreedyTour(int startX, int startY,
                                             int firstMoveX, int firstMoveY) {
        int currentX = firstMoveX;
        int currentY = firstMoveY;

        // Mark the starting position and the first move on the board
        chessboard[startX][startY] = 0;
        chessboard[currentX][currentY] = 1;

        int moveCount = boardSize * boardSize - 1;

        for (int move = 2; move <= moveCount; move++) {
            int bestX = -1, bestY = -1;
            int minDegree = Integer.MAX_VALUE;

            for (int i = 0; i < 8; i++) {
                int newX = currentX + knightMovesX[i];
                int newY = currentY + knightMovesY[i];
                if (isValidMove(newX, newY)) {
                    int degree = getMoveDegree(newX, newY);
                    if (degree < minDegree) {
                        minDegree = degree;
                        bestX = newX;
                        bestY = newY;
                    }
                }
            }

            if (bestX == -1) return false; // stuck

            chessboard[bestX][bestY] = move;
            currentX = bestX;
            currentY = bestY;
        }

        // Check if the final move can return to the starting position (closed tour)
        for (int i = 0; i < 8; i++) {
            if (currentX + knightMovesX[i] == startX &&
                currentY + knightMovesY[i] == startY) {
                System.out.println("Closed Knight's Tour found with " +
                        moveCount + " moves.");
                return true;
            }
        }

        return false; // no closed tour found
    }

    // Print the final chessboard showing the knight's tour path
    private static void printChessboard() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                System.out.print(chessboard[i][j] + "\t");
            }
            System.out.println();
        }
    }

    // Main method to execute the knight's tour
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the chessboard (n x n): ");
        boardSize = scanner.nextInt();

        boolean tourFound = false;

        // Try all starting positions (startX, startY)
        outer:
        for (int startX = 0; startX < boardSize; startX++) {
            for (int startY = 0; startY < boardSize; startY++) {
                // Try all 8 possible directions for the first move
                for (int direction = 0; direction < 8; direction++) {
                    int firstMoveX = startX + knightMovesX[direction];
                    int firstMoveY = startY + knightMovesY[direction];

                    if (firstMoveX >= 0 && firstMoveY >= 0 &&
                        firstMoveX < boardSize && firstMoveY < boardSize) {

                        // Initialize chessboard with -1 (unvisited)
                        chessboard = new int[boardSize][boardSize];
                        for (int i = 0; i < boardSize; i++)
                            for (int j = 0; j < boardSize; j++)
                                chessboard[i][j] = -1;

                        if (performGreedyTour(startX, startY, firstMoveX, firstMoveY)) {
                            System.out.println("Start position: (" + startX + ", " + startY + ")");
                            printChessboard();
                            tourFound = true;
                            break outer;
                        }
                    }
                }
            }
        }

        if (!tourFound) {
            System.out.println("No closed Knight's Tour found using greedy.");
        }
    }
}
