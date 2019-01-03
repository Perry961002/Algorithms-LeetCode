class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i in range(len(s)):
            if stack != [] and s[i] == ')' and stack[len(stack)-1] == '(':
                stack.pop()
            elif stack != [] and s[i] == ']' and stack[len(stack)-1] == '[':
                stack.pop()
            elif stack != [] and s[i] == '}' and stack[len(stack)-1] == '{':
                stack.pop()
            else:
                stack.append(s[i])
        return stack == []
        