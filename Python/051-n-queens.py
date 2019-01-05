class Solution:
    def check(self, cur, k):
        """
        cur存放每行中皇后的位置
        检查前k行是不是合法
        """
        for i in range(k):
            if cur[i] == cur[k] or (k-i) == abs(cur[i]-cur[k]):
                return False
        return True
    def dfs(self, n, k, cur, res):
        if k >= n:
            solve = []
            for row in cur:
                s = '.'*row + 'Q' + '.'*(n-1-row)
                solve.append(s)
            res.append(solve)
            return
        else:
            for i in range(n):
                cur[k] = i
                if self.check(cur, k):
                    self.dfs(n, k+1, cur, res)
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        cur = [-1]*n
        res = []
        self.dfs(n, 0, cur, res)
        return res