static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划算法
        //dp[i]表示以nums[i]结尾的最大和的连续子数组的和
        vector<int> dp(nums.size());
        int maxsub = dp[0] = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxsub = max(dp[i], maxsub);
        }
        return maxsub;
    }
};