class Solution {
public:
    int rob(vector<int>& nums) {
        //动态规划，dp[i]表示到达i位置时的最大收益
        //对第i个房子要么偷，要么不偷，如果偷的话则要求i-1位置上没偷
        //状态转移方程：dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2;i < len;i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        return dp[len-1];
    }
};