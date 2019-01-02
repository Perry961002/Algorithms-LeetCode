class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        position = 1
        while x // (10 * position):
            position *= 10
        while x:
            if x // position != x % 10:
                return False
            else:
                x = x % position // 10
                position //= 100
        return True