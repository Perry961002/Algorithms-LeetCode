class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        min = 2 ** 31
        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if abs(min - target) > abs(sum - target):
                    min = sum
                #sum偏小，left右移，添加一个更大的nums[left]
                if sum <= target:
                    left += 1
                if sum > target:
                    right -= 1
        return min