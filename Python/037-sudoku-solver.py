class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def check(board, x, y, num):
            """
            检查board里面的(x, y)位置能不能填num
            """
            for i in range(9):
                if board[x][i] == num:
                    return False
                if board[i][y] == num:
                    return False
            m = (x // 3) * 3
            n = (y // 3) * 3
            for i in range(m, m+3):
                for j in range(n, n+3):
                    if board[i][j] == num:
                        return False
            return True
        def dfs(board, x, y):
            """
            以深度搜索方式从(x, y)开始填充board
            """
            if x >= 9:
                return True
            if board[x][y] == '.':
                for i in range(1, 10):
                    num = str(i)
                    if check(board, x, y, num):
                        board[x][y] = num
                        if dfs(board,x+(y+1)//9,(y+1)%9):
                            return True
                #回溯
                board[x][y] = '.'
            else:
                return dfs(board,x+((y+1)//9),(y+1)%9)
            return False
        dfs(board, 0, 0)
                