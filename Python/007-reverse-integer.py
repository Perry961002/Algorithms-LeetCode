class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1
        if x < 0:
            x = -x
            flag = -1
        result = 0
        while x:
            result = result * 10 + x % 10
            #出现溢出
            if result >= 2 ** 31 - 1:
                return 0
            x //= 10
        return result * flag