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
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        cur = [-1] * n
        self.res = 0
        def dfs(k, cur):
            if k >= n:
                self.res += 1
                return
            else:
                for i in range(n):
                    cur[k] = i
                    if self.check(cur, k):
                        dfs(k+1, cur)
        dfs(0, cur)
        return self.res