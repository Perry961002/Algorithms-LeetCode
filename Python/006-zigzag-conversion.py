class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        lens = len(s)
        result = ""
        for i in range(numRows):
            leftstep = 2 * numRows - 2 - 2 * i
            rightstep = 2 * i
            index = i
            while index < lens:
                if leftstep > 0:
                    result += s[index]
                    index += leftstep
                if index < lens and rightstep > 0:
                    result += s[index]
                    index += rightstep
        return result