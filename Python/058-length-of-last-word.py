class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        #因为是求最后一个单词，我们应该从后向前遍历
        slen = len(s)
        if slen == 0:
            return 0
        lastlen = 0 #最后一个单词的长度
        flag = False #是不是最后一个单词的标志
        for i in range(slen-1, -1, -1):
            #过滤最后一个单词右边的空格
            if s[i] == ' ' and flag == False:
                continue
            #只有遇到空格才标志最后一个单词结束
            elif s[i] != ' ':
                lastlen += 1
                flag = True
            else:
                break
        return lastlen