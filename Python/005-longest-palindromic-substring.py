class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        #Manarcher
        len1 = len(s)
        if len1 < 2:
            return s
        s = "#" + "#".join(s) + "#"
        len2 = len(s)
        maxlen = 0
        maxid = 0
        p = [0] * len2
        id = 0
        mx = 0
        for i in range(len2):
            if i < mx:
                p[i] = min(mx-i, p[2*id-i])
            else:
                p[i] = 1
            while i - p[i] >= 0 and i + p[i] < len2 and s[i-p[i]] == s[i+p[i]]:
                p[i] += 1
            if i + p[i] > mx:
                id = i
                mx = i + p[i]
            if maxlen < p[i] - 1:
                maxlen = p[i] - 1
                maxid = i
        return s[maxid-maxlen:maxid+maxlen+1].replace("#","")