/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new ArrayList<>();
        if(intervals.size() == 0)  //边界情况
        {
            result.add(newInterval);
            return result;
        }
        int i = 0;
        while(i < intervals.size())
        {
            if(newInterval.end < intervals.get(i).start)  //新区间在当前区间的左边，将新区间和所剩的区间全部放入解中
            {
                result.add(newInterval);
                while(i < intervals.size())
                    result.add(intervals.get(i++));
                return result;
            }
            else if(newInterval.start > intervals.get(i).end)  //当前区间在新区间的左边，将当前区间放入解
                result.add(intervals.get(i));
            else
            {
                //有重叠的情况，将两个区间融合
                newInterval.start = Math.min(newInterval.start, intervals.get(i).start);
                newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
            }
            i++;
        }
        result.add(newInterval);  //当与最后一个区间有重叠时，最后要把新区间加入
        return result;
    }
}
