class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());//先排序，如果j<i,nums[i] % nums[j]==0,那么nums[j]的因子也是nums[i]的因子
        int len = nums.size();//数组的长度
        vector<int> dp(len, 0);//dp[i]表示以nums[i]为最大数的最大整除子集的长度
        vector<int> last(len, 0);//last[i]表示nums[i]的最大因子的下标
        int maxlen = 0;//最大整除子集的长度
        int idx;
        for(int i=0;i<len;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if((nums[i] % nums[j]) == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }
            }
            if(dp[i] > maxlen)
            {
                maxlen = dp[i];
                idx = i;
            }
        }
        vector<int> result;
        for(int i=0;i<maxlen;i++)
        {
            result.push_back(nums[idx]);
            idx = last[idx];
        }
        return result;
    }
};