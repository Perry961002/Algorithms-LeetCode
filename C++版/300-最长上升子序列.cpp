static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        /*
        //动态规划，dp[i]表示以i位置结尾的最长子序列的长度
        vector<int> dp(len,1);
        int maxlen = 0;
        for(int i = 1;i < len;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j])   //说明nums[i]加入j位置之前的数字序列依然是递增的
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            maxlen = max(maxlen,dp[i]);  //更新maxlen
        }
        return maxlen;
        */
        vector<int> dp;
        for(int i = 0;i < len;i++)
        {
            //对于每一个nums[i]二分搜索dp找第一个不小于他的数，如果找到则把dp里的这个数更新，如果没有则把遍历的数加入dp
            int left = 0, right = dp.size();
            int mid = 0;
            while(left < right)
            {
                mid = (left + right) / 2;
                if(dp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            //因为dp是递增的，所以不存在>=nums[i]的话，right == dp.size()
            if(right == dp.size())
                dp.push_back(nums[i]);
            else
                dp[right] = nums[i];
        }
        return dp.size();
    }
};