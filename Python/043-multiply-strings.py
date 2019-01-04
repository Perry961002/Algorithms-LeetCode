class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        len1 = len(num1)
        len2 = len(num2)
        len_res = len1 + len2
        carry = 0
        res = ''
        arr = [0 for i in range(len_res)]
        for i in range(len1):
            for j in range(len2):
                arr[len_res - 2 - i -j] += (int)(num1[i]) * (int)(num2[j])
        for i in range(len_res):
            arr[i] += carry
            carry = arr[i] // 10
            arr[i] %= 10
        i = len_res - 1
        while i >= 0 and arr[i] == 0:
            i -= 1
        if i < 0:
            return '0'
        while i >= 0:
            res += str(arr[i])
            i -= 1
        return res