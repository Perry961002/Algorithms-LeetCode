class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # s,p的下标
        indexs = 0
        indexp = 0
        startp = -1 # p中*出现的位置
        starts = -1 # s中记录被*匹配的位置的开始位置
        while indexs < len(s):
            # s和p的字符正好匹配
            if indexp < len(p) and (s[indexs] == p[indexp] or p[indexp] == '?'):
                indexs += 1
                indexp += 1
            elif indexp < len(p) and p[indexp] == '*':
                startp = indexp #记录这个位置
                starts = indexs
                indexp += 1 # 尝试让*匹配0个字符
            elif startp != -1:
                # 让*匹配更多的字符
                indexp = startp + 1
                starts += 1
                indexs = starts
            else:
                return False
        # s已经匹配完，处理p剩下字符中的*
        while indexp < len(p) and p[indexp] == '*':
            indexp += 1
        return indexp == len(p)