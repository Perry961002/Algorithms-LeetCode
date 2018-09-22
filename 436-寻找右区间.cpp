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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        if(intervals.size() == 1)
            return {-1};
        map<int, int> hash;//以<区间左端点, 下标>建hash表
        vector<int> result;
        //插入元素,按起始点的升序排列
        for(int i=0;i<intervals.size();i++)
            hash[intervals[i].start] = i;
        for(auto it : intervals)
        {
            auto index = hash.lower_bound(it.end);//查找有序区间中第一个大于或等于某给定值的元素的位置
            if(index == hash.end())//不存在it的右区间
                result.push_back(-1);
            else
                result.push_back(index->second);//找到最小右区间的下标
        }
        return result;
    }
};