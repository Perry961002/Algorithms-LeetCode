class Solution {
    public int check(char[][] board, int x, int y, char num) {
        int i, j;
        for (i = 0; i < 9; i++) {
            if (board[x][i] == num)
                return 0; // 检查同一行
            if (board[i][y] == num)
                return 0; // 检查同一列
        }
        int m = (x / 3) * 3;
        int n = (y / 3) * 3; // 确定所在九宫格
        for (i = m; i < m + 3; i++)
            for (j = n; j < n + 3; j++)
                if (board[i][j] == num)
                    return 0;
        return 1;
    }

    public boolean dfs(char[][] board, int x, int y) {
        if (x >= 9)
            return true;
        if (board[x][y] == '.') {
            int i;
            for (i = 1; i <= 9; i++) {
                char num = (char) (i + '0');
                if (this.check(board, x, y, num) != 0) {
                    board[x][y] = num;
                    if (dfs(board, x + (y + 1) / 9, (y + 1) % 9))
                        return true;
                }
            }
            board[x][y] = '.'; // 回溯
        } else
            return dfs(board, x + ((y + 1) / 9), (y + 1) % 9);
        return false;
    }

    public void solveSudoku(char[][] board) {
        this.dfs(board, 0, 0);
    }
}