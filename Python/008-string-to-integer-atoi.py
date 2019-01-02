class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if str == "":
            return 0
        lens = len(str)
        result = 0
        flag = 1
        i = 0
        while  i < lens and str[i] == " ":
            i += 1
        if i < lens and str[i] == "-":
            flag = -1
            i += 1
        elif i < lens and str[i] == "+":
            i += 1
        while i < lens:
            if str[i] >= "0" and str[i] <= "9":
                result = result * 10 + (int)(str[i])
                if result > 2 ** 31 - 1:
                    if flag == 1:
                        return 2 ** 31 - 1
                    else:
                        return - (2 ** 31)
                i += 1
            else:
                break
        return result * flag