class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lens = len(s)
        if lens < 2:
            return lens
        dict = {} #字符存放出现的位置
        maxlen = 0 #最长不重复子串的长度
        start = -1 #子串开始的下标
        for i in range(lens):
            #出现重复字符
            if s[i] in dict and dict[s[i]] > start:
                #重置start
                start = dict[s[i]]
            #记录这个字符的位置
            dict[s[i]] = i
            maxlen = max(maxlen, i - start)
        return maxlen