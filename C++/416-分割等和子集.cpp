class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //只有1个或0个元素
        if(nums.size() < 2)
            return false;
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2)//不能将数组分成两个部分
            return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int val : nums)
            for(int i=target;i>=val;i--){
                dp[i] = dp[i] || dp[i - val];
            }
        return dp[target];
    }
};