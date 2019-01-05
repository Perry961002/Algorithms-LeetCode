class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        动态规划算法
        dp[i]表示以nums[i]结尾的最大和的连续子数组的和
        """
        dp = [nums[0]] * len(nums)
        maxSum = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
            maxSum = max(maxSum, dp[i])
        return maxSum