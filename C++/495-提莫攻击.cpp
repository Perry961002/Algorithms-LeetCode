class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int len = timeSeries.size() , time = duration;   //初始化
        for(int i=1;i<len;i++)
        {
            int interval = timeSeries[i] - timeSeries[i-1];
            time += interval < duration? interval:duration;   //时间间隔是否大于duration
        }
        return time;
    }
};