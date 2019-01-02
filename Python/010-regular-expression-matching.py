class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        '''
        首先判断p是否为空，为空的话返回s是否为空
        p多于两个字符并且第二个字符为*,因为*前面可以有0个字符，递归可为0的情况，即去掉p的前两个字符
        或者s不为空，并且p和s的第一个字符相同，去掉p的前一个字符递归
        p的第二个字符不是*，则比较p和s的第一个字符，并且递归
        '''
        #两个都空，才是true
        if p == "":
            return s == ""
        if len(p) > 1 and p[1] == "*":
            #分别尝试匹配0个或1个字符
            return self.isMatch(s, p[2:]) or (s != "" and (s[0] == p[0] or p[0] == ".") and self.isMatch(s[1:], p))
        else:
            return (s != "" and ((s[0] == p[0] or p[0] == ".") and self.isMatch(s[1:], p[1:])))