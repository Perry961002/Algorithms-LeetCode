class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        res = ""
        first = strs[0]
        for i in range(len(first)):
            for j in range(len(strs)):
                if len(strs[j]) <= i or strs[0][i] != strs[j][i]:
                    return res
            res += strs[0][i]
        return res
                    