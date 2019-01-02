class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        transform = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            #拆成单个字符，组成list
            return list(transform[digits])
        res = []
        #对digits第二个字符开始的部分递归生成解集
        rests = self.letterCombinations(digits[1:])
        #对rest中每个字符串，在前面接上digits[0]可对应的字符
        for first in transform[digits[0]]:
            for rest in rests:
                res.append(first + rest)
        return res