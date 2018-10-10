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
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    static bool cmp(Interval& I1, Interval& I2)
    {
        return I1.start < I2.start;  //区间左端点的大小关系
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;  //结果集
        if(intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end(), cmp);   //将区间按左端点从小到大排序
        int left = intervals[0].start, right = intervals[0].end;  //记录左、右端点
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start > right)  //当前区间的左端点在前一个的右端点之后
            {
                result.push_back(Interval(left, right));  //把前一个区间放入
                left = intervals[i].start;   //更新左、右端点
                right = intervals[i].end;
            }
            else
            {
                right = max(right, intervals[i].end);   //看区间是包含还是相交关系
            }
        }
        result.push_back(Interval(left, right));   //放最后一个区间
        return result;
    }
};