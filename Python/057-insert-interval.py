# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        """
        以newInterval为对象依次和列表中的区间比较，能合并的就合并
        """
        interlen = len(intervals)
        if interlen == 0:
            return [newInterval]
        res = []
        i = 0
        while i < interlen:
            #新插入的区间在第i个区间的左边
            #那么先放入newInterval，再把intervals[i]及之后的都加入
            if newInterval.end < intervals[i].start:
                res.append(newInterval)
                while i < interlen:
                    res.append(intervals[i])
                    i += 1
                return res
            #intervals[i]在newInterval的左边
            #只放intervals[i]
            elif newInterval.start > intervals[i].end:
                res.append(intervals[i])
            #合并intervals[i]和newInterval作为新的newInterval
            else:
                newInterval.start = min(newInterval.start, intervals[i].start)
                newInterval.end = max(newInterval.end, intervals[i].end)
            i += 1
        res.append(newInterval)
        return res