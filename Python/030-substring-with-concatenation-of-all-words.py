class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if s == '' or words == []:
            return []
        res = []
        #单词长度
        wordlen = len(words[0])
        #单词个数
        wordcount = len(words)
        #需要匹配的总长度
        strlen = wordlen * wordcount
        #转换为字典
        book = {}
        for w in words:
            if w in book:
                book[w] += 1
            else:
                book[w] = 1
        i = 0
        while i <= len(s) - strlen:
            substr = s[i: i + strlen]
            #匹配到的单词
            subbook = {}
            j = 0
            while j <= strlen - wordlen:
                sub = substr[j: j + wordlen]
                #是字典里的单词
                if sub in book:
                    #统计次数
                    if sub in subbook:
                        subbook[sub] += 1
                    else:
                        subbook[sub] = 1
                    #后移一个单词长度
                    j += wordlen
                else:
                    break
            #在这一轮中book中的单词都被恰好用完
            if subbook == book:
                res.append(i)
            i += 1
        return res