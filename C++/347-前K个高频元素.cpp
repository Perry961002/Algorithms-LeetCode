static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return nums;
        vector<int> result;
        //以 <数字,次数> 建立hash表
        unordered_map<int,int> numhash;
        for(int num : nums)
            numhash[num] ++;
        //建立优先队列，默认是大根堆，使用堆排序，以 <次数,数字>方式存放
        priority_queue<pair<int, int>> numpq;
        for(auto val : numhash)
        {
            numpq.push(pair<int, int> (val.second, val.first));
            if(numpq.size() > numhash.size() - k)
            {
                //已经出现了前k高的元素
                result.push_back(numpq.top().second);
                numpq.pop();
            }
        }
        return result;
    }
};