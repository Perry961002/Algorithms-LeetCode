/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.empty())  //边界情况
        {
            result.push_back(newInterval);
            return result;
        }
        int i = 0;
        while(i < intervals.size())
        {
            if(newInterval.end < intervals[i].start)  //新区间在当前区间的左边，将新区间和所剩的区间全部放入解中
            {
                result.push_back(newInterval);
                while(i < intervals.size())
                    result.push_back(intervals[i++]);
                return result;
            }
            else if(newInterval.start > intervals[i].end)  //当前区间在新区间的左边，将当前区间放入解
                result.push_back(intervals[i]);
            else
            {
                //有重叠的情况，将两个区间融合
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            i++;
        }
        result.push_back(newInterval);  //当与最后一个区间有重叠时，最后要把新区间加入
        return result;
    }
};