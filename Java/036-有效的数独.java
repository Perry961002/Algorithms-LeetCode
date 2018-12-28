import java.util.*;

class Solution {
    public char[][] board;

    boolean isValidBlock(int x, int y) {
        List<Integer> test = new ArrayList<>();
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (board[i][j] <= '9' && board[i][j] >= '1') {
                    if (test.indexOf(board[i][j] - '0') == -1) // 判断是否存在
                    {
                        test.add(board[i][j] - '0');
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    boolean isValidRow(int row) {
        List<Integer> test = new ArrayList<>();
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '.') {
                continue;
            }
            if (test.indexOf(board[row][i] - '0') == -1) {
                test.add(board[row][i] - '0');
            } else {
                return false;
            }
        }

        return true;
    }

    boolean isValidColum(int colum) {
        List<Integer> test = new ArrayList<>();
        for (int i = 0; i < 9; ++i) {
            if (board[i][colum] == '.') {
                continue;
            }
            if (test.indexOf(board[i][colum] - '0') == -1) {
                test.add(board[i][colum] - '0');
            } else {
                return false;
            }
        }

        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        /* check row & colum */
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            if (!isValidRow(i) || !isValidColum(i)) {
                System.out.println(i);
                return false;
            }
        }

        /* check block */
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidBlock(i, j)) {
                    System.out.println("" + i + j);
                    return false;
                }
            }
        }

        return true;
    }
}