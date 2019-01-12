class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res=[]
        m = len(matrix)
        if m == 0:
            return res
        else:
            n = len(matrix[0])
            if n == 0:
                return res
        count  =(m+1) // 2
        k = 0
        su = m*n
        cc = 0
        while k < count and cc < su:
            for i in range(k,n-k):
                res.append(matrix[k][i])
                cc += 1
            for i in range(k+1,m-1-k):
                res.append(matrix[i][n-1-k])
                cc += 1
            if k != m-1-k:
                for i in range(k,n-k):
                    res.append(matrix[m-1-k][n-1-i])
                    cc += 1
            if k != n-1-k:
                for i in range(k+1,m-1-k):
                    res.append(matrix[m-1-i][k])
                    cc += 1
            k += 1
        return res