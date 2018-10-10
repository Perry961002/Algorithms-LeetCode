/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    //算法导论上题目的改变，求出最大的不重叠区间的长度即可
    static bool cmp(Interval &a, Interval &b)
    {
        return a.end < b.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len == 0 || len == 1)
            return 0;
        //按结束时间的升序排列
        sort(intervals.begin(), intervals.end(),cmp);
        int num = 1;//最长不重叠区间的长度
        int start= 0;
        for(int i=1;i<len;i++)
        {
            if(intervals[i].start < intervals[start].end)
                continue;
            else
            {
                start = i;
                num ++;
            }
        }
        return len - num;
    }
};