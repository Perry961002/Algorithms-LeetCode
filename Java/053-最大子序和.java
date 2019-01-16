class Solution {
    public int maxSubArray(int[] nums) {
        //动态规划算法
        //dp[i]表示以nums[i]结尾的最大和的连续子数组的和
        int[] dp = new int[nums.length];
        int maxsub = dp[0] = nums[0];
        for(int i = 1;i < nums.length;i++)
        {
            dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
            maxsub = Math.max(dp[i], maxsub);
        }
        return maxsub;
    }
}
