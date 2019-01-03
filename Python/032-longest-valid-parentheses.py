class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        max = 0
        for i in range(len(s)):
            if stack != [] and s[i] == ')' and s[stack[len(stack)-1]] == '(':
                stack.pop()
                if stack == []:
                    max = i + 1
                elif i - stack[len(stack)-1] > max:
                    max = i - stack[len(stack)-1]
                
            else:
                stack.append(i)
        return max