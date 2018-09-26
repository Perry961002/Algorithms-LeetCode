class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        //按second的升序排列,如果相等的话按first的升序排列
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() < 2)
            return points.size();
        //排序
        sort(points.begin(), points.end(), cmp);
        //重叠区间的最左端点
        int minSecond = points[0].second;
        int count = 1;
        for(int i=1;i<points.size();i++){
            //无重叠
            if(points[i].first > minSecond){
                count ++;
                minSecond = points[i].second;
            }
            else{
                minSecond = min(minSecond, points[i].second);
            }
        }
        return count;
    }
};