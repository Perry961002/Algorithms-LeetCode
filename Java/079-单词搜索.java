class Solution {
    public boolean dfs(char[][] board, String word, int i, int j, int index) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] == '0'
                || board[i][j] != word.charAt(index)) // 不满足则说明符合要求
            return false;
        if (index == word.length() - 1) // 所有单词已经找到
            return true;
        char temp = board[i][j];
        board[i][j] = '0'; // 已经访问的标记
        if (dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1)
                || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j - 1, index + 1)) // 搜索4个方向
            return true;
        board[i][j] = temp; // 找不到的话回溯
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        if (m == 0 || n == 0)
            return false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
}