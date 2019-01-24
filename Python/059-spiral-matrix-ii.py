class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n == 0:
            return []
        result = [[0 for x in range(n)] for y in range(n)]
        square = n * n
        num = 1
        x, y = 0, 0
        while num <= square:
            #从左到右
            while y < n and result[x][y] == 0:
                result[x][y] = num
                y += 1
                num += 1
            y -= 1
            x += 1
            #从上到下
            while x < n and result[x][y] == 0:
                result[x][y] = num
                x += 1
                num += 1
            x -= 1
            y -= 1
            #从右到左
            while y >= 0 and result[x][y] == 0:
                result[x][y] = num
                y -= 1
                num += 1
            y += 1
            x -= 1
            #从下到上
            while x >= 0 and result[x][y] == 0:
                result[x][y] = num
                x -= 1
                num += 1
            x += 1
            y += 1
        return result