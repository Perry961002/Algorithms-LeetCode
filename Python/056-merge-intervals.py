# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        interlen = len(intervals)
        if interlen < 2:
            return intervals
        res = []
        #按start升序排序
        intervals.sort(key = lambda x : x.start)
        #合并的新区间的左右端点
        left, right = intervals[0].start, intervals[0].end
        for i in range(1, interlen):
            #/当前区间的左端点在前一个的右端点之后,产生了区间分段
            if intervals[i].start > right:
                res.append([left, right])
                #更新为新的区间
                left = intervals[i].start
                right = intervals[i].end
            else:
                #合并两个区间
                right = max(right, intervals[i].end)
        res.append([left, right])
        return res