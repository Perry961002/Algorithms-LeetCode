class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = []
        strmap = {}
        for s in strs:
            tmpstr = s[:]
            tmpstr = (str)(sorted(tmpstr))
            if tmpstr in strmap:
                strmap[tmpstr].append(s[:])
            else:
                strmap[tmpstr] = [s]
        for s in strmap.values():
            res.append(s)
        return res