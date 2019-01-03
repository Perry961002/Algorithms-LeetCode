class Solution:
    def create(self, left, right, str_par, result):
        """
        left: 左括号剩余个数
        right: 右括号剩余括号
        str_par: 一个有效的括号串
        result: 结果
        """
        if left > right:
            return
        if left == 0 and right == 0:
            result.append(str_par)
        else:
            #分别放左、右括号并递归
            if left > 0:
                self.create(left-1, right, str_par + '(', result)
            if right > 0:
                self.create(left, right-1, str_par + ')', result)
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        str_par = ""
        self.create(n, n, str_par, res)
        return res